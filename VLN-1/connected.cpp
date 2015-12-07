#include "connected.h"

Connected::Connected()
{
    nameOne = "";
    nameTwo = "";
}
Connected::Connected(string name1, string name2)
{
    nameOne = name1;
    nameTwo = name2;
}

string Connected::getNameOne() const
{
    return nameOne;
}

string Connected::getNameTwo() const
{
    return nameTwo;
}

ostream& operator << (ostream& outs, const Connected& Connected)
{
    outs << setw(30);
    outs.setf(ios::left);
    outs << Connected.nameOne
         << Connected.nameTwo;

    return outs;
}
