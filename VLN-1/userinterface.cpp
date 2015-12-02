#include "userinterface.h"



UserInterface::UserInterface()
{
    sci = List() ;

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
    sci.dataFromFile();
    options();
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
    string name;
    string gender;
    string dayofbirth;
    string dayofdeath;
    int genderans;
    char liveans;

      cout << "Enter the name of the scientist: ";
      cin.sync();
      getline(cin, name);

      cout << "Enter 1 for female or 2 for male: ";
      cin >> genderans;

      if (genderans == 1){
          gender = "female";
      }
      else if (genderans == 2) {
          gender = "male";
      }
      else {
          cout << "Invalit input";
          cout << endl << endl;
          inputData();
      }

      cin.sync();
      cout << "Enter year of birth: ";
      while(getline(cin, dayofbirth)&& dayofbirth.size() !=4){
          cout << "Please enter a valid year.";
      }

      cin.sync();

      cout << "Is " << name << " a live?  Y/N: ";
      cin >> liveans;
      if(liveans=='Y' || liveans=='y'){

          dayofdeath = "0";

      }
      else if (liveans=='N' || liveans=='n') {
          cin.sync();
          cout << "Enter year of death: ";
          while(getline (cin, dayofdeath) && dayofdeath.size()!=4){
              cout << "Please enter a valid year.: ";

      }}
      else {
          cout << "Sorry this was invalid input. You will be directed to the main menu";
          cout << endl << endl;
          options();

      }



    string out = name + ", " + gender + ", " + dayofbirth + ", " + dayofdeath + "\n";
    ofstream Scientistfile;
    Scientistfile.open(FILENAME.c_str(), ios::out | ios::app);
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
void UserInterface::searchData()
{
    string nameSearch;

    cout << "Please enter the name of scientist you wish to find: ";
    cin.sync();
    getline(cin, nameSearch);
    list<anItem> sciFindData = sci.findData(nameSearch); // Upphaflsstillir listann


    if (sciFindData.empty())
    {
            cout << "Scientist not found\n";
    }
    else
    {
        printList(sciFindData);
    }

            char ans;

            cout << "Do want to try again? Y/N ";
            cin >> ans;

            if(ans=='Y' || ans=='y')
            {
                searchData();
            }
            else if (ans=='N' || ans=='n')
            {
                options();
            }
            else
            {
                cout << "Sorry this was invalid input. You will be directed to the main menu";
                cout << endl << endl;
                options();
            }
        }

void UserInterface::sortOption()
{
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
           printList(sci.sortListS());
       break;
       case 'R':
           cout << "The list in reversed alphabetical order: " << endl;
           printList(sci.sortListR());

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

void UserInterface::viewData()
{
    printList(sci.getList());
    cout << endl;
    sortOption();
    options();
}


void UserInterface::printList(list<anItem> aList)
{
    for (list<anItem>::iterator it = aList.begin(); it != aList.end(); it++)
    {
        cout << *it;
    }
}
