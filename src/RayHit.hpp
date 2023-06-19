#ifndef RAYTRACER_RAYHIT_HPP
#define RAYTRACER_RAYHIT_HPP

#include "vecs.hpp"
#include "Material.hpp"

struct RayHit {
    bool hit;
    double distance;
    V3 intersection_point, normal;
    Material* material;
    RayHit();
    RayHit(double distance);
};

#endif //RAYTRACER_RAYHIT_HPP
