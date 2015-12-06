#include "computer.h"

Computer::Computer()
{
    name = "";
    year = 0;
    type = "";
    built = false;
}

Computer::Computer(string aName, int aYear, string aType, bool wasItBuilt)
{
    name = aName;
    year = aYear;
    type = aType;
    built = wasItBuilt;
}

string Computer::getName() const
{
    return name;
}

int Computer::getYear() const
{
    return year;
}

string Computer::getType() const
{
    return type;
}

bool Computer::getwasItBuilt() const
{
    return built;
}

ostream& operator << (ostream& outs, const Computer& Computer)
{
    outs << setw(30);
    outs.setf(ios::left);
    outs << Computer.name
         << Computer.year << "\t"
         << Computer.type << "\t";
    if (Computer.built == true)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No" << endl;
    }
    return outs;
}
