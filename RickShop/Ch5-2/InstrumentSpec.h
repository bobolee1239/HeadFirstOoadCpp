#ifndef INSTRUMENT_SPEC_H
#define INSTRUMENT_SPEC_H

#include <iostream>
#include <string>
#include <map>

#include "PropertyKey.h"
#include "PropertyValue.h"

class InstrumentSpec 
{
public:
    InstrumentSpec(const std::map<PropertyKey, PropertyValue*> &property) 
    {
        for (auto& [key, value] : property)
        {
            this->property.insert(std::make_pair(key, value->dup()));
        }
    }

    InstrumentSpec(const InstrumentSpec& other)
    {
        for (auto& [key, value] : other.property)
        {
            this->property.insert(std::make_pair(key, value->dup()));
        }
    }

    ~InstrumentSpec()
    {
        for (auto& [key, value] : property)
        {
            delete value;
        }
    }

    const PropertyValue* getProperty(const PropertyKey& key) const 
    {
        auto itr = property.find(key);
        if (itr == property.end())
        {return NULL;}
        else
        {return itr->second;}
    }

    std::map<PropertyKey, PropertyValue*> getProperties() const
    {
        return property;
    }

    bool equal(const InstrumentSpec& other) const
    {
        for (auto &[key, pValue] : other.property)
        {
            auto itr = property.find(key);
            if (itr == property.end())
            {return false;}
            else if (*(itr->second) != *pValue)
            {return false;}
        }
        return true;
    }

    bool operator == (const InstrumentSpec& other) const
    {
        return equal(other);
    }

    friend std::ostream& operator << (std::ostream& os, const InstrumentSpec& spec)
    {
        os << "[InstrumentSpec] {";
        for (auto& [key, pValue] : spec.property)
        {
            os << key << ":";
            pValue->log(os);
            os << ", ";
        }
        os << "}";
        return os;
    }

private:
    std::map<PropertyKey, PropertyValue*> property;
};


#endif // !INSTRUMENT_SPEC_H