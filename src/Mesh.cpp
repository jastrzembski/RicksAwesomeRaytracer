#include "Mesh.hpp"

void Mesh::intersect(const Ray &ray, RayHit &ray_hit) const {
    for (auto i : geometry) {
        //if the ray has intersection with given geometry and there was no intersetion before or
        // the distance from the ray's origin to the intersection point is lesser than in the previous intersection
        if (i->intersect(ray, ray_hit)) {
            ray_hit.material = material;
        }
    }
}

Mesh::Mesh() {
    material = new UFOMat(V4(0.9, 0.9, 0.9, 1), 0.5, 0.5, 0.5);
}

void Mesh::add_geometry(Geometry *geom) {
    geometry.push_back(geom);
}

void Mesh::set_material(Material *mat) {
    material = mat;
}

Mesh::~Mesh() {
    for (auto i : geometry) {
        delete i;
    }
    delete material;
}
