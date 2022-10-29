#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <vector>
#include "./Terrain.h"

class Tile {
public:
    Tile()
     : terrain("unspecified")
    {}

    Tile(const Terrain& terrain)
     : terrain(terrain)
    {}

    Terrain getTerrain() const
    {return terrain;}

    void setTerrain(const Terrain& terrain)
    {
        this->terrain = terrain;
    }

    friend std::ostream& operator << (std::ostream& os, const Tile& tile)
    {
        os << "[Tile] {terrain:" << tile.terrain <<  "}";
        return os;
    }
private:
    Terrain terrain;
};

#endif // !TILE_H