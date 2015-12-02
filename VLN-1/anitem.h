#ifndef ANITEM_H
#define ANITEM_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class anItem
{
    public:
        friend ostream& operator << (ostream& outs, const anItem& anItem);
        //prints out the item
        anItem();
        anItem(string aName, string aGender, int aBirthYear, int aDeathYear);
        string getName() const;
        string getGender() const;
        int getBirthYear() const;
        int getDeathYear() const;
        //string name;
    private:
        string name, gender;
        int birthYear, deathYear;
};

#endif // ANITEM_H
