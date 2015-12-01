#include "userinterface.h"
#include "list.h"

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
    List sciList;


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
            sciList.searchData();
            break;
        case '3':
            viewData(sciList.getList());
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
    string name;
    string gender;
    string dayofbirth;
    string dayofdeath;

      cout << "Enter the name of the scientist: ";
      getline (cin, name);
      cout << "Enter gender: ";
      getline (cin,gender);
      cout << "Enter year of birth: ";
      getline (cin, dayofbirth);
      cout << "Enter year of death: ";
      getline (cin, dayofdeath);

    string out = name + ";" + gender + ";" + dayofbirth + ";" + dayofdeath + "\n";
    ofstream Scientistfile;
    Scientistfile.open("Scientist.txt", ios::out | ios::app);
        if (Scientistfile.fail())
            {
                cout<< "Input file opening fail.\n";
                exit(1);
             }

        else
            {
                Scientistfile << out.c_str();
            }

    Scientistfile.close();
    cout << endl << endl;

    char svar;

    cout << "Add another scientist? Y/N ";
    cin >> svar;

    if(svar=='Y' || svar=='y'){
        inputData();
    }
    else if (svar=='N' || svar=='n') {
        options();

    }
    else {
        cout << "Sorry this was invalid input. You will be directed to the main menu";
        cout << endl << endl;
        options();

    }
  }



    //TO DO Dagný skrifar fall sem les úr csv skránni og skrifar það í listann.






void UserInterface::viewData(list<anItem> aList)
{
    for (list<anItem>::iterator it = aList.begin(); it != aList.end(); it++)
    {
        cout << *it;
    }
}
