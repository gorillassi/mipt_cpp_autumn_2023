#include "libstemmer.hpp"
#include <iostream>
#include <string>

int main()
{
    
    std::string world;
    std::cin >> world;
    std::cout << normalize(world) << std::endl;
}