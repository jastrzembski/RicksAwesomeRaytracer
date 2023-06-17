#ifndef RAYTRACER_RAY_HPP
#define RAYTRACER_RAY_HPP

#include "vecs.hpp"
#include "RayHit.hpp"

struct Ray {
    V3 origin, direction;

    Ray(const V3& origin, const V3& direction);
};

#endif //RAYTRACER_RAY_HPP
