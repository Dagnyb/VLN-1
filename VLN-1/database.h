#ifndef DATABASE_H
#define DATABASE_H

#include "scientist.h"
#include "computer.h"
#include "connected.h"
#include <string>
#include <Qstring>
#include <list>
#include <QtSql>
#include <cstdlib>

using namespace std;

class Database
{
public:

    Database();

    //heldur utan um tenginguna
    QSqlDatabase connectDatabase();

    list <Scientist> databaseToScientistList(QSqlQuery& query);

    list <Computer> databaseToComputerList(QSqlQuery& query);

    void add(Scientist);

    void addcomputer(Computer);

    list <Scientist> searchScientists(string inputFromUser);

    list <Computer> searchComputers(string inputFromUser);
    list <Scientist> sortScientistsAlpabetically();

    list <Scientist> sortScientistsReverse();

    void disconnectDatabase(QSqlDatabase database);

    list <Computer> sortComputer();

    list <Computer> sortComputersAsc();

    list <Computer> sortComputersDesc();

    list<Connected> AllScientistToComputer();

    list <Connected> databaseToAllScientistToComputer(QSqlQuery& query);

    list<Connected> ComputerToScientistId(string Id);

    list <Connected> databaseToComputerScientistlist(QSqlQuery& query);
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
