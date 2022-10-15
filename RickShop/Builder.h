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
      case FENDER:   
        os << "Fender";
        break;
      case MARTIN:   
        os << "Martin";
        break;
      case GIBSON:   
        os << "Gibson";
        break;
      case COLLINGS: 
        os << "Collings";
        break;
      case OLSON:    
        os << "Olson";
        break;
      case RYAN:     
        os << "Ryan";
        break;
      case PRS :     
        os << "PRS";
        break;
      default:       
        os << "Unspecified";
    }
    return os;
}


#endif // !BUILDER_H