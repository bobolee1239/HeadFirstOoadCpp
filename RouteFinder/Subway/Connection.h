#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <string>
#include "./Station.h"
#include "../Utility/StringUtil.h"

class Connection {
public:
    Connection(const Station& station1, const Station& station2, const std::string& lineName)
     : station1(station1), station2(station2), lineName(lineName)
    {
        toLowercase(this->lineName);
    }
    Connection(const Connection& other)
     : station1(other.station1), station2(other.station2), lineName(other.lineName)
    {
        toLowercase(this->lineName);
    }

    Station getStation1() const
    {return station1;}

    Station getStation2() const
    {return station2;}

    std::string getLineName() const
    {return lineName;}

    bool lessThan (const Connection& rhs) const
    {
        #define _COMBINE(ptr)   ((ptr)->station1.getName() + (ptr)->station2.getName())
        return _COMBINE(this) < _COMBINE(&rhs);
        #undef _COMBINE
    }

    bool operator < (const Connection& rhs) const
    {return lessThan(rhs);}

    friend std::ostream& operator<< (std::ostream& os, const Connection& connect)
    {
        os << "[Connection] " << connect.station1 << " -> " << connect.station2;
        os << " @ " << connect.lineName << " line";
        return os;
    }

private:
    Station station1;
    Station station2;
    std::string lineName;
};

#endif  // !CONNECTION_H
