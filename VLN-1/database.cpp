#include "database.h"
#include <iostream> // For testing purposes only
                    // TODO: Delete before final version

using namespace std;

bool Connection()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    QSqlQuery query(db);

    if(!db.isOpen()){
       throw std::runtime_error("Failed to open database");
    }
    return true;
}

Database::Database()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    QSqlQuery query(db);

    string queryInsert = "INSERT INTO Scientists VALUES (30, 'Halla Palla', 'female', 1980, 0)";
    query.exec(QString(queryInsert.c_str()));

}

void Database::add(Scientist scientist)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    QSqlQuery query(db);

    query.prepare("INSERT INTO Scientists (Name, Gender, YearOfBirth, YearOfDeath) VALUES (:Name, :Gender, :YearOfBirth, :YearOfDeath)");
    query.bindValue(":Name",         QString::fromStdString(scientist.getName()));
    query.bindValue(":Gender",       QString::fromStdString(scientist.getGender()));
    query.bindValue(":YearOfBirth",  QString::number(scientist.getBirthYear()));
    query.bindValue(":YearOfDeath",  QString::number(scientist.getDeathYear()));
    query.exec();
}

/*void searchScientists()
{
    QSqlDatabase SciDatabase;
    SciDatabase = QSqlDatabase::addDatabase("QSQLITE"); //lætur vita hvaða
    QString SciDatabaseName = "dbScience.sqlite";
    SciDatabase.setDataBaseName(SciDatabaseName);

    SciDatabase.open();

    QSqlQuery query(SciDatabase);
    //Setja inn fall sem les inn töfluna
    query.searchId ("SELECT * FROM Scientists WHERE ID LIKE %inputId") // Search by ID
    query.searchName ("SELECT * FROM Scientists WHERE Name LIKE %inputName") // Search by name
    query.searchGender ("SELECT * FROM Scientists WHERE Gender LIKE %inputGender") // Search by gender
    query.searchYearOfBirth ("SELECT * FROM Scientists WHERE YearOfBirth LIKE %inputYearOfBirth") // Search by year of birth
    query.searchYearOfDeath ("SELECT * FROM Scientists WHERE YearOfDeath LIKE %inputYearOfDeath") // Search by year of death

}*/

/*void searchComputers()
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


void sortComputers()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    QSqlQuery query(db);

    query.prepare ("SELECT * FROM computers c ORDER BY c.name "); // Sort computers by name Ascending
    query.bindValue(":name","%");
    query.prepare ("SELECT * FROM computers c ORDER BY c.name DESC"); // Sort computers by name Descending
    query.bindValue(":name","%");
}


void sortScientists()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    QSqlQuery query(db);

    query.prepare ("SELECT * FROM scientists s ORDER BY s.name "); // Sort scientists by name Ascending
    query.bindValue(":name","%");
    query.prepare ("SELECT * FROM scientists s ORDER BY c.name DESC"); // Sort scientists by name Descending
    query.bindValue(":name","%");
}

