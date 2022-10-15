#ifndef WOOD_H
#define WOOD_H

#include <string>
#include <ostream>

enum Wood {
    INDIAN_ROSEWOOD, 
    BRAZILIAN_ROSEWOOD, 
    MAHOGANY, 
    MAPLE,
    COCOBOLO, 
    CEDAR, 
    ADIRONDACK, 
    ALDER, 
    SITKA
};

std::ostream& operator << (std::ostream& os, const Wood& wood)
{
    switch (wood) {
    case INDIAN_ROSEWOOD:    os << "Indian Rosewood";
    case BRAZILIAN_ROSEWOOD: os << "Brazilian Rosewood";
    case MAHOGANY:           os << "Mahogany";
    case MAPLE:              os << "Maple";
    case COCOBOLO:           os << "Cocobolo";
    case CEDAR:              os << "Cedar";
    case ADIRONDACK:         os << "Adirondack";
    case ALDER:              os << "Alder";
    case SITKA:              os << "Sitka";
    default:                 os << "unspecified";
    }
    return os;
}


#endif // !WOOD_H