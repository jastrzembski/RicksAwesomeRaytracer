#ifndef RAYTRACER_TRACE_HPP
#define RAYTRACER_TRACE_HPP

#include "vecs.hpp"
#include "Ray.hpp"
#include "RayHit.hpp"
#include "Scene.hpp"

V4 trace_ray(const Ray& ray, const Scene& scene, int depth);

#endif //RAYTRACER_TRACE_HPP
