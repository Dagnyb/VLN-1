#include "userinterface.h"

UserInterface::UserInterface()
{

}

void UserInterface::initial()
{
    cout << "- - - - - - - - -\n ";
    cout << "D A T A B A S E\n";
    cout << "- - - - - - - - -";
    cout << endl;
    cout << "This database contains known computer scientist.\n"
            "You can add new scientists, view, sort and/or "
            "search for a scientist in the database.\n"
            "";
    cout << endl;
    options();
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
    string name;
    string gender;
    string dayofbirth;
    string dayofdeath;

      cout << "Enter the name of the scientist: ";
      getline (cin, name);
      cout << "Enter gender: ";
      getline (cin,gender);
      cout << "Enter day of birth: ";
      getline (cin, dayofbirth);
      cout << "Enter day of death: ";
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


  }

void UserInterface::sortOption()
{
   List temp;
   char sort;
   bool repeat;
   cout << "Please enter s for an alphabetically "
        << "sorted list, r for a reversed alphabetically "
        << "sorted list or q to quit: "
        << endl;

   do{
       repeat = false;
       cin >> sort;
       sort = toupper(sort);


   switch (sort)
   {
       case 'S':
           cout << "The list in alphabetical order: " << endl;
           printList(temp.sortListS());
       break;
       case 'R':
           cout << "The list in reversed alphabetical order: " << endl;
           printList(temp.sortListR());

       break;
       case 'Q':
       break;
       default:
       repeat = true;
       cout << "Invalid input please enter s for an alphabetically sorted list, r for a reversed alphabetically sorted list or q to quit: " << endl;
   }
}
while (repeat);
}


void UserInterface::searchData()
{
cout <<"case 2\n";
}

void UserInterface::viewData()
{
    List sciList;
    sciList.dataFromFile();
    sortOption();
    printList(sciList.getList());
    cout << endl;
    options();
    //    ath setja inn valmöguleika fyrir sort
}



void UserInterface::printList(list<anItem> aList)
{
    for (list<anItem>::iterator it = aList.begin(); it != aList.end(); it++)
    {
        cout << *it;
    }
}
