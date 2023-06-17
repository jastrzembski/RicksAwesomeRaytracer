#ifndef RAYTRACER_GEOMETRY_HPP
#define RAYTRACER_GEOMETRY_HPP

#include "Ray.hpp"
#include "RayHit.hpp"

class Geometry {
public:
    /**
     * @brief tests given geometry for an intersection with a ray
     * @param ray ray to be tested for intersection
     * @param ray_hit reference to the RayHit object for returning data of the intersection
     * @return true if there's an intersection with the ray and it's its first intersection or the intersection point
     * is closer to the ray origin than the previous one
     */
    virtual bool intersect(const Ray& ray, RayHit& ray_hit) const = 0;
};


#endif //RAYTRACER_GEOMETRY_HPP
