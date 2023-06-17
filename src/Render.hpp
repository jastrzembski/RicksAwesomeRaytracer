#ifndef RAYTRACER_RENDER_HPP
#define RAYTRACER_RENDER_HPP

#include <string>

#include "tiles.hpp"
#include "trace.hpp"


struct RenderProperties {
/*ideas for future: multi_thread, preview_window, */
    int width, height, samples_per_pixel, bouncing_depth;
    std::string scene_path, output_path;
    RenderProperties(const std::string& scene = "",
                     const std::string& output = "",
                     int width = 1000,
                     int height = 500,
                     int samples_per_pixel = 50,
                     int bouncing_depth = 20);
};

class Render {
private:
    RenderProperties properties;
    Tile result; //TODO result class
    Scene scene;
public:
    Render(const RenderProperties& properties);
    void render();
//    void concurrent_render();
};

#endif //RAYTRACER_RENDER_HPP
