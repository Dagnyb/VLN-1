#include "userinterface.h"
#include <iostream>
#include <cstdlib>
#include "anitem.h"
#include <fstream>

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
 //   ifstream Scientistfile;
   // Scientistfile.open ("scientist.txt");
   // if (Scientistfile.fail())
   // {
     //   cout<< "Input file opening fail.\n";
       // exit(1);
   // }

    string name;
    string gender;
    int dayofbirth;
    int dayofdeath;

  cout << "Enter the name of the scientist: ";
  cin >> name;
  cout << "Enter gender: ";
  cin >> gender;
  cout << "Enter day of birth: ";
  cin >> dayofbirth;
  cout << "Enter day of death: ";
  cin >> dayofdeath;

  ofstream Scientistfile;
  Scientistfile.open("Scientist.txt");
  Scientistfile << name << ";" << gender << ";" << dayofbirth << ";" << dayofdeath;
  Scientistfile.close();

  }








void UserInterface::searchData()
{
cout <<"case 2\n";
}
