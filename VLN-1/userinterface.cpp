#include "userinterface.h"

const int MINYEAR = 1500;
const int MAXYEAR = 2015;


UserInterface::UserInterface()
{
    sci = Service() ;
    com = ServiceComputer();
}

void UserInterface::initial()
{
    cout << "\t- - - - - - - - -\n "
         << "\t D A T A B A S E\n"
         << "\t- - - - - - - - -"
         << endl
         << "This program connects to a database containing known computer\n"
         << "scientists and the devices they have been credited to work on.\n"
         << endl
         << "You can use this program to add a new scientist and/or computer to\n"
         << "the database and connect the corresponding scientist to his devices,\n"
         << "search for a scientist or a device as well as change existing data "
         << "regarding the scientists and/or their devices.\n"
         << endl;
    options();

}

void UserInterface::options()
{
    bool loopAgain = true;
    while(loopAgain == true)
    {
        cout << endl
             << "Main menu:\n"
             << "-----------\n"
             << "\n"
             << "1) to input new data.\n"
             << "2) to search in the existing database.\n"
             << "3) to view existing data.\n"
             << "4) to quit program.\n"
             << endl
             << "Selection: ";
        char control;
        cin >> control;
        cout << endl;
        bool insideLoopAgain = true;
        while (insideLoopAgain == true)
        {
            insideLoopAgain = false;
            switch (control)
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
                    cin >> control;
                    loopAgain = false;
                    insideLoopAgain = true;
                    break;
            }
        }
    }
}

void UserInterface::inputData()
{
    bool loopAgain = true;
    while(loopAgain == true)
    {
        cout << endl
             << "Input menu:\n"
             << "-----------\n"
             << "\n"
             << "1) to input new computer scientist.\n"
             << "2) to input new computer.\n"
             << "3) to connect scientist to computer.\n"
             << "4) to connect computer to scientist.\n"
             << "5) back to main menu"
             << endl
             << "Selection: ";
        char control;
        cin >> control;
        cout << endl;
        bool insideLoopAgain = true;
        while (insideLoopAgain == true)
        {
            insideLoopAgain = false;
            switch (control)
            {
                case '1':
                    inputScientist();
                    loopAgain = true;
                    break;
                case '2':
                    inputComputer();
                    loopAgain = true;
                    break;
                case '3':
                    inputConnectionSciCom();
                    loopAgain = true;
                    break;
                case '4':
                 //   inputConnectionComSci();
                    loopAgain = true;
                    break;
                case '5':
                    loopAgain = false;
                    options();
                    break;
                default:
                    errorMessage(". Please select 1, 2, 3, 4 or 5: ");
                    cin >> control;
                    loopAgain = false;
                    insideLoopAgain = true;
                    break;
            }
        }
    }
}

void UserInterface::inputConnectionSciCom()
{
    cout << "Enter full name of the scientist you wich to find: ";
    string scientist = name();
    list <Scientist> findScientistFull = list <Scientist>();
    findScientistFull = sci.findDataFull(scientist);

    if (findScientistFull.empty())
    {
        cout << "Scientist not found\n"
             << "you will be directed to main menu"
             << endl;
//        scientist = "NULL";
        options();
    }
    else
    {
        printList(findScientistFull);

        cout << "Enter full name of the computer you wich to find: ";
        string computer = name();
        list <Computer> findComputerFull = list <Computer>();
        findComputerFull = com.findDataFull(computer);

        if (findComputerFull.empty())
        {
            cout << "Computer not found\n"
                 << "you will be directed to main menu"
                 << endl;
//          computer = "NULL";
            options();
        }
        else
        {
            printComputerList(findComputerFull);
            Connected sciToCom(scientist, computer);
            if(connect.connectSciToCom(sciToCom))
            {
                cout << "Connection made";
            }
            else
            {
                cout << "connecion faild";
            }
        }
    }
}

void UserInterface::inputScientist()
{
    bool add = true;
    while (add == true)
    {
        cout << "Name of the scientist: ";
        string newName = name();
        string newGender= gender();
        int newBYear = birthYear();
        int newDYear = deathYear();
        Scientist temp(newName, newGender, newBYear, newDYear);
        sci.newScientist(temp);
        cout << endl;
        add = addAnother();
    }
}

string UserInterface::name()
{
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

    char control;
    cin >> control;
    bool loopAgain = true;
    string gender;

    while(loopAgain == true)
    {
        loopAgain = false;
        switch (control)
        {
            case '1':
                gender = "female";
                break;
            case '2':
                gender = "male";
                break;
            default:
                errorMessage(". Please input 1 or 2: ");
                cin >> control;
                cout <<"selection:    ";
                loopAgain = true;
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
    char control;
    cin >> control;

    bool loopAgain = true;

    while(loopAgain == true)
    {
        loopAgain = false;
        switch (control)
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
                    errorMessage(" Please insert a valid year (from 1500 to current date) : ");
                    cin >> year;
                }
                break;
            default:
                errorMessage("input y or n. ");
                cin >> control;
                loopAgain = true;
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
            errorMessage(". Please select y or n: ");
            cin >> another2;
            }
            while(another2 != 'y' || another2 != 'Y' || another2 != 'n' || another2 != 'N');

        another1 = another2;
        loopAgain = true;
        }
    }

    return add;
}

void UserInterface::inputComputer()
{
    bool add = true;
    while (add == true)
    {
        cout << "Name of the computer: ";
        string newName = name();
        string newtype = type();
        newWasItBuilt = wasItBuilt();
        int newYearBuilt = yearBuilt();
        Computer temp(newName, newYearBuilt, newtype, newWasItBuilt);
        com.newComputer(temp);
        cout << endl;
        add = addAnotherComputer();
    }
}

int UserInterface::yearBuilt()
{
    if(newWasItBuilt == true)
    {
        int year;
        cout << "Year built: ";
        cin >> year;

    while (year < MINYEAR || year > MAXYEAR )
    {
        errorMessage(" Please input a valid year (from 1500 to current date) : ");
        cin >> year;
    }
        return year;
    }else cout << "Your data has been processed" << endl;
    return 0;
    options();

}

string UserInterface::type()
{
    cout << "Type of the computer: ";

    string result = name();

    return result;
}

bool UserInterface::wasItBuilt()
{
    int built;

    cout << "Was the computer built? (y/n): ";
    char control;
    cin >> control;

    bool loopAgain = true;

    while(loopAgain == true)
    {
        loopAgain = false;
        switch (control)
        {
            case 'n':
            case 'N':
                built = 0;
                break;
            case 'y':
            case 'Y':
                built = 1;
               // yearBuilt();
                break;
            default:
                errorMessage("input y or n. ");
                cin >> control;
                loopAgain = true;
                break;
        }
    }
    return built;
}

bool UserInterface::addAnotherComputer()
{
    bool add = false;
    bool loopAgain = true;

    while(loopAgain == true)
    {
        cout << "Add another computer? (y/n): ";
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
            errorMessage(". Please select y or n: ");
            cin >> another2;
            }
            while(another2 != 'y' || another2 != 'Y' || another2 != 'n' || another2 != 'N');

        another1 = another2;
        loopAgain = true;
        }
    }

    return add;
}

string UserInterface::searchString()
{
    string search;

    cout << "Please enter the name: ";
    cin.sync();
 //   cin.ignore();  Fyrir Maca eða ????
    getline(cin, search);

    return search;
}

void UserInterface::searchData()
{
    bool loopAgain = true;
    while(loopAgain == true)
    {
        cout << endl
             << "Search Menu:\n"
             << "------------\n"
             << "\n"
             << "1) to search for scientists.\n"
             << "2) to search for computer.\n"
             << "3) back to main menu"
             << endl
             << "Selection: ";
        char control;
        cin >> control;
        cout << endl;
        bool insideLoopAgain = true;
        while (insideLoopAgain == true)
        {
            insideLoopAgain = false;
            switch (control)
            {
                case '1':
                    {list<Scientist> s = list<Scientist>();
                     s = sci.findData(searchString());
                     printList(s);
                     loopAgain = true;}
                     break;
                case '2':
                    {list<Computer> c = list<Computer>();
                    c = com.findDataComp(searchString());
                    printComputerList(c);
                    loopAgain = true;}
                    break;
                case '3':
                    loopAgain = false;
                    options();
                    break;
                default:
                    errorMessage(". Please select 1, 2 or 3: ");
                    cin >> control;
                    loopAgain = false;
                    insideLoopAgain = true;
                    break;
            }
        }
    }
}



void UserInterface::viewData()
{
    bool loopAgain = true;
    while(loopAgain == true)
    {
        cout << endl
             << "View menu:\n"
             << "-----------\n"
             << "\n"
             << "1) to view scientists.\n"
             << "2) to view computers.\n"
             << "3) to view connections between scientist and computer.\n"
             << "4) to view connections between computer and scientist.\n"
             << "5) back to main menu"
             << endl
             << "Selection: ";
        char control;
        cin >> control;
        cout << endl;
        bool insideLoopAgain = true;
        while (insideLoopAgain == true)
        {
            insideLoopAgain = false;
            switch (control)
            {
                case '1':
                    sortOptionsScientist();
                    loopAgain = true;
                    break;
                case '2':
                    sortOptionsComputers();
                    loopAgain = true;
                    break;
                case '3':
                    viewScientistToComputer();
                    loopAgain = true;
                    break;
                case '4':
                //    viewComputerToScientist();
                    loopAgain = true;
                    break;
                case '5':
                    loopAgain = false;
                    options();
                    break;
                default:
                    errorMessage(". Please select 1, 2, 3, 4 or 5: ");
                    cin >> control;
                    loopAgain = false;
                    insideLoopAgain = true;
                    break;
            }
        }
    }
}

void UserInterface::sortOptionsScientist()
{
    cout << "Select:\n"
         << "1) for alphabetical order.\n"
         << "2) for reverse alphabetical order.\n"
         << "3) for order by year of birth.\n"
         << endl
         << "Selection: ";
        char control;
        cin >> control;
        bool loopAgain = true;
        while(loopAgain == true)
        {
            loopAgain = false;
            switch (control)
            {
                case '1':
                    printList(sci.viewScientistAlphabetically());
                    break;
                case '2':
                    printList(sci.viewScientistReverse());
                    break;
                case '3':
                    cout << "case 3";
                    break;
                default:
                    errorMessage(". Please input 1, 2 or 3: ");
                    cin >> control;
                    cout <<"selection:    ";
                    loopAgain = true;
                    break;
            }
        }
}

void UserInterface::sortOptionsComputers()
{
    cout << "Select:\n"
         << "1) for alphabetical order.\n"
         << "2) for reverse alphabetical order.\n"
         << endl
         << "Selection: ";
        char control;
        cin >> control;
        bool loopAgain = true;
        while(loopAgain == true)
        {
            loopAgain = false;
            switch (control)
            {
                case '1':
                    printComputerList(com.viewComputerAlphabetically());
                    break;
                case '2':
                    printComputerList(com.viewComputerReverse());
                    break;
                default:
                    errorMessage(". Please input 1 or 2: ");
                    cin >> control;
                    cout <<"selection:    ";
                    loopAgain = true;
                    break;
            }
        }
}

void UserInterface::viewScientistToComputer()
{
     printConnectList(connect.viewSciToCom());

}

void UserInterface::printList(list <Scientist> aList)
{
    for (list <Scientist>::iterator it = aList.begin(); it != aList.end(); it++)
    {
        cout << *it;
    }
}

void UserInterface::printComputerList(list <Computer> aList)
{
    for (list <Computer>::iterator it = aList.begin(); it != aList.end(); it++)
    {
        cout << *it;
    }
}

void UserInterface::printConnectList(list <Connected> aList)
{
    for (list <Connected>::iterator it = aList.begin(); it != aList.end(); it++)
    {
        cout << *it;
    }
}

void UserInterface::errorMessage(string aString)
{
    cout << "Invalid input" << aString << endl;
}
