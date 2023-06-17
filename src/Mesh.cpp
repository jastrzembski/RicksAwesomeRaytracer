#include "Mesh.hpp"

void Mesh::intersect(const Ray &ray, RayHit &ray_hit) const {
    for (auto i : geometry) {
        //if the ray has intersection with given geometry and there was no intersetion before or
        // the distance from the ray's origin to the intersection point is lesser than in the previous intersection
        if (i->intersect(ray, ray_hit)) {
            //writing mesh's material to the ray_hit
        }
    }
}
