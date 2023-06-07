#ifndef RAYTRACER_TILES_HPP
#define RAYTRACER_TILES_HPP

#include <string>

#include "vecs.hpp"

struct Tile;

struct VirtualTile {
    Tile *tile;
    IV2 top_left_corner, bottom_right_corner;
    VirtualTile(const IV2& top_left_corner,
                const IV2& bottom_right_corner);

    VirtualTile(const IV2& top_left_corner,
                const IV2& bottom_right_corner,
                Tile& base_tile);

    /**
     * @brief Calculates the width [in pixels] of the tile.
     * @return
     */
    int width() const;

    /**
     * @brief Calculates the height [in pixels] of the tile.
     * @return Height of the tile.
     */
    int height() const;

    /**
     * @brief Calculates the number of pixels of the tile.
     * @return Number of pixels.
     */
    int resolution() const;

    /**
     * @brief Converts index of pixel in buffer aka successive number to it's coordinates.
     * @return Pixel's coordinates
     */
     IV2 successive_to_coordinates(int successive_number) const{
         return {top_left_corner.x + successive_number % width(), top_left_corner.y + successive_number / width()};
     }

     /**
      * @brief Converts coordinates to pixel successive number which is also the pixel's index in the buffer array.
      * @return Pixels successive number
      */
     int coordinates_to_successive(IV2 coordinates) const {
         return (coordinates.x - top_left_corner.x) + (coordinates.y - top_left_corner.y) * width();
     }

     /**
      * @brief Writes pixel to the base tile buffer.
      */
     virtual void write_pixel(IV2& coordinates, const V4& color) const;

     /**
      * @brief Converts successive number buffer to coordinates and writes
      * the pixel to the base buffer at it.
      */
     virtual void write_pixel(int successive_number, const V4& color) const;
};



struct Tile : VirtualTile {
    V4 *buffer;
    Tile(int width, int height);
    void checker_fill( V4 OO = V4(0.4, 0.4, 0.4, 1),
                       V4 OI = V4(0.2, 0.8, 0.2, 1),
                      int side = 16);
    ~Tile() {
        delete buffer;
    }

    /**
     * @brief Writes the tile as a ppm file to the given location.
     * @param path Location of the output file.
     */
    void save_as_ppm(const std::string& path);

    /**
     * @brief Writes the color at the given pixel's coordinates.
     * */
    void write_pixel(IV2& coordinates, const V4& color) const override;

    /**
     * @brief Writes the color to the buffer at the given index.
     * */
    void write_pixel(int successive_number, const V4& color) const override;
};

#endif //RAYTRACER_TILES_HPP
