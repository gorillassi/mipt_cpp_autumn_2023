#include "isEqual.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

std::string convertTextToSound(std::string text);

bool isEqual(std::string text1, std::string text2)
{
    std::string sound1 = convertTextToSound(text1);
    std::string sound2 = convertTextToSound(text2);
    return sound1 == sound2;
}

std::string convertTextToSound(std::string text)
{
    std::string sound;

    char firstLetter = text[0];
    sound += toupper(firstLetter);

    text.erase(std::remove(text.begin() + 1, text.end(), 'h'), text.end());
    text.erase(std::remove(text.begin() + 1, text.end(), 'w'), text.end());

    for(size_t i = 1; i < text.length(); i++)
    {
        char letter = text[i];
        switch (toupper(letter))
        {
            case 'B':
            case 'F':
            case 'P':
            case 'V':
                sound += '1';
                break;
            case 'C':
            case 'G':
            case 'J':
            case 'K':
            case 'Q':
            case 'S':
            case 'X':
            case 'Z':
                sound += '2';
                break;
            case 'D':
            case 'T':
                sound += '3';
                break;
            case 'L':
                sound += '4';
                break;
            case 'M':
            case 'N':
                sound += '5';
                break;
            case 'R':
                sound += '6';
                break;
            default:
                break;
        }
    }

    std::string reducedSound;
    reducedSound += sound[0];
    for (size_t i = 1; i < sound.length(); i++)
    {
        if (sound[i] != sound[i - 1])
        {
            reducedSound += sound[i];
        }
    }
    sound = reducedSound;

    sound.erase(std::remove(sound.begin() + 1, sound.end(), 'a'), sound.end());
    sound.erase(std::remove(sound.begin() + 1, sound.end(), 'e'), sound.end());
    sound.erase(std::remove(sound.begin() + 1, sound.end(), 'i'), sound.end());
    sound.erase(std::remove(sound.begin() + 1, sound.end(), 'o'), sound.end());
    sound.erase(std::remove(sound.begin() + 1, sound.end(), 'u'), sound.end());
    sound.erase(std::remove(sound.begin() + 1, sound.end(), 'y'), sound.end());
    
    if (sound.length() < 4)
    {
        sound.resize(4, '0');
    }
    else
    {
        sound = sound.substr(0, 4);
    }
    
    return sound;
}