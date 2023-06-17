#ifndef RAYTRACER_GEOMETRY_HPP
#define RAYTRACER_GEOMETRY_HPP

#include "Ray.hpp"
#include "RayHit.hpp"

class Geometry {
public:
    virtual bool intersect(const Ray& ray, RayHit& ray_hit) const = 0;
};


#endif //RAYTRACER_GEOMETRY_HPP
