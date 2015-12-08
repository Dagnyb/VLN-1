#include "servicecomputer.h"

ServiceComputer::ServiceComputer()
{
   comList = list <Computer>();
}

list <Computer> ServiceComputer::getComputerList()
{
    return comList;
}

list <Computer> ServiceComputer::findDataComp(string nameSearch) // á að vera list <Computer> Service, eftir að breyta
{
    comList = db.searchComputers(nameSearch);

    return comList;
}
