#include <iostream>

#include "render.h"
#include "vecs.h"
#include "tiles.h"

//Everything startas from the main function
int main(int argc, char** argv) {
    //auto render = argc > 1 ? Render(argv[0]) : Render();
    auto checker = Tile(1000, 500);
    checker.checker_fill(V4(1, 1, 1, 1),
                         V4(0.95, 0.95, 0.95, 1), 15);
    checker.save_as_ppm("/home/byte/checker.ppm");
    return 0;
}