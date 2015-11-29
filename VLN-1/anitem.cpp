#include "anitem.h"


anItem::anItem (string aName, string aGender, int aBirthYear, int aDeathYear) {
    name = aName;
    gender = aGender;
    birthYear = aBirthYear;
    deathYear = aDeathYear;
}
anItem::anItem(string aName, string aGender, int aBirthYear){
    name = aName;
    gender = aGender;
    birthYear = aBirthYear;
    deathYear = 0;
}

string anItem::getName() const {
    return name;
}

string anItem::getGender() const {
    return gender;
}

int anItem::getBirthYear() const {
    return birthYear;
}

int anItem::getDeathYear() const {
    return deathYear;
}
ostream& operator << (ostream& outs, const anItem& anItem) {
    outs << anItem.name << "\t"
         << anItem.gender << "\t"
         << anItem.birthYear << "\t"
         << anItem.deathYear << "\t"
         << endl;
    return outs;
}
