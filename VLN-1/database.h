#ifndef DATABASE_H
#define DATABASE_H
#include "scientist.h"
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSql>
#include <iostream>
#include <string>
#include <stdexcept>
#include <QSqlQuery>
#include <QtSql>
#include "service.h"

using namespace std;
class Database
{
public:
    Database();
    void add(Scientist);
    void searchScientists(); // Search for scientists on database
    //void searchCompters(); // Search for computer in database
    void sortComputers();
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
