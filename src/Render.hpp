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
    void fill_gaps();
};

class Render {
private:
    RenderProperties properties;
    Tile *result;
    Scene scene;
public:
    Render(const RenderProperties &prop);
    void render();
    ~Render();
//    void concurrent_render();
};

#endif //RAYTRACER_RENDER_HPP
