#include <iostream>

#include "Render.hpp"


RenderProperties::RenderProperties(int width, int height, int samples_per_pixel) :
        width(width),
        height(height),
        samples_per_pixel(samples_per_pixel) {}

Render::Render(RenderProperties properties) :
    properties(properties),
    result(properties.width, properties.height) {
    std::cout << "Render is initializing." << std::endl;
}

void Render::render() {
    auto glue = V4(0.8, 0.3, 0.9, 0);
    for (auto i = 0; i < result.resolution(); i++)
        result.write_pixel(i, glue);
    result.save_as_ppm("/home/byte/cotusiedzieje.ppm");
}