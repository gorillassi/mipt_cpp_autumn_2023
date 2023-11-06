#include "isEqual.hpp"
#include <iostream>

int main()
{
    std::string text1{"Ashcraft"};
    std::string text2{"Ashcroft"};
    if(isEqual(text1, text2) ){
        std::cout << "Similar!" << std::endl;
    }
    else{
        std::cout << "Not similar!" << std::endl;
    }
    
    if(convertTextToSound(text1) == std::string{"A261"} ){
        std::cout << "Correct!" << std::endl;
    }
}