#include "userinterface.h"
#include <QtSql/QSql>

const int MINYEAR = 1800;
const int MAXYEAR = 2015;


UserInterface::UserInterface()
{
    sci = Service() ;
}

void UserInterface::initial()
{
    cout << "\t- - - - - - - - -\n "
         << "\t D A T A B A S E\n"
         << "\t- - - - - - - - -"
         << endl
         << "This database contains known computer scientist.\n"
         << "You can add new scientists, view, sort and/or\n"
         << "search for a scientist in the database.\n"
         << endl;
    sci.dataFromFile();  // HÉR DATA
    options();

}
void UserInterface::options()
{
    bool loopAgain = true;
    while(loopAgain == true)
    {
        bool insideLoopAgain = true;
        cout << endl
             << "Select:\n"
             << "1) to input new computer scientist.\n"
             << "2) to search in the existing database.\n"
             << "3) to view existing data.\n"
             << "4) to quit program.\n"
             << endl
             << "Selection: ";
        char lastControl;
        cin >> lastControl;
        cout << endl;
        while (insideLoopAgain == true)
        {
            insideLoopAgain = false;
            switch (lastControl)
            {
                case '1':
                    inputData();
                    loopAgain = true;
                    break;
                case '2':
                    searchData();
                    loopAgain = true;
                    break;
                case '3':
                    viewData();
                    loopAgain = true;
                    break;
                case '4':
                    loopAgain = false;
                    exit(1);
                    break;
                default:
                    errorMessage(". Please select 1, 2, 3 or 4: ");
                    cin >> lastControl;
                    loopAgain = false;
                    insideLoopAgain = true;
                    break;
            }
        }
    }
}

void UserInterface::inputData()
{
    bool add = true;
    while (add == true)
    {
        name();
        gender();
        birthYear();
        deathYear();
        cout << endl;
        add = addAnother();
    }
}

string UserInterface::name()
{
    cout << "Name of the scientist: ";
    string name;
    cin.sync();
    getline(cin, name);
    //locale loc;
    while(name.empty())  //setja in isdigit held samt að það vinni bara með char ath ef við höfum tíma.
    {
        errorMessage(". Please input name: ");
        getline(cin, name);
    }
    return name;
}

string UserInterface::gender()
{
    cout << "Select gender 1) for female\n"
         << "              2) for male       : ";

    char ans;
    cin >> ans;
    bool again = true;
    string gender;

    while(again == true)
    {
        again = false;
        switch (ans)
        {
            case '1':
                gender = "female";
                break;
            case '2':
                gender = "male";
                break;
            default:
                errorMessage("input 1 or 2. ");
                cin >> ans;
                cout <<"selection:    ";
                again = true;
                break;
        }
    }
    return gender;
}

int UserInterface::birthYear()
{
    int year;
    cout << "Year of birth: ";
    cin >> year;

    while (year < MINYEAR || year > MAXYEAR )
    {
        errorMessage(" Please input valid year on the format YYYY: ");
        cin >> year;
    }
    return year;
}

int UserInterface::deathYear()
{
    int year;

    cout << "Is the scientist still alive? (y/n): ";
    char ans;
    cin >> ans;

    bool again = true;

    while(again == true)
    {
        again = false;
        switch (ans)
        {
            case 'y':
            case 'Y':
                year = 0;  //kann ekki að gera ekkert eins og databaseinn tekur við
                break;
            case 'n':
            case 'N':
                cout << "Year of death: ";
                cin >> year;
                while (year < MINYEAR || year > MAXYEAR )
                {
                    errorMessage(" Please select y or n: ");
                    cin >> year;
                }
                break;
            default:
                errorMessage("input y or n. ");
                cin >> ans;
                again = true;
                break;
        }
    }
    return year;
}

bool UserInterface::addAnother()
{
    bool add = false;
    bool loopAgain = true;

    while(loopAgain == true)
    {
        cout << "Add another scientist? (y/n): ";
        char another1, another2;
        cin >> another1;

        if (another1 == 'y' || another1 == 'Y')
        {
            add = true;
            loopAgain = false;
        }
        else if (another1 == 'n' || another1 == 'N')
        {
            add = false;
            loopAgain = false;
        }
        else
        {
            do
            {
            errorMessage(" Please select y or n: ");
            cin >> another2;
            }
            while(another2 != 'y' || another2 != 'Y' || another2 != 'n' || another2 != 'N');

        another1 = another2;
        loopAgain = true;
        }
    }

    return add;
}
void UserInterface::searchData()
{
    string nameSearch;

    cout << "Please enter the name of scientist you wish to find: ";
    cin.sync();
    getline(cin, nameSearch);
    list<Scientist> sciFindData = sci.findData(nameSearch); // Upphaflsstillir listann


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

   do
    {
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


void UserInterface::printList(list<Scientist> aList)
{
    for (list<Scientist>::iterator it = aList.begin(); it != aList.end(); it++)
    {
        cout << *it;
    }
}

void UserInterface::errorMessage(string aString)
{
    cout << "Invalid input" << aString << endl;
}
