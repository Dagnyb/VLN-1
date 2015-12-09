#ifndef SERVICECOMPUTER_H
#define SERVICECOMPUTER_H
#include "computer.h"
#include "database.h"
#include <string>
#include <list>
#include <cstdlib>


using namespace std;

class ServiceComputer
{
    public:
        ServiceComputer();
        list <Computer> getComputerList();
        list <Computer> findDataComp(string nameSearch);
        list <Computer> findDataFull(string nameSearch);
        list <Computer> viewComputerAlphabetically();
        list <Computer> viewComputerReverse();
        void newComputer(Computer newComputer);
    private:
        list <Computer> comList;
        Database db;
};

#endif // SERVICECOMPUTER_H
