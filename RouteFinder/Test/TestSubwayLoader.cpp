#include <iostream>
#include "Subway/Subway.h"
#include "Loader/SubwayLoader.h"

using namespace std;

#define TEST(case, fname)  \
    do {            \
        if (test##case(fname)) {   \
            cout << "Pass " #case "on " << fname << "!" << endl;   \
        } else {    \
            cout << "Fail " #case "on " << fname << "!" << endl; \
        }\
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
    SubwayLoader loader;
    Subway subway = loader.loadFromFile(fname);
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
}
