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
    Inventory() : stock(), guitarStock(), mandolinStock()
    {}

    ~Inventory()
    {
        for (auto& item : guitarStock)
        {
            delete item;
        }
        for (auto& item : mandolinStock)
        {
            delete item;
        }
    }

    int addInstrument(
        const std::string    &serialNumber,
        const double          price,
        InstrumentSpec      &&spec
    ) {
        Instrument* pInstrument;
        if (dynamic_cast<GuitarSpec*>(&spec))
        {
            guitarStock.push_back(
                new Guitar(
                    serialNumber, 
                    price, 
                    dynamic_cast<GuitarSpec&>(spec)
                    ));
            pInstrument = static_cast<Instrument*>(guitarStock.back());
        }
        else if (dynamic_cast<MandolinSpec*>(&spec))
        {
            mandolinStock.push_back(
                new Mandolin(
                    serialNumber,
                    price,
                    dynamic_cast<MandolinSpec&>(spec)
                ));
            pInstrument = static_cast<Instrument*>(mandolinStock.back());
        }
        else
        {return 0;}
        stock.push_back(pInstrument);
        return 1;
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
    
    std::list<const Instrument*> search(const GuitarSpec& target)
    {
        std::list<const Instrument*> matches;
        for (auto& pItem : guitarStock)
        {
            if (pItem->getSpec() == target)
            {
                matches.push_back(static_cast<const Instrument*>(pItem));
            }
        }
        return matches;
    }

    std::list<const Instrument*> search(const MandolinSpec& target)
    {
        std::list<const Instrument*> matches;
        for (auto& pItem : mandolinStock)
        {
            if (pItem->getSpec() == target)
            {
                matches.push_back(static_cast<const Instrument*>(pItem));
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

// private:
    std::list<Instrument*>  stock;
    std::list<Guitar*>      guitarStock;
    std::list<Mandolin*>    mandolinStock;
};


#endif // !INVENTORY_H