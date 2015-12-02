#ifndef LIST_H
#define LIST_H
#include "anitem.h"
#include <string>
#include <list>
#include <cstdlib>
#include <fstream>


using namespace std;


const string FILENAME = "prufaHrund.txt";


class List
{
public:
    List(); // Initializes the list
    void dataFromFile(); // instreams the .txt file
    void putList(list<anItem> inputList); // returns input in sciList
    anItem extract (string aString); // read from the txt file in string and converts two string to int
    list<anItem> getList(); // Returns sciList
    list<anItem> findData(string name); // Allows the user to search in the list
    list<anItem> sortListS(); // Sorts the list in alphabetic order
    list<anItem> sortListR(); // Sorts the list in reverse alphabetic order
    //bool sortlikethis(anItem a, anItem b);
private:
    list <anItem> sciList;
};

#endif // LIST_H
