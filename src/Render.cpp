#include <iostream>

#include "Render.hpp"
#include "Scene.hpp"

RenderProperties::RenderProperties(const std::string& scene,
                                   const std::string& output,
                                   int width,
                                   int height,
                                   int samples_per_pixel,
                                   int bouncing_depth) :
        width(width),
        height(height),
        samples_per_pixel(samples_per_pixel),
        bouncing_depth(bouncing_depth),
        scene_path(scene),
        output_path(output) {}

Render::Render(const RenderProperties& properties) :
    properties(properties),
    result(properties.width, properties.height) {
}

void Render::render() {
    auto glue = V4(0.8, 0.3, 0.9, 0);
    for (auto i = 0; i < result.resolution(); i++) {
        auto coords = result.successive_to_coordinates(i);
        auto primary_ray =  scene.primary_ray((double)(coords.x + 1) / result.width(),
                                 (double)(coords.y + 1) / result.height());
        result.write_pixel(coords, trace_ray(primary_ray, scene, properties.bouncing_depth));
    }

    auto output = properties.output_path.empty()
                        ? "output.ppm"
                        : properties.output_path;
    std::cout << "Writing your render to " << output << std::endl;
    result.save_as_ppm(output);
}