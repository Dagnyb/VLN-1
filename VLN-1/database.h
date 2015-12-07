#ifndef DATABASE_H
#define DATABASE_H
#include "scientist.h"
#include "computer.h"
//#include <QCoreApplication>
#include <iostream>
#include <string>
#include <list>
//#include <stdexcept>
//#include <QSqlQuery>
#include <QtSql>
#include <cstdlib>
//#include <QSql>

#include <iostream> // For testing purposes only
                    // TODO: Delete before final version

using namespace std;

class Database
{
public:
    Database();

    list <Scientist> databaseToScientistList(QSqlQuery& query);
    list <Computer> databaseToComputerList(QSqlQuery& query);

    void add(Scientist);
    void searchScientists(); // Search for scientists on database
    //void searchCompters(); // Search for computer in database
    list <Scientist> sortScientistsAlpabetically();
    list <Computer> sortComputer();


    void sortComputersAsc();
    //void sortComputersDesc();
private:
    QSqlDatabase db;

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
