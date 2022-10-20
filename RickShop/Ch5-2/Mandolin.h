#ifndef MANDOLIN_H
#define MANDOLIN_H

#include <string>
#include "Instrument.h"
#include "InstrumentSpec.h"
#include "MandolinSpec.h"

class Mandolin : public Instrument
{
public:
    Mandolin(
        const std::string  &serialNumber,
        const double        price,
        MandolinSpec       &spec
    ) : Instrument(serialNumber, price), spec(spec)
    {}

    ~Mandolin() {}

    const InstrumentSpec& getSpec() const
    {return static_cast<const InstrumentSpec&>(spec);}

private:
    MandolinSpec spec;
};

#endif // !MANDOLIN_H