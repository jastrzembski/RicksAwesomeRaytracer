#ifndef RAYTRACER_MESH_HPP
#define RAYTRACER_MESH_HPP

#include <vector>

#include "Ray.hpp"
#include "RayHit.hpp"
#include "Geometry.hpp"

#include "Sphere.hpp"

class Mesh {
    std::vector<Geometry*> geometry;
public:
    Mesh() {}

    void add_geometry(Geometry* geom) {
        geometry.push_back(geom);
    }

    ~Mesh() {
        for (auto i : geometry) {
            delete i;
        }
    }
    void intersect(const Ray& ray, RayHit& ray_hit) const;
};


#endif //RAYTRACER_MESH_HPP
