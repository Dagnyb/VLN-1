#include "userinterface.h"
#include <iostream>

using namespace std;

UserInterface::UserInterface()
{

}

void UserInterface::initial()
{
    cout << "D A T A B A S E\n";
    cout << endl;
    cout << "This database contains known computer scientist.\n"
            "You can input new names and/or search in the database\n"
            "";
    cout << endl;
}
void UserInterface::options()
{
    cout << "Choose:\n"
         << "1 to input new computer scientist.\n"
         << "2 to search in the existing database.\n";
    cout << endl;
}
