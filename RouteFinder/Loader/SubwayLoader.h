#ifndef SUBWAYLOADER_H
#define SUBWAYLOADER_H

#include <string>
#include <fstream>
#include "Subway/Subway.h"
#include "Utility/StringUtil.h"

static inline
void readLine(std::ifstream& ifs, std::string& buf)
{
    std::getline(ifs, buf);
    rstrip(buf);
}

class SubwayLoader {
public:
    SubwayLoader()
    {}

    Subway loadFromFile(const std::string& fname) 
    {
        std::ifstream ifs;
        ifs.open(fname);
        if (ifs.fail()) 
        {
            throw std::invalid_argument("Open " + fname + " Failed");
        }
        Subway subway;
        loadStations(ifs, subway);
        std::string lineName;
        readLine(ifs, lineName);
        while (!lineName.empty())
        {
            loadLine(ifs, subway, lineName);
            readLine(ifs, lineName);
        }
        ifs.close();
        return subway;
    }

    int loadStations(std::ifstream& ifs, Subway& subway)
    {
        std::string line;
        readLine(ifs, line);
        while (!line.empty())
        {
            subway.addStation(line);
            readLine(ifs, line);
        }
        return 1;
    }

    int loadLine(std::ifstream& ifs, Subway& subway, const std::string& lineName)
    {
        std::string s1;
        std::string s2;
        readLine(ifs, s1);
        readLine(ifs, s2);
        while (!s2.empty())
        {
            subway.addConnection(s1, s2, lineName);
            s1 = s2;
            readLine(ifs, s2);
        }
        return 1;
    }
};

#endif  // !SUBWAYLOADER_H
