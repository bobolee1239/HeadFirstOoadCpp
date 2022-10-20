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
    case INDIAN_ROSEWOOD:    os << "Indian Rosewood"; break;
    case BRAZILIAN_ROSEWOOD: os << "Brazilian Rosewood"; break;
    case MAHOGANY:           os << "Mahogany"; break;
    case MAPLE:              os << "Maple"; break;
    case COCOBOLO:           os << "Cocobolo"; break;
    case CEDAR:              os << "Cedar"; break;
    case ADIRONDACK:         os << "Adirondack"; break;
    case ALDER:              os << "Alder"; break;
    case SITKA:              os << "Sitka"; break;
    default:                 os << "unspecified";
    }
    return os;
}


#endif // !WOOD_H