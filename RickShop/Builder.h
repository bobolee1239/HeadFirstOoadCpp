#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>
#include <string>

enum Builder { 
  FENDER, 
  MARTIN, 
  GIBSON, 
  COLLINGS, 
  OLSON, 
  RYAN, 
  PRS, 
  ANY
};

std::ostream& operator << (std::ostream& os, const Builder& builder) 
{
    switch(builder) {
      case FENDER:   os << "Fender";
      case MARTIN:   os << "Martin";
      case GIBSON:   os << "Gibson";
      case COLLINGS: os << "Collings";
      case OLSON:    os << "Olson";
      case RYAN:     os << "Ryan";
      case PRS :     os << "PRS";
      default:       os << "Unspecified";
    }
    return os;
}


#endif // !BUILDER_H