#ifndef ANITEM_H
#define ANITEM_H

#include <iostream>
using namespace std;

class anItem
{
    public:
        friend ostream& operator << (ostream& outs, const anItem& anItem);
        //prints out the item

        anItem(string aName, string aGender, int aBirthYear, int aDeathYear);
        anItem(string aName, string aGender, int aBirthYear);
        string getName() const;
        string getGender() const;
        int getBirthYear() const;
        int getDeathYear() const;
    private:
        string name, gender;
        int birthYear, deathYear;
};

#endif // ANITEM_H
