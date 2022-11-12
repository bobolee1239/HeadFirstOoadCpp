#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>
#include <map>
#include <functional>

class Unit {
public:
    Unit() : name("no name"), id(-1)
    {}

    Unit(const std::string& name, const int& id)
     : name(name), id(id)
    {}

    Unit(const Unit& other) 
     : name(other.name), id(other.id)
    {}

    bool operator == (const Unit& rhs) const
    {return name == rhs.name;}

    int getId() const 
    {return id;}

    void setType(const std::string& name)
    {this->name = name;}

    std::string getType() const
    {return name;}

    void setProperty(const std::string& key, const std::string& value)
    {properties[key] = value;}

    std::string getProperty(const std::string& query)
    {
        if (properties.find(query) == properties.end())
        {return std::string("");}
        return properties[query];
    }

    friend std::ostream& operator << (std::ostream& os, const Unit& unit)
    {
        os << "[Unit] {name:" << unit.name << "}";
        return os;
    }

private:
    int         id;
    std::string name;
    std::string type;
    std::map<std::string, std::string> properties;
    friend class UnitHash;
    friend class UnitLt;
};


class UnitHash {
public:
    size_t operator() (const Unit& unit) const
    {
        std::hash<int> hasher;
        return hasher(unit.id);
    }
};

class UnitLt {
public:
    bool operator()(const Unit& lhs, const Unit& rhs) const
    {
        return lhs.id < rhs.id;
    }
};

#endif // !UNIT_H