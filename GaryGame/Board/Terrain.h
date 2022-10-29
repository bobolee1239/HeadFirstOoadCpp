#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <string>

class Terrain {
public:
    Terrain(const std::string& name)
     : name(name)
    {}

    Terrain(const Terrain& other)
     : name(other.name)
    {}

    friend std::ostream& operator << (std::ostream& os, const Terrain& terrain)
    {
        os << "[Terrain] {name:" << terrain.name << "}";
        return os;
    }

private:
    std::string name;
};

#endif // !TERRAIN_H