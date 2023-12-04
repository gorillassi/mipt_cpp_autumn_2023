#include "tparser.hpp"

void parse(const std::string& text, func_digit_ptr digit_callback = nullptr, func_str_ptr string_callback = nullptr){
    char* token = std::strtok(const_cast<char*>(text.c_str()), " \t\n");
    while(token != nullptr){
        std::string current_token(token);
        bool is_num = true;

        for(char c: current_token){
            if(!isdigit(c)){
                is_num = false;
                break;
            }
        }

        if(is_num){
            try{
                uint32_t num = std::stoul(current_token);
                digit_callback(num);
            } catch(...){
                string_callback(current_token);
            }
        }else{
            string_callback(current_token);
        }

        token = std::strtok(nullptr, " \t\n");
    }
}

void parse_string(const std::string& text){
    std::cout << "String token: " << text << std::endl;
}

void parse_digit(uint64_t text){
    std::cout << "Digit token: " << text << std::endl;
}