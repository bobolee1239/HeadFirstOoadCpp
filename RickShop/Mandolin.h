#ifndef MANDOLIN_H
#define MANDOLIN_H

#include <string>
#include "Instrument.h"
#include "MandolinSpec.h"

class Mandolin : public Instrument
{
public:
    Mandolin(
        const std::string  &serialNumber,
        const double        price,
        MandolinSpec       &spec
    ) : Instrument(serialNumber, price, static_cast<InstrumentSpec&>(spec)), spec(spec)
    {}

private:
    MandolinSpec spec;
};

#endif // !MANDOLIN_H