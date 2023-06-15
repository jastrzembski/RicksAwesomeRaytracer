#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include "Ray.hpp"
#include "Camera.hpp"

class Scene {
private:
    Camera camera;
public:
    Scene() {
        camera = Camera();
    }
};

#endif //RAYTRACER_SCENE_HPP
