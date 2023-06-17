//
// Created by byte on 6/5/23.
//

#ifndef RAYTRACER_RAYHIT_HPP
#define RAYTRACER_RAYHIT_HPP

#include "vecs.hpp"

struct RayHit {
    bool hit;
    double distance;
    RayHit() : hit(false) {}
    RayHit(double distance) : distance(distance) {}
};

#endif //RAYTRACER_RAYHIT_HPP
