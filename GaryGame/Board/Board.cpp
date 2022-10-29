#include "Board.h"

using std::vector;

int Board::addUnit(const int& unitId, const Coordinate& loc)
{
    if (unitsMap.count(unitId))
    {return 0;}
    unitsMap[unitId] = loc;
    return 1;
}

int Board::mvUnit(const int& unitId, const Coordinate& newLoc)
{
    if (unitsMap.find(unitId) == unitsMap.end())
    {return 0;}
    unitsMap[unitId] = newLoc;
    return 1;
}

int Board::rmUnit(const int& unitId)
{
    if (unitsMap.find(unitId) == unitsMap.end())
    {return 0;}
    unitsMap.erase(unitId);
    return 1;
}
    

vector<int> Board::getUnitsAt(const Coordinate& loc) const
{
    vector<int> units;
    for (auto& [unitId, pos] : unitsMap)
    {
        if (pos == loc)
        {
            units.push_back(unitId);
        }
    }
    return units;
}
