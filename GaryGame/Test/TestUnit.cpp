#include "Unit/Unit.h"

using namespace std;

int testUnitTypeOp(const string& iType, const string& expectedOut);
int testSetUnitProp(const string& propName, const string& propValue);
int testChangeUnitProp(Unit &unit, const string& propName, const string& propValue);
int testGetEmptyUnitProp(const string& propName);

#define _I0R1(exp)   \
    do {    \
        if (!(exp)) {   \
            cerr << "[ERROR]@" << __LINE__ << endl; \
            return 1;   \
        }   \
    } while (0)

int main(int argc, char* argv[])
{
    _I0R1(testUnitTypeOp("infantry", "infantry"));
    cout << "[INFO] Pass!" << endl;
    _I0R1(testSetUnitProp("hitPoints", "25"));
    cout << "[INFO] Pass!" << endl;
    Unit unit;
    unit.setProperty("hitPoints", "25");
    _I0R1(testChangeUnitProp(unit, "hitPoints", "15"));
    cout << "[INFO] Pass!" << endl;
    _I0R1(testGetEmptyUnitProp("strength"));
    cout << "[INFO] Pass!" << endl;
    return 0;
}

int testUnitTypeOp(const string& iType, const string& expectedOut)
{
    Unit unit;
    unit.setType(iType);
    return unit.getType() == expectedOut;
}

int testSetUnitProp(const string& propName, const string& propValue)
{
    Unit unit;
    unit.setProperty(propName, propValue);
    return unit.getProperty(propName) == propValue;
}

int testChangeUnitProp(Unit& unit, const string& propName, const string& propValue)
{
    unit.setProperty(propName, propValue);
    return unit.getProperty(propName) == propValue;
}

int testGetEmptyUnitProp(const string& propName)
{
    Unit unit;
    return unit.getProperty(propName) == string("");
}