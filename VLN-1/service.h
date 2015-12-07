#ifndef SERVICE_H
#define SERVICE_H
#include "scientist.h"
#include "database.h"
#include <string>
#include <list>
#include <cstdlib>
#include <fstream>


using namespace std;


const string FILENAME = "prufaHrund.txt";


class Service
{
public:
    Service(); // Initializes the list
    void dataFromFile(); // instreams the .txt file
    void putList(list <Scientist> inputList); // returns input in sciList
    Scientist extract (string aString); // read from the txt file in string and converts two string to int
    list <Scientist> getList(); // Returns sciList
    list <Computer> getComputerList();
    list <Scientist> findData(string name); // Allows the user to search in the list

    list <Scientist> viewScientistAlphabetically();
    list <Scientist> sortListS(); // Sorts the list in alphabetic order
    list <Computer> sortListR()
    ; // Sorts the list in reverse alphabetic order
    //bool sortlikethis(Scientist a, Scientist b);
private:
    list <Scientist> sciList;
    list <Computer> comList;

    Database db;
};

#endif // SERVICE_H
