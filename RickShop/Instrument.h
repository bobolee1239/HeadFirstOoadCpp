#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <iostream>
#include <string>
#include "InstrumentSpec.h"

class Instrument {
public:
    Instrument(
        const std::string    &serialNumber, 
        const double          price, 
        InstrumentSpec       &spec
    ) : serialNumber(serialNumber), price(price), spec(spec)
    {}

    virtual ~Instrument() = 0;

    std::string getSerialNumber() const
    {return serialNumber;}
    
    double getPrice() const
    {return price;}

    void setPrice(const double newPrice)
    {price = newPrice;}

    const InstrumentSpec& getSpec() const
    {return spec;}

    friend std::ostream& operator << (std::ostream& os, const Instrument& instrument)
    {
        os << "[Instrument]" << std::endl;
        os << "\t- serial#: " << instrument.serialNumber << std::endl;
        os << "\t- price  : " << instrument.price << std::endl;
        os << "\t- spec   : " << instrument.spec;
        return os;
    }

private:
    std::string     serialNumber;
    double          price;
    InstrumentSpec &spec;
};

Instrument::~Instrument() {}


#endif // !INSTRUMENT_H