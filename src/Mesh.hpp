#ifndef RAYTRACER_MESH_HPP
#define RAYTRACER_MESH_HPP

#include "Ray.hpp"
#include "RayHit.hpp"

class Mesh {
public:
    void intersect(const Ray& ray, RayHit& ray_hit) const;
};


#endif //RAYTRACER_MESH_HPP
