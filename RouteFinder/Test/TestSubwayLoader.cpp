#include <iostream>
#include "Subway/Subway.h"
#include "Loader/SubwayLoader.h"

using namespace std;

#define TEST(case, fname)  \
    do {            \
        try { \
            if (test##case(fname)) {   \
                cout << "Pass " #case " on " << fname << "!" << endl;   \
            } else {    \
                cout << "Fail " #case " on " << fname << "!" << endl; \
            }\
        } catch (exception& e) { \
            cerr << "[ERROR]" << e.what() << endl; \
        } \
    } while (0)

bool testLoadSubway(const string& fname);

void do_hint()
{
    cout << "Usage: ./SubwayLoaderTester <test_file>" << endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        do_hint();
        return 1;
    }
    string fname(argv[1]);
    TEST(LoadSubway, fname);
    return 0;
}

bool testLoadSubway(const string& fname)
{
    #define _IFRF(exp) \
        do {    \
            if (!(exp)) { \
                cerr << "[ERROR]" #exp << endl; \
                return false; \
            } \
        } while (0)
    SubwayLoader loader;
    Subway subway = loader.loadFromFile(fname);
    _IFRF(subway.hasStation("Ajax Rapids"));
    _IFRF(subway.hasStation("HTML Heights"));
    _IFRF(subway.hasStation("Infinite Circle"));
    _IFRF(subway.hasStation("CSS Center"));
    _IFRF(subway.hasConnection("Ajax Rapids", "HTML Heights", "Booch Line"));
    _IFRF(subway.hasConnection("UML Walk", "Ajax Rapids", "Booch Line"));
    _IFRF(subway.hasConnection("OOA&D Oval", "Head First Lounge", "Gamma Line"));
    cout << " --- Stations ---" << endl;
    for (auto& station : subway.getStations())
    {
        cout << "- " << station << endl;
    }
    cout << " --- Connections ---" << endl;
    for (auto& connection : subway.getConnections())
    {
        cout << "- " << connection << endl;
    }
    return true;
    #undef _IFRF
}
