#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>

#include "Instrument.h"
#include "InstrumentSpec.h"

#include "Guitar.h"
#include "GuitarSpec.h"
#include "Mandolin.h"
#include "MandolinSpec.h"

class Inventory 
{
public:
    Inventory() : stock(), guitarStock()
    {}

    int addInstrument(
        const std::string    &serialNumber,
        const double          price,
        InstrumentSpec      &&spec
    ) {
        Instrument* pInstrument;
        if (dynamic_cast<GuitarSpec*>(&spec))
        {
            guitarStock.push_back(
                Guitar(
                    serialNumber, 
                    price, 
                    dynamic_cast<GuitarSpec&>(spec)
                    ));
            pInstrument = static_cast<Instrument*>(&guitarStock.back());
        }
        else if (dynamic_cast<MandolinSpec*>(&spec))
        {
            mandolinStock.push_back(
                Mandolin(
                    serialNumber,
                    price,
                    dynamic_cast<MandolinSpec&>(spec)
                ));
            pInstrument = static_cast<Instrument*>(&mandolinStock.back());
        }
        else
        {return 0;}
        stock.push_back(pInstrument);
        return 1;
    }

    const Instrument* get(const std::string& serialNumber) 
    {
        for (int n=0; n<stock.size(); ++n)
        {
            if (stock[n]->getSerialNumber() == serialNumber)
            {return stock[n];}
        }
        return NULL;
    }
    
    std::vector<const Instrument*> search(const GuitarSpec& target)
    {
        std::vector<const Instrument*> matches;
        for (int n=0; n<guitarStock.size(); ++n)
        {
            std::cout << __func__ << ": " << n << std::endl;
            if (target == guitarStock[n].getSpec())
            {
                matches.push_back(static_cast<const Instrument*>(&guitarStock[n]));
            }
        }
        return matches;
    }

    std::vector<const Instrument*> search(const MandolinSpec& target)
    {
        std::vector<const Instrument*> matches;
        for (int n=0; n<mandolinStock.size(); ++n)
        {
            if (mandolinStock[n].getSpec() == target)
            {
                matches.push_back(static_cast<const Instrument*>(&mandolinStock[n]));
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
    std::vector<Instrument*> stock;
    std::vector<Guitar>      guitarStock;
    std::vector<Mandolin>    mandolinStock;
};


#endif // !INVENTORY_H