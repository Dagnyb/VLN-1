#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <fstream>
#include <string>
#include "anitem.h"
#include "service.h"

using namespace std;


class UserInterface
{
public:
    UserInterface();
    void initial(); // the head of the output
    void options(); // allows the user to choose what to do
    void inputData(); // allows the user to choose what to do
    void searchData(); // search for name in List
    void viewData(); // writes list to screen without parameters
    void printList (list<anItem> aList); // prints out the list
    void sortOption(); // allows the user to choose how he wants to sort the list
    void viewData(list<anItem> aList); // writes out the list to the screen with parameters
    void errorMessage(string aString);
    bool addAnother();
    string name();
    string gender();
    int birthYear();
    int deathYear();
private:
    Service sci;
};

#endif // USERINTERFACE_H
