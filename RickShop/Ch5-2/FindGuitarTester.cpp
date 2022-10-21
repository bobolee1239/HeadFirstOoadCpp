#include <iostream>
#include <list>
#include <string>

#include "Wood.h"
#include "Type.h"
#include "Style.h"
#include "Builder.h"
#include "InstrumentType.h"

#include "Instrument.h"
#include "InstrumentSpec.h"
#include "Inventory.h"

using namespace std;

#define SET_GUITAR_PROPERTIES(prop, builder, model, type, topWood, backWood, numString) \
    do {                                                                                \
        prop.insert(make_pair(INSTRUMENT_TYPE, new Property<InstrumentType>(GUITAR)));  \
        prop.insert(make_pair(BUILDER        , new Property<Builder>(builder)));        \
        prop.insert(make_pair(MODEL          , new Property<string>(model)));           \
        prop.insert(make_pair(TYPE           , new Property<Type>(type)));              \
        prop.insert(make_pair(TOP_WOOD       , new Property<Wood>(topWood)));           \
        prop.insert(make_pair(BACK_WOOD      , new Property<Wood>(backWood)));          \
        prop.insert(make_pair(NUM_STRING     , new Property<int>(numString)));          \
    } while (0)

#define SET_MANDOLIN_PROPERTIES(prop, builder, model, type, topWood, backWood, style)   \
    do {                                                                                \
        prop.insert(make_pair(INSTRUMENT_TYPE, new Property<InstrumentType>(GUITAR)));  \
        prop.insert(make_pair(BUILDER        , new Property<Builder>(builder)));        \
        prop.insert(make_pair(MODEL          , new Property<string>(model)));           \
        prop.insert(make_pair(TYPE           , new Property<Type>(type)));              \
        prop.insert(make_pair(TOP_WOOD       , new Property<Wood>(topWood)));           \
        prop.insert(make_pair(BACK_WOOD      , new Property<Wood>(backWood)));          \
        prop.insert(make_pair(STYLE          , new Property<Style>(style)));            \
    } while (0)


void constructInventory(Inventory& inventory);

int main(int argc, char* argv[])
{
    Inventory inventory;
    constructInventory(inventory);
    cout << "[Stock]:" << endl;
    cout << inventory << endl;

    map<PropertyKey, PropertyValue*> prop;
    SET_GUITAR_PROPERTIES(prop, FENDER, "Stratocastor", ELECTRIC, ALDER, ALDER, 6);
    InstrumentSpec whatErinLikes(prop);
    
    list<const Instrument*> matches = inventory.search(whatErinLikes);

    const int numFound = matches.size();
    if (numFound)
    {
        cout << "Erin, you might like these guitars:" << endl;
        for (auto& item : matches)
        {
            const InstrumentSpec& spec = item->getSpec();
            cout << " You can have it for only $" << item->getPrice() << ":" << endl;
            cout << "\t" << spec << endl;
            cout << "-----" << endl;
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
    map<PropertyKey, PropertyValue*> prop;

    prop.clear();
    SET_GUITAR_PROPERTIES(prop, COLLINGS, "CJ", ACOUSTIC, INDIAN_ROSEWOOD, SITKA, 6);
    inventory.addInstrument("11277", 3999.95, prop);

    prop.clear();
    SET_GUITAR_PROPERTIES(prop, FENDER, "Stratocastor", ELECTRIC, ALDER, ALDER, 6);
    inventory.addInstrument("V95693", 1499.95, prop);
    
    prop.clear();
    SET_MANDOLIN_PROPERTIES(prop, FENDER, "Stratocastor", ELECTRIC, ALDER, ALDER, A);
    inventory.addInstrument("Brian5", 1006.802, prop);
    
    prop.clear();
    SET_GUITAR_PROPERTIES(prop, FENDER, "Stratocastor", ELECTRIC, ALDER, ALDER, 6);
    inventory.addInstrument("V9512", 1549.95, prop);
    
    prop.clear();
    SET_GUITAR_PROPERTIES(prop, MARTIN, "D-18", ACOUSTIC, MAHOGANY, ADIRONDACK, 6);
    inventory.addInstrument("122784", 5495.95, prop);
    
    prop.clear();
    SET_GUITAR_PROPERTIES(prop, MARTIN, "OM-28", ACOUSTIC, BRAZILIAN_ROSEWOOD, ADIRONDACK, 6);
    inventory.addInstrument("76531", 6295.95, prop);
    
    prop.clear();
    SET_GUITAR_PROPERTIES(prop, GIBSON, "Les Paul", ELECTRIC, MAHOGANY, MAHOGANY, 6);
    inventory.addInstrument("70108276", 2295.95, prop);

    prop.clear();
    SET_GUITAR_PROPERTIES(prop, GIBSON, "SG '61 Reissue", ELECTRIC, MAHOGANY, MAHOGANY, 6);
    inventory.addInstrument("82765501", 1890.95, prop);

    prop.clear();
    SET_GUITAR_PROPERTIES(prop, MARTIN, "D-28", ACOUSTIC, BRAZILIAN_ROSEWOOD, ADIRONDACK, 6);
    inventory.addInstrument("77023", 6275.95, prop);
    
    prop.clear();
    SET_GUITAR_PROPERTIES(prop, OLSON, "SJ", ACOUSTIC, INDIAN_ROSEWOOD, CEDAR, 12);
    inventory.addInstrument("1092", 12995.95, prop);

    prop.clear();
    SET_GUITAR_PROPERTIES(prop, RYAN, "Cathedral", ACOUSTIC, COCOBOLO, CEDAR, 12);
    inventory.addInstrument("566-62", 8999.95, prop);
    
    prop.clear();
    SET_GUITAR_PROPERTIES(prop, PRS, "Dave Navarro Signature", ELECTRIC, MAHOGANY, MAPLE, 6);
    inventory.addInstrument("6 29584", 2100.95, prop);
}