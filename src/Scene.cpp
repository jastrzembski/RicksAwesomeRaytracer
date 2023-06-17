#include "Scene.hpp"

Ray Scene::primary_ray(double horizontally, double vertically) const {
    return camera.get_ray(horizontally, vertically);
}

V4 Scene::background_color(const V3 &orientation) const {
    return background->color(orientation);
}

void Scene::intersect(const Ray &ray, RayHit &ray_hit) const {
    //Set ray_hit to default no-intersection when there's no meshes to intersect
    if (meshes.empty()) ray_hit = RayHit();
}

Scene::Scene() {
    camera = Camera();
    background = new SolidBackground(V4(1, 0, 0, 1));
}

Scene::~Scene() {
    delete background;
}
