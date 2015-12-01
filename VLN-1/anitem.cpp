#include "anitem.h"


anItem::anItem(){}

anItem::anItem (string aName, string aGender, int aBirthYear, int aDeathYear) {
    name = aName;
    gender = aGender;
    birthYear = aBirthYear;
    deathYear = aDeathYear;
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
    outs << setw(30);
    outs.setf(ios::left);
    outs << anItem.name
         << anItem.gender << "\t"
         << anItem.birthYear << "\t"
         << anItem.deathYear
         << endl;
    return outs;
}
