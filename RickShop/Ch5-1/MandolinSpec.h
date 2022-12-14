#ifndef MANDOLINSPEC_H
#define MANDOLINSPEC_H

#include "InstrumentSpec.h"
#include "Style.h"

class MandolinSpec : public InstrumentSpec
{
public:
    MandolinSpec(
        const Builder     &builder, 
        const std::string &model, 
        const Type        &type,
        const Style       &style,
        const Wood        &backWood,
        const Wood        &topWood
    ) : InstrumentSpec(builder, model, type, backWood, topWood), style(style)
    {}

    MandolinSpec(const MandolinSpec& other) 
     : InstrumentSpec(static_cast<const InstrumentSpec&>(other)), style(other.style)
    {}

    ~MandolinSpec() {}

    Style getStyle() const
    {return style;}

    bool equal(const MandolinSpec& other) const
    {
        return InstrumentSpec::equal(static_cast<const InstrumentSpec&>(other)) &&
               style == other.style;
    }
    bool equal(const InstrumentSpec& other) const
    {
        const MandolinSpec* pOtherMandolin = dynamic_cast<const MandolinSpec*>(&other);
        if (pOtherMandolin)
        {
            return InstrumentSpec::equal(other) &&
                   style == pOtherMandolin->style;
        } 
        else
        {return false;}
    }

    bool operator == (const MandolinSpec& other) const
    {
        return equal(other);
    }
    bool operator == (const InstrumentSpec& other) const
    {
        return equal(other);
    }

private:
    Style style;
};

#endif // !MANDOLINSPEC_H