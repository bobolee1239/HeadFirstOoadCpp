#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <list>

#include "Instrument.h"
#include "InstrumentSpec.h"

#include "Guitar.h"
#include "GuitarSpec.h"
#include "Mandolin.h"
#include "MandolinSpec.h"

class Inventory 
{
public:
    Inventory() : stock()
    {}

    ~Inventory()
    {
        for (auto& item : stock)
        {
            delete item;
        }
    }

    int addInstrument(
        const std::string    &serialNumber,
        const double          price,
        InstrumentSpec      &&spec
    ) {
        int ret = 1;
        if (dynamic_cast<GuitarSpec*>(&spec))
        {
            stock.push_back(static_cast<Instrument*>(
                new Guitar(
                    serialNumber, 
                    price, 
                    dynamic_cast<GuitarSpec&>(spec)
                    )));
        }
        else if (dynamic_cast<MandolinSpec*>(&spec))
        {
            stock.push_back(static_cast<Instrument*>(
                new Mandolin(
                    serialNumber,
                    price,
                    dynamic_cast<MandolinSpec&>(spec)
                )));
        }
        else
        {ret = 0;}
        return ret;
    }

    const Instrument* get(const std::string& serialNumber) 
    {
        for (auto& pItem : stock)
        {
            if (pItem->getSerialNumber() == serialNumber)
            {return pItem;}
        }
        return NULL;
    }
    
    std::list<const Instrument*> search(const InstrumentSpec& target)
    {
        std::list<const Instrument*> matches;
        for (auto& pItem : stock)
        {
            if (pItem->getSpec() == target)
            {
                matches.push_back(pItem);
            }
        }
        return matches;
    }

    friend std::ostream& operator << (std::ostream& os, const Inventory& inventory)
    {
        for (auto& item : inventory.stock)
        {
            os << *item << std::endl;
        }
        return os;
    }

private:
    std::list<Instrument*>  stock;
};


#endif // !INVENTORY_H