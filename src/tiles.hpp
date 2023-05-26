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

    /**
     * @brief Calculates the width [in pixels] of the tile.
     * @return
     */
    int width();

    /**
     * @brief Calculates the height [in pixels] of the tile.
     * @return Height of the tile.
     */
    int height();

    /**
     * @brief Calculates the number of pixels of the tile.
     * @return Number of pixels.
     */
    int resolution();
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
};

#endif //RAYTRACER_TILES_HPP
