#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <iostream>
#include <cstdlib>
#include <list>
//#include <fstream>
#include <string>
#include "scientist.h"
#include "computer.h"
#include "connected.h"
#include "service.h"
#include "servicecomputer.h"

using namespace std;


class UserInterface
{
public:
    UserInterface();

    // the head of the output
    void initial();

    // allows the user to choose what to do
    void options();

    // allows the user to choose what to do
    void inputData();

    //
    void inputScientist();

    //
    Connected inputConnectionComSci();

    //
    Connected inputConnectionSciCom();


    // search for name in List
    void searchData();

    // writes list to screen without parameters
    void viewData();

    // prints out the list of scientist
    void printList (list<Scientist> aList);

    // prints out the list of computer
    void printComputerList (list<Computer> aList);

    // allows the user to choose how he wants to sort the list af scientists.
    void sortOptionsScientist();

    // allows the user to choose how he wants to sort the list of computers
    void sortOptionsComputers();

    // promt user and takes an input
    string searchString();


/* -----notum þetta væntanlega ekki
    // allows the user to choose how he wants to sort the list
    void sortOption();-------------------------- hingað */

    // writes out the list to the screen with parameters
    void viewData(list<Scientist> aList);

    // writes out error message and takes in string of instructions.
    void errorMessage(string aString);

    // Allows the user to input new computer
    void inputComputer();

    // offers user to input another scientist, returns bool value.
    bool addAnother();

    // offers user to input another computer, returns bool value.
    bool addAnotherComputer();

    // prompts user and takes in name as a string and returns it
    string name();

    // prompts user and takes in gender as a string and returns it
    string gender();

    // prompts user and takes in year of birth as a int and returns it
    int birthYear();

    // prompts user and takes in year of death as a int and returns it
    int deathYear();

    // prompts user and takes in year built as a int and returns it
    int yearBuilt();

    // prompts user and takes in type as a string and returns it
    string type();

    // prompts user and takes in if the computer was built as a string and returns it
    bool wasItBuilt();

private:
    Service sci;
    ServiceComputer com;
    bool newWasItBuilt;
};

#endif // USERINTERFACE_H
