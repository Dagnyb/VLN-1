#include "userinterface.h"
#include "anitem.h"
#include <string>

UserInterface::UserInterface()
{

}

void UserInterface::initial()
{
    cout << "D A T A B A S E\n";
    cout << endl;
    cout << "This database contains known computer scientist.\n"
            "You can add new scientists, view, sort and/or "
            "search for a scientist in the database.\n"
            "";
    cout << endl;
}
void UserInterface::options()
{
    char control;

    cout << "Choose:\n"
         << "1 to input new computer scientist.\n"
         << "2 to search in the existing database.\n"
         << "3 to view existing data.\n"
         << "4 to quit program.\n";
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
            viewData();
            break;
        case '4':
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
    ifstream Scientistfile;
    Scientistfile.open ("scientist.txt");
    if (Scientistfile.fail())
    {
        cout<< "Input file opening fail.\n";
        exit(1);
    }
    //TO DO Dagný skrifar fall sem les úr csv skránni og skrifar það í listann.
}


void UserInterface::searchData()
{
cout <<"case 2\n";
}


void UserInterface::viewData()
{
    cout << "case 3\n";
}
