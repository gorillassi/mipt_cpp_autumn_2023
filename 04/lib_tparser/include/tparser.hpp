#include <iostream>
#include <cstring>

using func_ptr = void(*)();
using func_digit_ptr = void(*)(uint64_t);
using func_str_ptr = void(*)(const std::string&);



void parse(const std::string& text, func_digit_ptr digit_callback = nullptr, func_str_ptr string_callback = nullptr);

void parse_string(const std::string& text);

void parse_digit(uint64_t text);