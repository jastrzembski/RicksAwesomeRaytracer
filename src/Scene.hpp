#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include <vector>

#include "Ray.hpp"
#include "RayHit.hpp"
#include "Camera.hpp"
#include "backgrounds.hpp"
#include "Mesh.hpp"


class Scene {
private:
    Camera camera;
    Background *background;
    std::vector<Mesh*> meshes;
public:
    Scene();
    ~Scene();
    void add_mesh(Mesh* mesh);
    void set_background(Background* bckg);
    Ray primary_ray(double horizontally, double vertically) const;
    V4 background_color(const V3& orientation) const;
    void intersect(const Ray& ray, RayHit& ray_hit) const;
};

#endif //RAYTRACER_SCENE_HPP
