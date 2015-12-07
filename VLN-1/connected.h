#ifndef CONNECTED_H
#define CONNECTED_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Object for connection between names of two tables in database
// with appropriate variebles set: string name1, string name2

class Connected
{
    public:
        // Default compiler.
        Connected();

        // Compiler that takes in all four variebles in Computer
        Connected(string name1, string name2);

        // returns nameOne.
        string getNameOne() const;

        // returns nameTwo.
        string getNameTwo() const;

        // operator << overwritten to print Connected.
        friend ostream& operator << (ostream& outs, const Connected& Connected);

    private:
        string nameOne, nameTwo;
};

#endif // CONNECTED_H
