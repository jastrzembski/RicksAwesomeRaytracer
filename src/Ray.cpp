#include "Ray.hpp"

Ray::Ray(const V3 &origin, const V3 &direction) :
origin(origin), direction(direction) {}

Ray::Ray(const V3 &origin, const V3 &direction, const V4 &color) :
    origin(origin),
    direction(direction),
    color(color) {}


