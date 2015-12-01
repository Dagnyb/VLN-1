#ifndef LIST_H
#define LIST_H
#include "anitem.h"
#include <string>
#include <list>
#include <cstdlib>
#include <fstream>
#include "userinterface.h"

using namespace std;


const string FILENAME = "prufaHrund.txt";


class List
{
public:
    List();
    void findData();
    void putList(list<anItem> inputList);
    void dataFromFile();
    anItem extract (string aString);
    list<anItem> getList();
    list<anItem> sortListS();
    list<anItem> sortListR();
private:
    list <anItem> sciList;

};

#endif // LIST_H
