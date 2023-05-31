#include <iostream>

#include "Render.hpp"
#include "vecs.hpp"
#include "tiles.hpp"

//Everything startas from the main function
int main(int argc, char** argv) {
    auto tile = Tile(200, 200);
    auto tile_v = VirtualTile(IV2(0, 0), IV2(50, 50), tile);
    tile.checker_fill();
    auto red_eye_loc = IV2(5, 5);
    auto red_eye = V4(1, 0, 0, 0);
    tile_v.write_pixel(red_eye_loc, red_eye);
    tile.save_as_ppm("checker.ppm");

    auto render = Render(RenderProperties(1000, 500, 50));
    render.render();
    return 0;
}