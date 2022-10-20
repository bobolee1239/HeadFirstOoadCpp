#ifndef STYLE_H
#define STYLE_H

#include <iostream>
#include <string>

enum Style { 
  A, 
  F
};


std::ostream& operator << (std::ostream& os, const Style& style)
{
    switch(style) {
    case A:   os << "A style"; break;
    case F:   os << "F style"; break;
    default:  os << "Unspecified"; break;
    }
    return os;
}

#endif // !STYLE_H