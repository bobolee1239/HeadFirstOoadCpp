#ifndef SUBWAY_H
#define SUBWAY_H

#include <set>
#include "./Station.h"
#include "./Connection.h"

class Subway {
public:
    Subway() : stations(), connections()
    {}

    bool hasStation(const std::string& stationName) const
    {
        return stations.count(Station(stationName));
    }

    void addStation(const std::string& stationName)
    {
        if (!hasStation(stationName))
        {
            stations.insert(Station(stationName));
        }
    }

    void addConnection(
        const std::string& station1Name,
        const std::string& station2Name,
        const std::string& lineName
    ) {
        const bool isValid = hasStation(station1Name) && hasStation(station2Name);
        if (!isValid)
        {
            throw std::runtime_error("Invalid Connection!");
        }
        Station station1(station1Name);
        Station station2(station2Name);
        connections.insert(Connection(station1, station2, lineName));
        connections.insert(Connection(station2, station1, lineName));
    }

    std::set<Station> getStations() const 
    {return stations;}
    std::set<Connection> getConnections() const 
    {return connections;}

private:
    std::set<Station>  stations;
    std::set<Connection> connections;
};

#endif  // !SUBWAY_H

