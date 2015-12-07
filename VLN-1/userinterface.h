#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <iostream>
#include <cstdlib>
#include <list>
#include <fstream>
#include <string>
#include "scientist.h"
#include "computer.h"
#include "service.h"

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

/* -----notum þetta væntanlega ekki
    // allows the user to choose how he wants to sort the list
    void sortOption();-------------------------- hingað */

    // writes out the list to the screen with parameters
    void viewData(list<Scientist> aList);

    // writes out error message and takes in string of instructions.
    void errorMessage(string aString);

    // offers user to input another scientist, returns bool walue.
    bool addAnother();

    // promts user and takes in name as a string and returns it
    string name();

    // promts user and takes in gender as a string and returns it
    string gender();

    // promts user and takes in year of birth s a int and returns it
    int birthYear();

    // promts user and takes in year of death s a int and returns it
    int deathYear();
private:
    Service sci;
};

#endif // USERINTERFACE_H
