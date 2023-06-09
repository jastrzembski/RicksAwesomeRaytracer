cmake_minimum_required(VERSION 3.0.0)
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
        )