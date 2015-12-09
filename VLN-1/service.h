#ifndef SERVICE_H
#define SERVICE_H
#include "scientist.h"
#include "database.h"
#include <string>
#include <list>
#include <cstdlib>

using namespace std;

class Service
{
public:
     // Initializes the list
    Service();

     // instreams the .txt file
    void dataFromFile();

    void newScientist(Scientist newScientist);

     // returns input in sciList
    void putList(list <Scientist> inputList);

     // read from the txt file in string and converts two string to int
    Scientist extract (string aString);

    // Returns sciList
    list <Scientist> getList();

     // Allows the user to search in the list
    list <Scientist> findData(string name);

    list <Scientist> findDataFull(string nameSearch);

    //list <Computer> findDataComp(string nameSearch);
    list <Scientist> viewScientistReverse();

    list <Scientist> viewScientistAlphabetically();

    // Sorts the list in alphabetic order
    list <Scientist> sortListS();

     // Sorts the list in reverse alphabetic order
    list <Computer> sortListR();

private:

    list <Scientist> sciList;

    Database db;
};

#endif // SERVICE_H
