#ifndef ANITEM_H
#define ANITEM_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class anItem // Returns anItem with appropriate variebles set: Name, gender, year, of birth & year of death
{
    public:
        friend ostream& operator << (ostream& outs, const anItem& anItem);
        // << operator overwritten to print anItem
        //prints out the item
        anItem();
        // combines Name, gender, year of birth
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
// git prufa Eva
