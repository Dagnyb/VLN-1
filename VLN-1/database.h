#ifndef DATABASE_H
#define DATABASE_H
#include "scientist.h"
#include "computer.h"
#include "connected.h"

//#include <QCoreApplication>
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
    void addcomputer(Computer);
    list <Scientist> searchScientists();
    list <Scientist> sortScientistsAlpabetically();
    list <Scientist> sortScientistsReverse();

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
