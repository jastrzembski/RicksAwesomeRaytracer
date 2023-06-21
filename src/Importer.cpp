#include "Importer.hpp"

#include <json/json.h>
#include <fstream>
#include <iostream>

#include "Scene.hpp"
#include "Mesh.hpp"
#include "Geometry.hpp"
#include "vecs.hpp"
#include "Sphere.hpp"
#include "Material.hpp"


bool Importer::import(const std::string &path, Scene &scene, RenderProperties &render_properties) {
    std::cout << "Importing scene from " << path << std::endl;
    std::ifstream file(path);
    if (!file) return false;

    Json::Reader reader;
    Json::Value data;
    if (!reader.parse(file, data)) return true;
    else std::cout << "Json successfully parsed." << std::endl;

    if (render_properties.width == 0) render_properties.width = data["render"]["width"].asInt();
    if (render_properties.height == 0) render_properties.height = data["render"]["height"].asInt();
    if (render_properties.samples_per_pixel == 0) render_properties.samples_per_pixel = data["render"]["sampling"].asInt();
    if (render_properties.bouncing_depth == 0) render_properties.bouncing_depth = data["render"]["depth"].asInt();

    if (data["scene"]["background"]["type"] == "solid") {
        Background* background = new SolidBackground(data["scene"]["background"]["color"].asString());
        scene.set_background(background);
    } else {
        scene.set_background(new SolidBackground(V4(1, 1, 1, 1)));
    }

    for (auto mesh : data["scene"]["meshes"]) {
        Mesh* m = new Mesh();
        for (auto shape : mesh["geometry"]) {
            Geometry* geometry;
            if (shape["type"] == "sphere") {
                geometry = new Sphere(V3(shape["center"].asString()), shape["radius"].asDouble());
            }
            m->add_geometry(geometry);
        }

        Material* mesh_material;
        if (mesh["material"]["type"] == "UFOMat") {
            mesh_material = new UFOMat(mesh["material"]["color"] ? V4(mesh["material"]["color"].asString()) : V4(0.5, 0.6, 0.7, 1),
                                       mesh["material"]["reflected"].asDouble(),
                                       mesh["material"]["matte"].asDouble(),
                                       mesh["material"]["fog"].asDouble());
        } else {
            mesh_material = new UFOMat(V4(0.7, 0.6, 0.3, 1), 1, 1, 0);
        }
        m->set_material(mesh_material);
        scene.add_mesh(m);
    }

    return false;
}
