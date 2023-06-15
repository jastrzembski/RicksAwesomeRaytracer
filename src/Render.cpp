#include <iostream>

#include "Render.hpp"
#include "Scene.hpp"

RenderProperties::RenderProperties(const std::string& scene,
                                   const std::string& output,
                                   int width,
                                   int height,
                                   int samples_per_pixel) :
        width(width),
        height(height),
        samples_per_pixel(samples_per_pixel),
        scene_path(scene),
        output_path(output) {}

Render::Render(const RenderProperties& properties) :
    properties(properties),
    result(properties.width, properties.height) {
    std::cout << "Render is starting." << std::endl;
}

void Render::render() {
    auto glue = V4(0.8, 0.3, 0.9, 0);
    auto cam = Camera();
    for (auto i = 0; i < result.width(); i++) {
        auto coords = result.successive_to_coordinates(i);
        std::cout << cam.get_ray((double)(coords.x + 1) / result.width(),
                                 (double)(coords.y + 1) / result.height()).direction << std::endl;
    }

    auto output = properties.output_path.empty()
                        ? "output.ppm"
                        : properties.output_path;
    std::cout << "Writing your render to " << output << std::endl;
    result.save_as_ppm(output);
}