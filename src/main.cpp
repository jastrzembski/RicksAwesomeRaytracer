#include <iostream>
#include <map>
#include <vector>

#include "Render.hpp"
#include "vecs.hpp"
#include "tiles.hpp"

std::map<std::string, std::string> extract_flags(std::vector<std::string> args);

//Everything startas from the main function
int main(int argc, char** argv) {
    std::vector<std::string> arguments(argv + 1, argv + argc);
    auto flags = extract_flags(arguments);
    if (flags["help"] == "solo flag") std::cout << "Can't help now" << std::endl; //TODO help

    auto properties = RenderProperties(flags["scene"],
                                       flags["output"],
                                       1000,
                                       500,
                                       50);
    auto render = Render(properties);
    render.render();
    auto a = V3(5, 1, 1);
    std::cout << a.unit_vector() << std::endl;
    return 0;
}

/**
 * @brief The function to write arguments to map data structure
 * @param args vector of arguments
 * @return map structure containing flags
*/
std::map<std::string, std::string> extract_flags(std::vector<std::string> args) {
    std::map<std::string, std::string> flags;
    for (auto arg = args.begin(); arg < args.end(); arg++) {
        if ((*arg)[0] == '-') {
            flags[(*arg).substr(1)] =
                    ((arg == args.end() - 1) || (*(arg+1))[0] == '-')
                    ? "solo flag"
                    : *(arg+1);
        }
    }
    return flags;
}