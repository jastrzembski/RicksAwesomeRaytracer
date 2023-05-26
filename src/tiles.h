#ifndef RAYTRACER_TILES_H
#define RAYTRACER_TILES_H

#include <string>

#include "vecs.h"

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
    void checker_fill(const V4 OO, const V4 OI, int side);
    ~Tile() {
        delete buffer;
    }

    /**
     * @brief Writes the tile as a ppm file to the given location.
     * @param path Location of the output file.
     */
    void save_as_ppm(std::string path);
};

#endif //RAYTRACER_TILES_H
