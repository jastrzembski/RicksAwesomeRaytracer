#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP


#include "vecs.hpp"
#include "Ray.hpp"
struct Ray;

/**
 * @brief Used for based on the camera parameters primary rays generation.
 * The class is in it's early version it'll be positionable in future development.
 */
class Camera {
private:
    V3 origin, top_left_corner, height, width;
public:
    Camera();
    Ray get_ray(double horizontally, double vertically) const;
};


#endif //RAYTRACER_CAMERA_HPP
