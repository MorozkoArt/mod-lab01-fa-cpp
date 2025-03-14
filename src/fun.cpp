// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool containsDigit = false;
    while (*str) {
        if (!std::isspace(*str) && !inWord) {
            count++;
            inWord = true;
            containsDigit = false;
        }
        if (std::isdigit(*str) && !containsDigit) {
            count--;
            containsDigit = true;
        }
        if (std::isspace(*str) && inWord) {
            containsDigit = false;
            inWord = false;
        }
        str++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool validWord = false;
    while (*str) {
        if (std::isspace(*str) && inWord) {
            validWord = false;
            inWord = false;
        } else if (!std::islower(*str) && validWord) {
            count--;
            validWord = false;
        } else if (!inWord && std::isupper(*str)) {
            count++;
            inWord = true;
            validWord = true;
        }
        str++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int count = 0;
    unsigned int lenWords = 0;
    bool inWord = false;
    while (*str) {
        if (std::isspace(*str) && inWord) {
            inWord = false;
        } else if (!std::isspace(*str) && !inWord) {
            inWord = true;
            count++;
            lenWords++;
        } else if (!std::isspace(*str) && inWord) {
            lenWords++;
        }
        str++;
    }
    if (count == 0) {
        return 0;
    }
    return (static_cast<unsigned int>
        (std::round(static_cast<double>(lenWords) / count)));
}
