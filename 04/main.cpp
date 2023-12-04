#include "tparser.hpp";


int main(){
    std::string line = "Hello 123 World a456";
    parse(line, parse_digit, parse_string);
    return 0;
}