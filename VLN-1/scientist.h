#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Object Scientist with appropriate variebles set:
// string Name, string gender, int year of birth, int year of death

class Scientist
{
    public:
        // *******skrifa********
        Scientist();

        // combines Name, gender, year of birth
        Scientist(string aName, string aGender, int aBirthYear, int aDeathYear);

        // *******skrifa********
        string getName() const;

        // *******skrifa********
        string getGender() const;

        // *******skrifa********
        int getBirthYear() const;

        // *******skrifa********
        int getDeathYear() const;

        // operator << overwritten to print Scientist
        friend ostream& operator << (ostream& outs, const Scientist& Scientist);

private:
        string name, gender;
        int birthYear, deathYear;
};

#endif // SCIENTIST_H
