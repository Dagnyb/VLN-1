#include "servicecomputer.h"

ServiceComputer::ServiceComputer()
{
   comList = list <Computer>();
}

list <Computer> ServiceComputer::getComputerList()
{
    return comList;
}

list <Computer> ServiceComputer::findDataComp(string nameSearch)
{
    comList = db.searchComputers(nameSearch);

    return comList;
}

list <Computer> ServiceComputer::viewComputerAlphabetically()
{
    comList = db.sortComputersAsc();

    return comList;
}

list <Computer> ServiceComputer::viewComputerReverse()
{
    comList = db.sortComputersDesc();

    return comList;
}

void ServiceComputer::newComputer(Computer newComputer)
{
    db.add(newComputer);
}
