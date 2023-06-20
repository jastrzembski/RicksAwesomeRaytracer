#include "Scene.hpp"

Ray Scene::primary_ray(double horizontally, double vertically) const {
    return camera.get_ray(horizontally, vertically);
}

V4 Scene::background_color(const V3 &orientation) const {
    return background->color(orientation);
}

void Scene::intersect(const Ray &ray, RayHit &ray_hit) const {
    //Set ray_hit to default no-intersection
    ray_hit = RayHit();

    //return when there's no meshes to intersect
    if (meshes.empty()) return;

    for (auto mesh : meshes) {
        mesh->intersect(ray, ray_hit);
    }
}

Scene::Scene() {
    camera = Camera();
    meshes.push_back(new Mesh());
}

Scene::~Scene() {
    delete background;
    for (auto mesh : meshes) delete mesh;
}

void Scene::add_mesh(Mesh *mesh) {
    meshes.push_back(mesh);
}

void Scene::set_background(Background *bckg) {
    background = bckg;
}
