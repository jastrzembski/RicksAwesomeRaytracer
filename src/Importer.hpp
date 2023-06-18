#ifndef RAYTRACER_IMPORTER_HPP
#define RAYTRACER_IMPORTER_HPP

#include <string>

#include "Scene.hpp"

class Importer {
private:
public:
    bool import(const std::string& path, Scene& scene);
};


#endif //RAYTRACER_IMPORTER_HPP
