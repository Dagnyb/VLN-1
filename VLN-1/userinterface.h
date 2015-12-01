#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <fstream>
using namespace std;



#include "anitem.h"


class UserInterface
{
public:
    UserInterface();
    void initial();
    void options();
    void inputData();
    void searchData();
    void viewData();
private:
    list <anItem> list;
};

#endif // USERINTERFACE_H
