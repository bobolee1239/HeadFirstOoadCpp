#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

class Coordinate {
public:
    int x;
    int y;

    Coordinate() : x(-1), y(-1)
    {}

    Coordinate(const int &x, const int& y)
     : x(x), y(y)
    {}

    Coordinate(const Coordinate& other)
     : x(other.x), y(other.y)
    {}

    bool operator == (const Coordinate& rhs) const
    {return x == rhs.x && y == rhs.y;}

    friend std::ostream& operator << (std::ostream& os, const Coordinate& coord)
    {
        os << "(" << coord.x << ", " << coord.y << ")";
        return os;
    }

    friend class CoordinateHash;
};

class CoordinateHash {
public:
    size_t operator()(const Coordinate& coord) const
    {
        const int base = 30000;
        return coord.x*base + coord.y;
    }
};

#endif // !COORDINATE_H