#include "Importer.hpp"

#include <json/json.h>
#include <fstream>
#include <iostream>

#include "Scene.hpp"
#include "Mesh.hpp"
#include "Geometry.hpp"
#include "vecs.hpp"
#include "Sphere.hpp"


bool Importer::import(const std::string &path, Scene &scene) {
    std::cout << "Importing scene from " << path << std::endl;
    std::ifstream file(path);
    if (!file) return false;

    Json::Reader reader;
    Json::Value data;
    if (!reader.parse(file, data)) return true;
    else std::cout << "Json successfully parsed." << std::endl;

    for (auto mesh : data["scene"]["meshes"]) {
        Mesh* m = new Mesh();
        for (auto shape : mesh["geometry"]) {
            Geometry* geometry;
            if (shape["type"] == "sphere") {
                geometry = new Sphere(V3(shape["center"].asString()), shape["radius"].asDouble());
            }
            m->add_geometry(geometry);
        }
        scene.add_mesh(m);
    }

    return false;
}
