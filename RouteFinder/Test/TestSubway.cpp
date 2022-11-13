#include <iostream>
#include "Subway/Subway.h"

using namespace std;

#define TEST(case, subway)  \
    do {            \
        if (test##case(subway)) {   \
            cout << "Pass " #case "!" << endl;   \
        } else {    \
            cout << "Fail " #case "!" << endl; \
        }\
    } while (0)

bool testAddStation(Subway& subway);
bool testAddConnection(Subway& subway);

int main(int argc, char* argv[])
{
    Subway subway;
    TEST(AddStation, subway);
    TEST(AddConnection, subway);
    return 0;
}

bool testAddStation(Subway& subway)
{
    const string s1Name("Tpe");
    const string s2Name("Hsinchu");
    subway.addStation(s1Name);
    subway.addStation(s2Name);
    for (auto& key : subway.getStations())
    {
        cout << "- " << key << endl;
    }
    return subway.hasStation(s1Name) && subway.hasStation(s2Name);
}

bool testAddConnection(Subway& subway)
{
    const string s1Name("Tpe");
    const string s2Name("Hsinchu");
    const string lineName("Brian");
    subway.addConnection(s1Name, s2Name, lineName);
    for (auto& key : subway.getConnections())
    {
        cout << "- " << key << endl;
    }
    return true;
}
