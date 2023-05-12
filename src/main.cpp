#include <iostream>

#include "lib.h"

int main() {
    auto is_linked = IsLinked();
    if (is_linked.is_linked()) 
        std::cout << "It's flying!" << std::endl;
    return 0;
}