#ifndef RAYTRACER_RAYHIT_HPP
#define RAYTRACER_RAYHIT_HPP

#include "vecs.hpp"

struct RayHit {
    bool hit;
    double distance;
    V3 intersection_point, normal;
    RayHit() : hit(false) {}
    RayHit(double distance) : distance(distance) {}
};

#endif //RAYTRACER_RAYHIT_HPP
