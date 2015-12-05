#include "database.h"

Database::Database()
{

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
