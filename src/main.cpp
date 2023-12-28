#include <iostream>
#include "lib.h"

int main (int, char*) noexcept
{
    std::cout << "Version: " << version() << std::endl;
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
