#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <fstream>
#include "anitem.h"

using namespace std;

class UserInterface
{
public:
    UserInterface();
    void initial();
    void options();
    void inputData();
    void searchData();
    void viewData(list<anItem> aList);
private:
    list<anItem> sciList;
};

#endif // USERINTERFACE_H
