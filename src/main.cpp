#include <iostream>

#include "Render.hpp"
#include "vecs.hpp"
#include "tiles.hpp"

//Everything startas from the main function
int main(int argc, char** argv) {
    auto tile = Tile(200, 200);
    tile.checker_fill();
    tile.save_as_ppm("1.ppm");
    //auto render = argc > 1 ? Render(argv[0]) : Render();
    return 0;
}