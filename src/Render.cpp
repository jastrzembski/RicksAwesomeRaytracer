#include <iostream>

#include "Render.hpp"
#include "Scene.hpp"
#include "Importer.hpp"
#include "Sphere.hpp"

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

void RenderProperties::fill_gaps() {
    width = width == 0 ? 1000 : width;
    height = height == 0 ? 500 : height;
    samples_per_pixel = samples_per_pixel == 0 ? 1 : samples_per_pixel;
    bouncing_depth = bouncing_depth == 0 ? 20 : bouncing_depth;
}

Render::Render(const RenderProperties &prop) : properties(prop) {
    Importer importer;
    if(properties.scene_path.empty() || properties.scene_path == "solo flag") {
        // generic scene
    } else if(properties.scene_path == "manual") {
        std::cout << "Your own spheres are: " << std::endl;
        for (std::string another_sphere; another_sphere != "n"; std::cin >> another_sphere) {
            std::cout << "Center x, y and z: ";
            V3 center;
            std::cin >> center.x >> center.y >> center.z;

            std::cout << "Enter radius: ";
            double radius;
            std::cin >> radius;

            std::cout << "Color <0, 1> RGBA: " << std::endl;
            V4 color;
            std::cin >> color.x >> color.y >> color.z >> color.w;

            std::cout << "Matte: " << std::endl;
            double matte;
            std::cin >> matte;

            Mesh *mesh = new Mesh();
            mesh->add_geometry(new Sphere(center, radius));
            mesh->set_material(new UFOMat(color, 0.5, matte, 0.5));
            scene.add_mesh(mesh);

            std::cout << "Do you maybe want to add another sphere [n for no, anything else for yes]: " << std::endl;
        }
        scene.set_background(new SolidBackground(V4(0.75, 0.75, 0.75, 1)));
    } else if (!importer.import(properties.scene_path, scene, properties)) {
            std::cout << "Scene imported from " << properties.scene_path << std::endl;

    } else {
        std::cout << "Failed to import from" << properties.scene_path << std::endl;
        //generic scene
    }
    properties.fill_gaps();

    result = new Tile(properties.width, properties.height);
}

void Render::render() {
    for (auto i = 0; i < result->resolution(); i++) {
        std::cout << "\rRendering: " << (int)((double)(i+1) / result->resolution() * 100) << "%";
        auto coords = result->successive_to_coordinates(i);
        auto primary_ray =  scene.primary_ray((double)(coords.x + 1) / result->width(),
                                 (double)(coords.y + 1) / result->height());
        V4 pixel_color(0, 0, 0, 0);
        for (auto i = 0; i < properties.samples_per_pixel; i++) {
            pixel_color = pixel_color + trace_ray(primary_ray, scene, properties.bouncing_depth);
        }
        pixel_color = pixel_color / properties.samples_per_pixel;
        result->write_pixel(coords, pixel_color);
    }
    std::cout << std::endl;

    auto output = properties.output_path.empty()
                        ? "output.ppm"
                        : properties.output_path;
    std::cout << "Writing your render to " << output << std::endl;
    result->save_as_ppm(output);
}

Render::~Render() {
    delete result;
}
