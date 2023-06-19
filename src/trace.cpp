#include "trace.hpp"

#include "Material.hpp"

#include <iostream>

V4 trace_ray(const Ray &ray, const Scene &scene, int depth) {
    if(depth == 0)
        return V4(0, 0, 0, 1);
    RayHit ray_hit;
    scene.intersect(ray, ray_hit);

    if (ray_hit.hit) {
        auto scattered = ray_hit.material->scatter(ray_hit.intersection_point,
                                                   ray_hit.normal,
                                                   ray.direction,
                                                   depth-1);
        return scattered.color * trace_ray(scattered, scene, depth-1);
    }
    return scene.background_color(ray.direction);
}
