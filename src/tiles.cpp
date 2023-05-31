#include <fstream>
#include <string>

#include "tiles.hpp"

VirtualTile::VirtualTile(const IV2& top_left_corner,
                         const IV2& bottom_right_corner) :
    top_left_corner(top_left_corner),
    bottom_right_corner(bottom_right_corner),
    tile(nullptr) {}

VirtualTile::VirtualTile(const IV2& top_left_corner,
            const IV2& bottom_right_corner,
            Tile& base_tile) :
        top_left_corner(top_left_corner),
        bottom_right_corner(bottom_right_corner),
        tile(&base_tile) {}

int VirtualTile::width() const {
    return bottom_right_corner.x - top_left_corner.x + 1;
}

int VirtualTile::height() const {
    return bottom_right_corner.y - top_left_corner.y + 1;
}

int VirtualTile::resolution() const {
    return width() * height();
}
Tile::Tile(int width, int height) :
    VirtualTile(IV2(0, 0),
                IV2(width-1, height-1)){
    buffer = new V4[width*height];
}

void Tile::save_as_ppm(const std::string& path) {
    std::ofstream file(path, std::ios::out);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to write to file " + path);
    }
    file << "P3 " << std::to_string(width()) << " " << std::to_string(height()) << " 255\n";
    for(auto i = 0; i < resolution(); i++) {
        file << (int)(255.99*buffer[i].x) << ' '
             << (int)(255.99*buffer[i].y) << ' '
             << (int)(255.99*buffer[i].z) << '\n';
    }
    file.close();
}

void Tile::checker_fill(const V4 OO, const V4 OI, int side) {
    for(auto i = 0; i < resolution(); i++) {
        buffer[i] = (i / width() / side % 2) == (i % width() / side % 2) ? OO : OI;
    }
}

void VirtualTile::write_pixel(IV2 &coordinates, V4 &color) const {
    tile->write_pixel(coordinates, color);
}

void VirtualTile::write_pixel(int successive_number, V4& color) const {
    auto coordinates = successive_to_coordinates(successive_number);
    tile->write_pixel(coordinates, color);
}

void Tile::write_pixel(int successive_number, V4& color) const {
    buffer[successive_number] = color;
}
void Tile::write_pixel(IV2& coordinates, V4& color) const {
    write_pixel(coordinates_to_successive(coordinates), color);
}