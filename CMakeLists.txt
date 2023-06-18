cmake_minimum_required(VERSION 3.1.3)
project(Raytracer VERSION 0.1.0)
#file(GLOB SRCS "src/*.cpp")

add_executable(Raytracer
        src/main.cpp
        src/Render.cpp
        src/Render.hpp
        src/tiles.cpp
        src/tiles.hpp
        src/vecs.cpp
        src/vecs.hpp
        src/backgrounds.cpp
        src/backgrounds.hpp
        src/Scene.cpp
        src/Scene.hpp
        src/Ray.hpp
        src/Ray.cpp
        src/Camera.cpp
        src/Camera.hpp
        src/RayHit.cpp
        src/RayHit.hpp
        src/Mesh.cpp
        src/Mesh.hpp
        src/Geometry.hpp
        src/Sphere.cpp
        src/Sphere.hpp
        src/trace.hpp
        src/trace.cpp
        src/math.hpp
        src/Importer.cpp
        src/Importer.hpp)
target_link_options(Raytracer PRIVATE -ljsoncpp)
