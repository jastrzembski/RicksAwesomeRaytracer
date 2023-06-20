#include "Sphere.hpp"
#include "math.hpp"

bool Sphere::intersect(const Ray &ray, RayHit &ray_hit) const {

        float t_min = 0.001, t_max = 1000;
        V3 oc = (ray.origin - center);
        float a = dot(ray.direction, ray.direction);
        float b = dot(oc, ray.direction);
        float c = dot(oc, oc) - radius*radius;
        float discriminant = b*b - a*c;

        if (discriminant>0) {
                float temp = (-b - sqrt(b*b-a*c))/a;
                if (temp < t_max && temp > t_min && (!ray_hit.hit || temp < ray_hit.distance)) {
                        ray_hit.hit = true;
                        ray_hit.distance = temp;
                        ray_hit.intersection_point = ray.origin + ray.direction * temp;;
                        ray_hit.normal = ((ray_hit.intersection_point - center) / radius).unit_vector();
                        return true;
                }
        }
        return false;

}

Sphere::Sphere(V3 center, double radius) : center(center), radius(radius) {
    std::cout << "Sphere: " << center << " radius " << radius << std::endl;
}
