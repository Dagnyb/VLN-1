#include <fstream>
#include <iostream>
#include "userinterface.h"
//#include "service.h"
//#include "scientist_.h"
#include "database.h" // Testing only
                      // TODO Delete before final version


using namespace std;

int main()
{

    Database db;
    db.sortComputersAsc();

    UserInterface ui;

    ui.initial();




    return 0;
}
