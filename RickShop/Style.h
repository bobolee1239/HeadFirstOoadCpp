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
    case A:   os << "A style";
    case F:   os << "F style";
    default:  os << "Unspecified";
    }
    return os;
}

#endif // !STYLE_H