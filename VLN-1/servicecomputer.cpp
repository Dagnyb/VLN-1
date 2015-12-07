#include "servicecomputer.h"

ServiceComputer::ServiceComputer()
{
   comList = list <Computer>();
}

list <Computer> ServiceComputer::getComputerList()
{
    return comList;
}
