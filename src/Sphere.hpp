#ifndef RAYTRACER_SPHERE_HPP
#define RAYTRACER_SPHERE_HPP

#include <cmath>

#include "Ray.hpp"
#include "RayHit.hpp"
#include "Geometry.hpp"

class Sphere : public Geometry {
private:
    V3 center;
    double radius;
public:
    Sphere(V3 center, double radius);
    bool intersect(const Ray& ray, RayHit& ray_hit) const override;
};


#endif //RAYTRACER_SPHERE_HPP
