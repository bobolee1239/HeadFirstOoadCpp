#ifndef PROPERTY_VALUE_H
#define PROPERTY_VALUE_H

#include <iostream>
#include <string>

class PropertyValue {
public:
    PropertyValue() 
    {}

    virtual ~PropertyValue() = 0;
    virtual PropertyValue* dup() = 0;
    virtual bool operator == (const PropertyValue& rhs) const = 0;
    virtual bool operator != (const PropertyValue& rhs) const = 0;
    virtual bool equal(const PropertyValue& rhs) const = 0;
    virtual void log(std::ostream& os) const = 0;
};

PropertyValue::~PropertyValue() {}

template<class T>
class Property : public PropertyValue {
public:
    Property(const T& data) : PropertyValue(), data(data)
    {}
    ~Property() {}

    virtual PropertyValue* dup()
    {
        return static_cast<PropertyValue*>(new Property(*this));
    }

    bool equal(const Property& rhs) const 
    {return data == rhs.data;}
    bool operator == (const Property& rhs) const
    {return equal(rhs);}
    bool operator != (const Property& rhs) const
    {return !equal(rhs);}

    virtual bool equal(const PropertyValue& rhs) const
    {
        const Property<T>* ptr = dynamic_cast<const Property<T>*>(&rhs);
        if (ptr)
        {return equal(*ptr);}
        else
        {return false;}
        // return rhs.equal(*this);
    }
    virtual bool operator == (const PropertyValue& rhs) const
    {return equal(rhs);}
    virtual bool operator != (const PropertyValue& rhs) const
    {return !equal(rhs);}

    virtual void log(std::ostream& os) const
    {
        os << data;
    }

private:
    T data;
};


#endif // !PROPERTY_VALUE_H