#ifndef RAYTRACER_MESH_HPP
#define RAYTRACER_MESH_HPP

#include <vector>

#include "Ray.hpp"
#include "RayHit.hpp"
#include "Geometry.hpp"
#include "Material.hpp"

class Mesh {
    Material* material;
    std::vector<Geometry*> geometry;
public:
    Mesh();

    void add_geometry(Geometry* geom);
    void set_material(Material* mat);
    ~Mesh();
    void intersect(const Ray& ray, RayHit& ray_hit) const;
};


#endif //RAYTRACER_MESH_HPP
