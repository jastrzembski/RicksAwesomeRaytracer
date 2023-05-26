cmake_minimum_required(VERSION 3.0.0)
project(Raytracer VERSION 0.1.0)
#file(GLOB SRCS "src/*.cpp")

add_executable(Raytracer
        src/render.cpp
        src/main.cpp
        src/tiles.cpp)