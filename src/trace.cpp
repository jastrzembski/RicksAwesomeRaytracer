#include "trace.hpp"

V4 trace_ray(const Ray &ray, const Scene &scene, int depth) {
    RayHit ray_hit;
    scene.intersect(ray, ray_hit);
    return ray_hit.hit ? V4(0, 0, 0, 1) : scene.background_color(ray.direction);
}
