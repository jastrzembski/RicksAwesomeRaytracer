#include "backgrounds.hpp"

V4 TransparentBackground::color(const V3& orientation) const{
return V4(0, 0, 0, 0);
}

V4 SolidBackground::color(const V3& orientation) const {
return background_color;
}

SolidBackground::SolidBackground(const V4 &color) : background_color(color) {}
