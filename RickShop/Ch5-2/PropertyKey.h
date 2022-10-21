#ifndef PROPERTY_KEY_H
#define PROPERTY_KEY_H

#include <iostream>
#include <string>

enum PropertyKey { 
    INSTRUMENT_TYPE,
    BUILDER,
    TYPE,
    MODEL,
    TOP_WOOD,
    BACK_WOOD,
    NUM_STRING,
    STYLE
};


std::ostream& operator << (std::ostream& os, const PropertyKey& key)
{
    switch(key) {
    case INSTRUMENT_TYPE : os << "InstrumetType"; break;
    case BUILDER         : os << "Buider"; break;
    case TYPE            : os << "Type"; break;
    case MODEL           : os << "Model"; break;
    case TOP_WOOD        : os << "Top Wood"; break;
    case BACK_WOOD       : os << "Back Wood"; break;
    case NUM_STRING      : os << "Num String"; break;
    case STYLE           : os << "Style"; break;
    default              : os << "Unspecified"; break;
    }
    return os;
}


#endif // !INSTRUMENT_PROPERTY_H