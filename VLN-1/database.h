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

    void add(Scientist);

    void addComputer(Computer);

    void disconnectDatabase(QSqlDatabase database);

    //heldur utan um tenginguna
    QSqlDatabase connectDatabase();

    list <Scientist> databaseToScientistList(QSqlQuery& query);

    list <Computer> databaseToComputerList(QSqlQuery& query);

    list <Scientist> searchScientists(string inputFromUser);

    list <Computer> searchComputers(string inputFromUser);

    list <Scientist> sortScientistsAlpabetically();

    list <Scientist> sortScientistsReverse();

    list <Computer> sortComputer();

    list <Computer> sortComputersAsc();

    list <Computer> sortComputersDesc();

    list<Connected> AllScientistToComputer();

    list <Connected> databaseScientistToComputer(QSqlQuery& query);

    list<Connected> ComputerToScientistId(string Id);

    list <Connected> databaseToComputerScientistlist(QSqlQuery& query);

    list <Scientist> searchScientistsId(string inputFromUser);

    list <Scientist> databaseToScientistIdList(QSqlQuery& query);

    list<Connected> searchComputerToScientistId(QSqlQuery& query );

    list <Computer> searchComputerId(string inputFromUser);

    list <Connected> databaseScientistIdToComputer(QSqlQuery& query);

    bool conncetScientistToComputer(Connected newCon);

    int ComputerId(string inputFromUser);

    int ScientistId(string inputFromUser);

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
