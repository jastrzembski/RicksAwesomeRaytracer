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
    Mesh() {
        geometry.push_back(new Sphere(V3(0, 0, 5), 1));
    }
    ~Mesh() {
        for (auto i : geometry) {
            delete i;
        }
    }
    void intersect(const Ray& ray, RayHit& ray_hit) const;
};


#endif //RAYTRACER_MESH_HPP
