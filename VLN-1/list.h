#ifndef LIST_H
#define LIST_H
#include "anitem.h"
#include <string>
#include <list>
#include <cstdlib>


using namespace std;


class List
{
public:
    List();
    anItem extract (string aString);
private:
    list <anItem> sciList;
};

#endif // LIST_H