#ifndef GUITAR_H
#define GUITAR_H

#include <string>
#include "Instrument.h"
#include "InstrumentSpec.h"
#include "GuitarSpec.h"

class Guitar : public Instrument
{
public:
    Guitar(
        const std::string &serialNumber, 
        const double       price,
        GuitarSpec        &spec
    ) : Instrument(serialNumber, price), spec(spec)
    {}

    ~Guitar() {}

    const InstrumentSpec& getSpec() const
    {return static_cast<const InstrumentSpec&>(spec);}

private:
    GuitarSpec spec;
};

#endif // !GUITAR_H