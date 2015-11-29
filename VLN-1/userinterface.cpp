#include "userinterface.h"

using namespace std;

UserInterface::UserInterface()
{

}

void UserInterface::initial()
{
    cout << "D A T A B A S E\n";
    cout << endl;
    cout << "This database contains known computer scientist.\n"
            "You can input new names and/or search in the database.\n"
            "";
    cout << endl;
}
void UserInterface::options()
{
    char control;

    cout << "Choose:\n"
         << "1 to input new computer scientist.\n"
         << "2 to search in the existing database.\n"
         << "3 to quit program.\n";
    cout << endl;
    cin >> control;

    switch (control)
    {
        case '1':
            inputData();
            break;
        case '2':
            searchData();
            break;
        case '3':
           exit(1);
            break;
        default:
            cout << "Invalid input\n";
            options();
            break;
    }
}
void UserInterface::inputData()
{
cout <<"case 1\n";
}

void UserInterface::searchData()
{
cout <<"case 2\n";
}
