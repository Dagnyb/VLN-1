#ifndef DATABASE_H
#define DATABASE_H
#include "scientist.h"
#include <QCoreApplication>
#include <iostream>
#include <string>
#include <stdexcept>
#include <QSqlQuery>
#include <QtSql>


using namespace std;
class Database
{
public:
    Database();
    void add(Scientist);
    void searchScientists(); // Search for scientists on database
    //void searchCompters(); // Search for computer in database
    void sortComputersAsc();
    //void sortComputersDesc();
    //void sortScientists();
private:
    string searchId;
    string searchName;
    string searchGender;
    string searchYearOfBirth;
    string searchYearOfDeath;
    string searchYearBuilt;
    string searchType;
    string searchWasItBuilt;
};


#endif // DATABASE_H
