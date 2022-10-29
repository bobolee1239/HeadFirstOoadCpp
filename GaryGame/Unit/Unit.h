#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>
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

    friend std::ostream& operator << (std::ostream& os, const Unit& unit)
    {
        os << "[Unit] {name:" << unit.name << "}";
        return os;
    }

private:
    int         id;
    std::string name;
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