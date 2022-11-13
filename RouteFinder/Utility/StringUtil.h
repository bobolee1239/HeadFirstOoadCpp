#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <string>
#include <algorithm>

static inline 
void toLowercase(std::string& str)
{
    std::for_each(
        str.begin(), 
        str.end(), 
        [](char& c){ 
            c = std::tolower(c);
            });
}

#endif  // !STRING_UTIL_H
