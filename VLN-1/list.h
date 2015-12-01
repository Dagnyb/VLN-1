#ifndef LIST_H
#define LIST_H
#include "anitem.h"
#include <string>
#include <list>
#include <cstdlib>
#include "userinterface.h"
using namespace std;


class List
{
public:
    List();
    void searchData(); // fall til að leita í listanum
    anItem extract (string aString);
    list<anItem> getList();


private:
    list <anItem> sciList;

};

#endif // LIST_H
