#ifndef RAYTRACER_RAY_HPP
#define RAYTRACER_RAY_HPP

#include "vecs.hpp"

struct Ray {
    V3 origin, direction;
    Ray(const V3& origin, const V3& direction) :
        origin(origin), direction(direction) {}
};

#endif //RAYTRACER_RAY_HPP
