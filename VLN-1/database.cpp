#include "database.h"
#include <QtSql/QSql>
#include "string"
#include <iostream>
#include <string>
#include <stdexcept>
#include <bits/stringfwd.h>
#include <QtSql>
#include <QtSql/QSqlDatabase>


using namespace std;
Database::Database()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    QSqlQuery query(db);

    // þetta keyrir fínt en þetta var bara prufa en vil ekki henta
   /* string queryInsert = "INSERT INTO Sientict VALUES (30, 'Halla Palla', 'female', 1980, 0)";
    query.exec(QString(queryInsert.c_str()));*/

    //þetta er ég að laga
    /*
   query.prepare("INSERT INTO Scientists (Name, Gender, YearOfBirth, YearOfDeath) VALUES (:Name, :Gender, :YearOfBirth, :YearOfDeath)");
   query.bindValue(":Name",         QString::fromStdString(Scientist.getName()));
   query.bindValue(":Gender",       QString::fromStdString(Scientist.getGender()));
   query.bindValue(":YearOfBirth",  QString::fromStdString(Scientist.getBirthYear()));
   query.bindValue(":YearOfDeath",  QString::fromStdString(Scientist.getDeathYear()));

*/
    query.exec();








}

/*void searchScientists()
{
    QSqlDatabase SciDatabase;
    QSqlQuery query(SciDatabase);
    //Setja inn fall sem les inn töfluna
    query.searchId ("SELECT * FROM Scientists WHERE ID LIKE inputId") // Search by ID
    query.searchName ("SELECT * FROM Scientists WHERE Name LIKE inputName") // Search by name
    query.searchGender ("SELECT * FROM Scientists WHERE Gender LIKE inputGender") // Search by gender
    query.searchYearOfBirth ("SELECT * FROM Scientists WHERE YearOfBirth LIKE inputYearOfBirth") // Search by year of birth
    query.searchYearOfDeath ("SELECT * FROM Scientists WHERE YearOfDeath LIKE inputYearOfDeath") // Search by year of death

}

void searchComputers()
{
    QSqlDatabase SciDatabase;
    QSqlQuery query(SciDatabase);
    //Setja inn fall sem les inn töfluna
    query.searchId ("SELECT * FROM Computers WHERE ID LIKE inputId") // Search by ID
    query.searchName ("SELECT * FROM Computers WHERE Name LIKE inputName") // Search by name
    query.searchYearBuilt ("SELECT * FROM Computers WHERE YearBuilt LIKE inputYearBuilt") // Search by year built
    query.searchType ("SELECT * FROM Computers WHERE Type LIKE inputType") // Search by type
    query.searchWasItBuilt ("SELECT * FROM Computers WHERE WasItBuilt LIKE inputWasItBuilt") // Search by was it built
}
*/
