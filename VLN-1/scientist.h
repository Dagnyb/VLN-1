#ifndef SCIENTIST__H
#define SCIENTIST__H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Scientist // Returns Scientist with appropriate variebles set: Name, gender, year, of birth & year of death
{
    public:
        friend ostream& operator << (ostream& outs, const Scientist& Scientist);
        // << operator overwritten to print Scientist
        //prints out the item
        Scientist();
        // combines Name, gender, year of birth
        Scientist(string aName, string aGender, int aBirthYear, int aDeathYear);
        string getName() const;
        string getGender() const;
        int getBirthYear() const;
        int getDeathYear() const;
        //string name;
    private:
        string name, gender;
        int birthYear, deathYear;
};

#endif // SCIENTIST__H
