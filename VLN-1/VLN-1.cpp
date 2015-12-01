#include <fstream>
#include <iostream>
#include "userinterface.h"
#include "anitem.h"
#include "list.h"




using namespace std;

int main()
{
    UserInterface ui;

    ui.initial();
    ui.options();
    /*
    //henda þessu út//
        anItem prufa1("hrund","kona",1975,2100);
        anItem prufa2("Matti","madur",1973,2100);

        list<anItem> a = list<anItem>();

        a.push_back(prufa1);
        a.push_back(prufa2);
    //hingað//
    ui.viewData(a);

    */


    return 0;
}

