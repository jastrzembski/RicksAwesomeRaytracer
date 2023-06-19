#include "Material.hpp"

#include <cstdlib>
#include <ctime>

#include "trace.hpp"


UFOMat::UFOMat(V4 surface_color, double reflected, double matte, double fog) :
        surface_color(surface_color),
        fog_color(V4(1, 1, 1, 1)),
        reflected(reflected),
        matte(matte),
        fog(fog) {}

Ray UFOMat::scatter(const V3 &intersection_point, const V3 &normal, const V3 &incident_direction, int depth) const {
    auto reflected = (incident_direction - normal * 2 * dot(incident_direction, normal)).unit_vector();
    auto diffused = (normal + random_in_unit_sphere()).unit_vector();
    return Ray(intersection_point, reflected, surface_color);
}

V3 UFOMat::random_in_unit_sphere() const {
    srand(time(nullptr));
    V3 p;
    do {
        p = V3(drand48(), drand48(), drand48()) * 2 - V3(1, 1, 1);
    } while (p.squared_lenght() >= 1);
    return p.unit_vector();
}
