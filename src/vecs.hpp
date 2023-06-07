#ifndef RAYTRACER_VECS_HPP
#define RAYTRACER_VECS_HPP

#include <ostream>
#include <cmath>
//TODO: replace vectors' structures with ones inheriting from one flexible structure

struct IV2 {
    int x, y;
    IV2(int x, int y) : x(x), y(y) {}
};

struct V4;
V4 operator/(const V4& a, double b);
V4 operator*(const V4& a, double b);
V4 operator+(const V4& a, const V4& b);
V4 operator-(const V4& a, const V4& b);
std::ostream& operator<<(std::ostream &out, const V4 &v);

struct V4 {
    double x, y, z, w;
    V4() {}
    V4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}
};

struct V3;
V3 operator/(const V3& a, double b);
V3 operator*(const V3& a, double b);
V3 operator+(const V3& a, const V3& b);
V3 operator-(const V3& a, const V3& b);
double dot(const V3& a, const V3& b);
V3 cross(const V3& a, const V3& b);
double distance(const V3& a, const V3& b);
std::ostream& operator<<(std::ostream &out, const V3 &v);

struct V3 {
    double x, y, z;
    V3() {}
    V3(double x, double y, double z) : x(x), y(y), z(z) {}
    double lenght() const;
    V3 unit_vector() const;
};

#endif //RAYTRACER_VECS_HPP