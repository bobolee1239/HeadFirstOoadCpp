#ifndef INSTRUMENT_SPEC_H
#define INSTRUMENT_SPEC_H

#include <iostream>
#include <string>
#include "Wood.h"
#include "Type.h"
#include "Builder.h"

class InstrumentSpec 
{
public:
    InstrumentSpec(
        const Builder     &builder, 
        const std::string &model, 
        const Type        &type,
        const Wood        &backWood,
        const Wood        &topWood
    ) : builder(builder), model(model), topWood(topWood), backWood(backWood), type(type)
    {}

    InstrumentSpec(const InstrumentSpec& other)
     : builder(other.builder), model(other.model), topWood(other.topWood), backWood(other.backWood), type(other.type)
    {}

    Builder getBuilder() const
    {return builder;}

    std::string getModel() const
    {return model;}

    Type getType() const
    {return type;}

    Wood getBackWood() const
    {return backWood;}

    Wood getTopWood() const
    {return topWood;}

    virtual bool equal(const InstrumentSpec& other) const
    {
        const bool match = (builder  == other.builder)   &&
                           (model    == other.model)     &&
                           (type     == other.type)      &&
                           (backWood == other.backWood)  &&
                           (topWood  == other.topWood);
        return match;
    }

    virtual bool operator == (const InstrumentSpec& other) const
    {
        return equal(other);
    }

    friend std::ostream& operator << (std::ostream& os, const InstrumentSpec& spec)
    {
        os << "[InstrumentSpec] model:" << spec.model << ",builder:" << spec.builder << ",topWood:" << spec.topWood;
        os << ",backWood:" << spec.backWood << ",type:" << spec.type; 
        return os;
    }
private:
    std::string model;
    Builder builder;
    Wood    topWood;
    Wood    backWood;
    Type    type;
};


#endif // !INSTRUMENT_SPEC_H