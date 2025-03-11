// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool containsDigit = false;
    if (str == nullptr || strlen(str) == 0)
    {
        return 0;
    }
    while (*str)
    {
        if (std::isspace(*str))
        {
            if (inWord && !containsDigit)
            {
                count++;
            }
            inWord = false;
            containsDigit = false;
        }
        else
        {
            if (!inWord)
            {
                inWord = true;
            }
            if (std::isdigit(*str))
            {
                containsDigit = true;
            }
        }
        str++;
    }
    if (inWord && !containsDigit)
    {
        count++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool validWord = false;
    if (str == nullptr || strlen(str) == 0) {
        return 0;
    }
    while (*str) {
        if (std::isspace(*str)) {
            if (inWord && validWord) {
                count++;
            }
            inWord = false;
            validWord = false;
        }
        else {
            if (!inWord) {
                inWord = true;
                if (std::isupper(*str) && (*str >= 'A' && *str <= 'Z')) {
                    validWord = true;
                }
                else {
                    validWord = false;
                }
            }
            else {
                if (validWord) {
                    if (std::islower(*str) && (*str >= 'a' && *str <= 'z')) {

                    }
                    else {
                        validWord = false;
                    }
                }
            }
        }
        str++;
    }
    if (inWord && validWord) {
        count++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    return 0;
}
