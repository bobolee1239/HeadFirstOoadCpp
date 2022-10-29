#include <iostream>
#include <string>
#include <map> 

#include "DataType/Coordinate.h"
#include "Board/Terrain.h"
#include "Board/Tile.h"
#include "Board/Board.h"
#include "Unit/Unit.h"

#define OSTREAM std::cout
#include "./Utility/Logger/Logger.h"
#include "./Utility/Logger/Stringify.h"

using namespace std;

int genUnitId();

#define I0R1(exp)                   \
    do {                            \
        if (!(exp)) {               \
            LOG_E(__LINE__);        \
            return 1;               \
        }                           \
    } while (0)

int main(int argc, char* argv[])
{
    const int width = 10;
    const int height = 10;

    const int playerId1 = 1;
    const int playerId2 = 2;
    Board board(width, height);
    
    map<int, Unit> units;
    
    const int id_player2_tank = genUnitId();
    units[id_player2_tank] = Unit("Player2's Tank", id_player2_tank);

    const int id_player2_army = genUnitId();
    units[id_player2_army] = Unit("Player2's Army", id_player2_tank);
    
    const int id_player1_artillery = genUnitId();
    units[id_player1_artillery] = Unit("Player1's Artillery", id_player1_artillery);

    I0R1(board.addUnit(id_player2_tank, Coordinate(4, 5)));
    I0R1(board.addUnit(id_player2_army, Coordinate(4, 5)));

    I0R1(board.addUnit(id_player1_artillery, Coordinate(3, 3)));
    I0R1(board.mvUnit(id_player1_artillery, Coordinate(4, 5)));

    LOG_I("Units @ (4, 5)");
    for (auto& unitId : board.getUnitsAt(Coordinate(4, 5)))
    {
        LOG_I(units[unitId]);
    }

    LOG_I("Player1 battles Player2");
    LOG_I("Terrain @ (4, 5):");
    LOG_I(board.requestTerrainAt(Coordinate(4, 5)));

    LOG_I("Player2 wins the battle!");
    LOG_I("Remove units of Player1 @ (4, 5)");
    I0R1(board.rmUnit(id_player1_artillery));
    LOG_I("Units @ (4, 5)");
    for (auto& unitId : board.getUnitsAt(Coordinate(4, 5)))
    {
        LOG_I(units[unitId]);
    }

    const int id_player1_sub = genUnitId();
    units[id_player1_sub] = Unit("Player1's Sub", id_player1_sub);
    I0R1(board.addUnit(id_player1_sub, Coordinate(2, 2)));
    LOG_I("Terrain @ (2, 2):");
    LOG_I(board.requestTerrainAt(Coordinate(2, 2)));

    return 0;
}


int genUnitId()
{
    static int counter = 0;
    return counter++;
}
