#include <iostream>

#include "Render.hpp"
#include "Scene.hpp"
#include "Importer.hpp"

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
    if(properties.scene_path.empty() || properties.scene_path == "solo flag") {
        // generic scene
    } else {
        Importer importer;
        if(importer.import(properties.scene_path, scene))
            std::cout << "Failed to import scene from " << properties.scene_path << std::endl;
        else
            ;// genericc scene
    }
}

void Render::render() {
    auto glue = V4(0.8, 0.3, 0.9, 0);
    for (auto i = 0; i < result.resolution(); i++) {
        std::cout << "\rRendering: " << i+1 << "/" << result.resolution();
        auto coords = result.successive_to_coordinates(i);
        auto primary_ray =  scene.primary_ray((double)(coords.x + 1) / result.width(),
                                 (double)(coords.y + 1) / result.height());
        V4 pixel_color(0, 0, 0, 0);
        for (auto i = 0; i < properties.samples_per_pixel; i++) {
            pixel_color = pixel_color + trace_ray(primary_ray, scene, properties.bouncing_depth);
        }
        pixel_color = pixel_color / properties.samples_per_pixel;
        result.write_pixel(coords, pixel_color);
    }

    auto output = properties.output_path.empty()
                        ? "output.ppm"
                        : properties.output_path;
    std::cout << "Writing your render to " << output << std::endl;
    result.save_as_ppm(output);
}