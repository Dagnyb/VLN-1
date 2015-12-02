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
    List();
    list<anItem> findData(string name);
    void putList(list<anItem> inputList);
    void dataFromFile();
    anItem extract (string aString);
    list<anItem> getList();
    list<anItem> sortListS();
    list<anItem> sortListR();
    //bool sortlikethis(anItem a, anItem b);
private:
    list <anItem> sciList;
};

#endif // LIST_H
