#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <fstream>
#include <string>
#include "anitem.h"
#include "list.h"

using namespace std;


class UserInterface
{
public:
    UserInterface();
    void initial();
    void options();
    void inputData();
    void searchData();
    void viewData();
    void printList (list<anItem> aList);
    void sortOption();
    //takes an list and prints it out
    void viewData(list<anItem> aList);
private:
    //List sci;
};

#endif // USERINTERFACE_H
