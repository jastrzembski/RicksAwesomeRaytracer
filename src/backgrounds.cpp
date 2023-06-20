#include "backgrounds.hpp"

V4 TransparentBackground::color(const V3& orientation) const{
return V4(0, 0, 0, 0);
}

V4 SolidBackground::color(const V3& orientation) const {
    //auto orien = (orientation.y + 1) /2;
    //background_color * orien + V4(1, 1, 1, 1) * (1-orien)
    return background_color;
}

SolidBackground::SolidBackground(const V4 &color) : background_color(color) {}
