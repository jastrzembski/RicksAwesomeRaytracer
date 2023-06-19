#ifndef RAYTRACER_RAY_HPP
#define RAYTRACER_RAY_HPP

#include "vecs.hpp"

struct Ray {
    V3 origin, direction;
    V4 color;
    Ray(const V3& origin, const V3& direction);
    Ray(const V3& origin, const V3& direction, const V4& color);
};

#endif //RAYTRACER_RAY_HPP
