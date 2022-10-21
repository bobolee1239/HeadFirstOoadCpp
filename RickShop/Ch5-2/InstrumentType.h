#ifndef INSTRUMENT_TYPE_H
#define INSTRUMENT_TYPE_H

#include <iostream>
#include <string>

enum InstrumentType 
{ 
    GUITAR,
    BANJO,
    DOBRO,
    FIDDLE,
    BASS,
    MANDOLIN
};


std::ostream& operator << (std::ostream& os, const InstrumentType& type)
{
    switch(type) {
    case GUITAR  : os << "Guitar"; break;
    case BANJO   : os << "Banjo"; break;
    case DOBRO   : os << "Dobro"; break;
    case FIDDLE  : os << "Fiddle"; break; 
    case BASS    : os << "Bass"; break;
    case MANDOLIN: os << "Mandolin"; break;
    default:       os << "Unspecified"; break;
    }
    return os;
}

#endif // !INSTRUMENT_TYPE_H