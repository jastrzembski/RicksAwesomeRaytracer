#ifndef RAYTRACER_RENDER_HPP
#define RAYTRACER_RENDER_HPP

#include "tiles.hpp"


struct RenderProperties {
    int width, height, samples_per_pixel;
    RenderProperties(int width, int height, int samples_per_pixel);
};

class Render {
private:
    RenderProperties properties;
    Tile result; //TODO result class
public:
    Render(RenderProperties properties);
    void render();
//    void concurrent_render();
};

#endif //RAYTRACER_RENDER_HPP
