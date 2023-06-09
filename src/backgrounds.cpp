#include "backgrounds.hpp"

V4 TransparentBackground::color(const V3& orientation) {
return V4(0, 0, 0, 0);
}

V4 SolidBackground::color(const V3& orientation) {
return background_color;
}
