#ifndef RAYTRACER_MATH_HPP
#define RAYTRACER_MATH_HPP

#include <cmath>

bool solve_quadratic(const double &a, const double &b, const double &c, double &x0, double &x1)
{
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) return false;
    else if (discriminant == 0) x0 = x1 = - 0.5 * b / a;
    else {
        double q = (b > 0) ?
                   -0.5 * (b + sqrt(discriminant)) :
                   -0.5 * (b - sqrt(discriminant));
        x0 = q / a;
        x1 = c / q;
    }
    if (x0 > x1) std::swap(x0, x1);

    return true;
}

#endif //RAYTRACER_MATH_HPP
