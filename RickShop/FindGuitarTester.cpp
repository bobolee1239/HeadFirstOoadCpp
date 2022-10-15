#include <iostream>
#include <list>
#include <string>

#include "Wood.h"
#include "Type.h"
#include "Style.h"
#include "Builder.h"

#include "Instrument.h"
#include "InstrumentSpec.h"
#include "GuitarSpec.h"
#include "MandolinSpec.h"
#include "Inventory.h"

using namespace std;

void constructInventory(Inventory& inventory);

int main(int argc, char* argv[])
{
    Inventory inventory;
    constructInventory(inventory);
    cout << "[Stock]:" << endl;
    cout << inventory << endl;

    GuitarSpec whatErinLikes(FENDER, "Stratocastor", ELECTRIC, 6, ALDER, ALDER);
    
    list<const Instrument*> matches = inventory.search(static_cast<const InstrumentSpec&>(whatErinLikes));

    const int numFound = matches.size();
    if (numFound)
    {
        cout << "Erin, you might like these guitars:" << endl;
        for (auto& item : matches)
        {
            const InstrumentSpec& spec = item->getSpec();
            cout << "  We have a " << spec.getBuilder() << " " << spec.getModel() << " " << spec.getType();
            cout << " guitar:\n     " << spec.getBackWood() << " back and sides,\n     " << spec.getTopWood();
            cout << " top.\n  You can have it for only $" << item->getPrice() << "!\n  ----" << endl;
        }
    }
    else
    {
        cout << "Sorry, Erin, we have nothing for you." << endl;
    }
    return 0;
}


void constructInventory(Inventory& inventory)
{
    inventory.addInstrument("11277", 3999.95, 
        GuitarSpec(COLLINGS, "CJ", ACOUSTIC, 
            6, INDIAN_ROSEWOOD, SITKA
            ));
    inventory.addInstrument("V95693", 1499.95, 
        GuitarSpec(FENDER, "Stratocastor", ELECTRIC, 
            6, ALDER, ALDER
            ));
    inventory.addInstrument("V9512", 1549.95, 
        GuitarSpec(FENDER, "Stratocastor", ELECTRIC, 
            6, ALDER, ALDER
            ));
    inventory.addInstrument("122784", 5495.95, 
        GuitarSpec(MARTIN, "D-18", ACOUSTIC, 
            6, MAHOGANY, ADIRONDACK
            ));
    inventory.addInstrument("76531", 6295.95, 
        GuitarSpec(MARTIN, "OM-28", ACOUSTIC, 
            6, BRAZILIAN_ROSEWOOD, ADIRONDACK
            ));
    inventory.addInstrument("70108276", 2295.95, 
        GuitarSpec(GIBSON, "Les Paul", ELECTRIC, 
            6, MAHOGANY, MAHOGANY
            ));
    inventory.addInstrument("82765501", 1890.95, 
        GuitarSpec(GIBSON, "SG '61 Reissue", ELECTRIC, 
            6, MAHOGANY, MAHOGANY
            ));
    inventory.addInstrument("77023", 6275.95, 
        GuitarSpec(MARTIN, "D-28", ACOUSTIC, 
            6, BRAZILIAN_ROSEWOOD, ADIRONDACK
            ));
    inventory.addInstrument("1092", 12995.95, 
        GuitarSpec(OLSON, "SJ", ACOUSTIC, 
            12, INDIAN_ROSEWOOD, CEDAR
            ));
    inventory.addInstrument("566-62", 8999.95, 
        GuitarSpec(RYAN, "Cathedral", ACOUSTIC, 
            12, COCOBOLO, CEDAR
            ));
    inventory.addInstrument("6 29584", 2100.95, 
        GuitarSpec(PRS, "Dave Navarro Signature", ELECTRIC, 
            6, MAHOGANY, MAPLE
            ));
}