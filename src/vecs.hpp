#ifndef RAYTRACER_VECS_HPP
#define RAYTRACER_VECS_HPP

#include <ostream>
//TODO: replace vectors' structures with ones inheriting from one flexible structure

struct IV2 {
    int x, y;
    IV2(int x, int y) : x(x), y(y) {}
};

struct V4 {
    double x, y, z, w;
    V4() {}
    V4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}
};
/*template <typename T, size_t D>
struct Vector {
    T data[D];

};*/

/*
struct IV2 : Vector<int, 2> {
    int& x = data[0];
    int& y = data[1];
    IV2(int x, int y) {
        data[0] = x;
        data[1] = y;
    }
    friend std::ostream& operator<<(std::ostream& os, const IV2& v) {
        os << "[" << v.data[0] << ", " << v.data[1] << "]";
        return os;
    }
};*/

/*struct V4 : Vector<double, 4> {
    double& x = data[0];
    double& y = data[1];
    double& z = data[2];
    double& w = data[3];
    V4() {}
    V4(double x, double y, double z, double w) {
        data[0] = x;
        data[1] = y;
        data[2] = z;
        data[3] = w;
    }
    V4& operator=(const V4& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
};*/

#endif //RAYTRACER_VECS_HPP