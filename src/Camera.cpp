#include "Camera.hpp"

Ray Camera::get_ray(double horizontally, double vertically) const {
    return Ray(origin,
               (top_left_corner
                + width * horizontally
                + height * vertically
                - origin).unit_vector());
}

Camera::Camera() {
    origin = V3(0, 0, -8);
    top_left_corner = V3(-2, 1, -5);
    height = V3(0, -2, 0);
    width = V3(4, 0, 0);
}
