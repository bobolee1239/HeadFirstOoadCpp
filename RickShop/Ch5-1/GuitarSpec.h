#ifndef GUITAR_SPEC_H
#define GUITAR_SPEC_H

#include <string>
#include "Wood.h"
#include "Type.h"
#include "Builder.h"
#include "InstrumentSpec.h"

class GuitarSpec : public InstrumentSpec 
{
public:
    GuitarSpec(
        const Builder     &builder, 
        const std::string &model, 
        const Type        &type,
        const int          numStrings,
        const Wood        &backWood,
        const Wood        &topWood
    ) : InstrumentSpec(builder, model, type, backWood, topWood), numStrings(numStrings)
    {}

    GuitarSpec(const GuitarSpec& other) 
     : InstrumentSpec(static_cast<const InstrumentSpec&>(other)), numStrings(other.numStrings)
    {}

    ~GuitarSpec() {}

    int getNumStrings() const
    {return numStrings;}

    bool equal(const GuitarSpec& other) const 
    {
        return InstrumentSpec::equal(static_cast<const InstrumentSpec&>(other)) &&
               numStrings == other.numStrings;
    }
    bool equal(const InstrumentSpec& other) const
    {
        const GuitarSpec* pOtherGuitar = dynamic_cast<const GuitarSpec*>(&other);
        if (pOtherGuitar)
        {
            return InstrumentSpec::equal(other) &&
                   numStrings == pOtherGuitar->numStrings;
        }
        else
        {return false;}
    }

    bool operator == (const GuitarSpec& other) const
    {
        return equal(other);
    }
    bool operator == (const InstrumentSpec& other) const
    {
        return equal(other);
    }

private:
    int numStrings;
};


#endif // !GUITAR_SPEC_H