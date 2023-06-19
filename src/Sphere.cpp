#include "Sphere.hpp"
#include "math.hpp"

bool Sphere::intersect(const Ray &ray, RayHit &ray_hit) const {
    double t0, t1;

    V3 L = ray.origin - center;
    double a = dot(ray.direction, ray.direction);
    double b = 2 * dot(ray.direction, L);
    double c = dot(L, L) - radius;
    if (!solve_quadratic(a, b, c, t0, t1)) return false;

    if (t0 > t1) std::swap(t0, t1);

    if (t0 < 0) {
        t0 = t1;
        if (t0 < 0.000001 || t0 > 10000) return false;
    }

    double distance = t0;

    if (!ray_hit.hit || ray_hit.distance < distance) {
        ray_hit.hit = true;
        ray_hit.distance = distance;
        ray_hit.intersection_point = ray.origin + ray.direction * distance;
        ray_hit.normal = ray_hit.intersection_point - center;
        return true;
    }

    return false;
}
