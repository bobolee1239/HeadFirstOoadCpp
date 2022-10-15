#ifndef GUITAR_H
#define GUITAR_H

#include <string>
#include "Instrument.h"
#include "GuitarSpec.h"

class Guitar : public Instrument
{
public:
    Guitar(
        const std::string &serialNumber, 
        const double       price,
        GuitarSpec        &spec
    ) : Instrument(serialNumber, price, static_cast<InstrumentSpec&>(this->spec)), spec(spec)
    {}

private:
    GuitarSpec spec;
};

#endif // !GUITAR_H