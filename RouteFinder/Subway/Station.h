#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <string>
#include <algorithm>
#include "../Utility/StringUtil.h"

class Station {
public:
    Station(const std::string& name) : name(name)
    {toLowercase(this->name);}
    Station(const Station& other) : name(other.name)
    {toLowercase(this->name);}

    std::string getName() const 
    {return name;}

    bool equals(const Station& rhs) const
    {return name == rhs.name;}

    bool operator == (const Station& rhs) const
    {return equals(rhs);}

    bool lessThan (const Station& rhs) const
    {return name < rhs.name;}

    bool operator < (const Station& rhs) const
    {return lessThan(rhs);}

    friend std::ostream& operator<< (std::ostream& os, const Station& station)
    {
        os << "[Station] " << station.name;
        return os;
    }

private:
    std::string name;

};

template<>
struct std::hash<Station> {
    std::size_t operator() (const Station& station) const
    {
        std::hash<std::string> hasher;
        return hasher(station.getName());
    }
};


#endif  // !STATION_H
