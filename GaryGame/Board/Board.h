#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <unordered_map>
#include "../DataType/Coordinate.h"
#include "./Tile.h"

class Board {
public:
    Board(const int& width, const int& height)
     : width(width), height(height), tiles(width, std::vector<Tile>(height))
    {}

    int getWidth() const 
    {return width;}

    int getHeight() const
    {return height;}

    Terrain requestTerrainAt(const Coordinate& loc) const
    {
        return tiles[loc.x][loc.y].getTerrain();
    }

    int addUnit(const int& unitId, const Coordinate& loc);

    int mvUnit(const int& unitId, const Coordinate& newLoc);

    int rmUnit(const int& unitId);

    std::vector<int> getUnitsAt(const Coordinate& loc) const;

private:
    int height;
    int width;
    std::vector<std::vector<Tile>>      tiles;    
    std::unordered_map<int, Coordinate> unitsMap;
};

#endif // !BOARD_H