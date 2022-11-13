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

static inline
void rstrip(std::string& str, const int endPos) 
{
    if (endPos < 0)
    {return;}
    if (str[endPos] != ' ')
    {
        if (endPos < str.size()-1)
        {str.erase(endPos+1);}
        return;
    }
    else
    {return rstrip(str, endPos-1);}
}

static inline
void rstrip(std::string& str) 
{
    rstrip(str, str.size()-1);
}


#endif  // !STRING_UTIL_H
