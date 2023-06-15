#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP


#include "vecs.hpp"
#include "Ray.hpp"

/**
 * @brief Used for based on the camera parameters primary rays generation.
 * The class is in it's early version it'll be positionable in future development.
 */
class Camera {
private:
    V3 origin, top_left_corner, height, width;
public:
    Camera() {
        origin = V3(0, 0, -1);
        top_left_corner = V3(-2, 1, 0);
        height = V3(0, -2, 0);
        width = V3(4, 0, 0);
    }
    Ray get_ray(double horizontally, double vertically) {
        return Ray(origin,
                   (top_left_corner
                   + width * horizontally
                   + height * vertically
                   - origin).unit_vector());
    }
};


#endif //RAYTRACER_CAMERA_HPP
