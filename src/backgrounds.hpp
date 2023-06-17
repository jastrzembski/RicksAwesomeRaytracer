#ifndef RAYTRACER_BACKGROUNDS_HPP
#define RAYTRACER_BACKGROUNDS_HPP

#include "vecs.hpp"

/**
 * @brief Abstract base class representing the background color computation for rays
 * that do not intersect any objects.
 */
class Background {
public:
    /**
     * @brief Computes the color for rays that do not intersect any objects.
     * @param orientation Orientation of the ray. Used until the Sky material is introduced.
     * @return Virtual function returning a color of the background.
     */
    virtual V4 color(const V3& orientation) const = 0;
    virtual ~Background() {}
};

/**
 * @brief TransparentBackground background.
 * The rendered image will contain transparent and semi-transparent pixels.
 */
class TransparentBackground : public Background {
public:
    /**
     * @brief Returns transparent color for any orientation.
     * @return RGBA (0, 0, 0, 0)
     */
    V4 color(const V3& orientation) const override;
};

/**
 * @brief SolidBackground color background.
 */
class SolidBackground : public Background {
private:
    V4 background_color;
public:
    SolidBackground(const V4& color);
    /**
     * @brief Returns the solid background color for any orientation.
     * @return SolidBackground background color as an RGBA value.
     */
    V4 color(const V3& orientation) const override;
};

#endif //RAYTRACER_BACKGROUNDS_HPP
