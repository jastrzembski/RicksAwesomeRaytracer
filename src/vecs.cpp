#include "vecs.hpp"

V4 operator/(const V4& a, double b) {
    return V4(a.x / b, a.y / b, a.z / b, a.w / b);
}

V4 operator*(const V4& a, double b) {
    return V4(a.x * b, a.y * b, a.z * b, a.w * b);
}

V4 operator+(const V4& a, const V4& b) {
    return V4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

V4 operator-(const V4& a, const V4& b) {
    return V4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

std::ostream& operator<<(std::ostream &out, const V4 &v) {
    return out << v.x << ' ' << v.y << ' ' << v.z << ' ' << v.w;
}

V3 operator/(const V3& a, double b) {
    return V3(a.x / b, a.y / b, a.z /b);
}

V3 operator*(const V3& a, double b) {
    return V3(a.x * b, a.y * b, a.z * b);
}

V3 operator+(const V3& a, const V3& b) {
    return V3(a.x + b.x, a.y + b.y, a.z + b.z);
}

V3 operator-(const V3& a, const V3& b) {
    return V3(a.x - b.x, a.y - b.y, a.z - b.z);
}

double distance(const V3& a, const V3& b) {
    auto c = b-a;
    return sqrt(c.x*c.x + c.y*c.y + c.z*c.z);
}

double dot(const V3& a, const V3& b) {
    return a.x * b.x
            + a.y * b.y
            + a.z * b.z;
}

V3 cross(const V3& a, const V3& b) {
    return V3(a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x);
}

std::ostream& operator<<(std::ostream &out, const V3 &v) {
    return out << v.x << ' ' << v.y << ' ' << v.z;
}

V4 operator*(const V4 &a, const V4 &b) {
    return V4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

double V3::lenght() const {
    return sqrt(x*x + y*y + z*z);
}
V3 V3::unit_vector() const {
    return *this / lenght();
}

double V3::squared_lenght() const {
    return x*x + y*y + z*z;
}
