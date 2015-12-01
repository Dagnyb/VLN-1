#ifndef LIST_H
#define LIST_H
#include "anitem.h"
#include <string>
#include <list>
#include <cstdlib>
#include <fstream>
using namespace std;


//string FILENAME = "prufaHrund.txt";


const string FILENAME = "prufaHrund.txt";
const int SIZEMAX = 30;

class List
{
public:
    List();
   // anItem search(list<anItem> list); // fall til að leita í listanum
    anItem extract (string aString);
    list<anItem> getList();
    void putList(list<anItem> inputList);
    void dataFromFile();
    list<anItem> sortListS();
    list<anItem> sortListR();

private:
    list <anItem> sciList;

};

#endif // LIST_H
