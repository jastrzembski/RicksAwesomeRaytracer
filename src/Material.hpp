#ifndef RAYTRACER_MATERIAL_HPP
#define RAYTRACER_MATERIAL_HPP

#include "vecs.hpp"
#include "Ray.hpp"

class Material {
private:
public:
    virtual Ray scatter(const V3& intersection_point, const V3& normal,
                const V3& incident_direction, int depth) const = 0;
    virtual ~Material() = default;
};

class UFOMat : public Material {
private:
    V4 surface_color, fog_color;
    double reflected, matte, fog;
    V3 random_in_unit_sphere() const;
public:
    UFOMat(V4 surface_color, double reflected, double matte, double fog);
    ~UFOMat() override = default;
    Ray scatter(const V3& intersection_point, const V3& normal,
             const V3& incident_direction, int depth) const override;
};


#endif //RAYTRACER_MATERIAL_HPP
