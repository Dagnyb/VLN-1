#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


// Object Computer with appropriate variebles set:
// string Name, string gender, int year of birth, int year of death

class Computer
{
    public:
        // Default compiler.
        Computer();

        // Compiler that takes in all four variebles in Computer
        Computer(string aName, int aYear, string aType, bool wasItBuilt);

        // returns name.
        string getName() const;

        // returns year.
        int getYear() const;

        // returns type.
        string getType() const;

        // returns bool value if computer was built.
        bool getwasItBuilt() const;

        // operator << overwritten to print Computer
        friend ostream& operator << (ostream& outs, const Computer& Computer);

    private:
        string name, type;
        int year;
        bool built;
};

#endif // COMPUTER_H
