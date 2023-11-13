#include "libstemmer.hpp"
#include <iostream>
#include <string>

bool isalpha(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if ((str[i] < 65) || (str[i] > 122))
        {
           return false;
        }
        
    }
    return true;
}

std::string toupper(const std::string& str)
{
    std::string str_up;
    for (size_t i = 0; i < str.size(); i++)
    {
        str_up += toupper(str[i]);
    }
    return str_up;
}

/*bool isEnding(const std::string& str, const std::string& ending)
{
    if (str.length() > ending.length())
    {
        bool result = str.compare(str.length() - ending.length(), ending.length(), ending);
        return result;
    }
    else
    {
        return false;
    }
    
}*/

std::string stem(const std::string& str)
{
    std::string str1 = "ed";
    std::string str2 = "ing";
    std::string str3 = "s";
    std::string str4 = "ly";

    if (str.length() > 1 and str.substr(str.length() - str1.length()) == str1)
    {
        return str.substr(0, str.length() - str1.length());
    }

    if (str.length() > 1 and str.substr(str.length() - str2.length()) == str2)
    {
        return str.substr(0, str.length() - str2.length());
    }

    if (str.length() > 0 and str.substr(str.length()- str3.length()) == str3)
    {
        return str.substr(0, str.length() - str3.length());
    }

    if (str.length() > 2 and str.substr(str.length() - str4.length()) == str4)
    {
        return str.substr(0, str.length() - str4.length());
    }
    return str;
}

std::string normalize(const std::string& str)
{
    if (isalpha(str))
    {
        
        return toupper(stem(str));
    }
    else
    {
        return "NOT A TOKEN";
    }
}