#ifndef TYPE_H
#define TYPE_H

#include <iostream>
#include <string>

enum Type { 
    ACOUSTIC, 
    ELECTRIC
};


std::ostream& operator << (std::ostream& os, const Type& type)
{
    switch(type) {
    case ACOUSTIC: os << "acoustic"; break;
    case ELECTRIC: os << "electric"; break;
    default:       os << "unspecified"; break;
    }
    return os;
}

#endif // !TYPE_H