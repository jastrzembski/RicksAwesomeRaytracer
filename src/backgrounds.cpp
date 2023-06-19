#include "backgrounds.hpp"

V4 TransparentBackground::color(const V3& orientation) const{
return V4(0, 0, 0, 0);
}

V4 SolidBackground::color(const V3& orientation) const {
    //temporary
    auto orien = (orientation.y + 1) /2;
    return background_color * orien + V4(1, 1, 1, 1) * (1-orien);
}

SolidBackground::SolidBackground(const V4 &color) : background_color(color) {}
