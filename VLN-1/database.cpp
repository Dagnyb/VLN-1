#include "database.h"

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
<<<<<<< HEAD
/*Database::Database()

=======

Database::Database()
>>>>>>> 848c5228c8899697e0afec387a334a7e54ce915c
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    QSqlQuery query(db);

<<<<<<< HEAD
    // þetta keyrir fínt en þetta var bara prufa en vil ekki henta
   string queryInsert = "INSERT INTO Sientict VALUES (30, 'Halla Palla', 'female', 1980, 0)";
=======
    string queryInsert = "INSERT INTO Sientict VALUES (30, 'Halla Palla', 'female', 1980, 0)";
>>>>>>> 848c5228c8899697e0afec387a334a7e54ce915c
    query.exec(QString(queryInsert.c_str()));

}

   query.prepare("INSERT INTO Scientists (Name, Gender, YearOfBirth, YearOfDeath) VALUES (:Name, :Gender, :YearOfBirth, :YearOfDeath)");
   query.bindValue(":Name",         QString::fromStdString(Scientist.getName()));
   query.bindValue(":Gender",       QString::fromStdString(Scientist.getGender()));
   query.bindValue(":YearOfBirth",  QString::fromStdString(Scientist.getBirthYear()));
   query.bindValue(":YearOfDeath",  QString::fromStdString(Scientist.getDeathYear()));

=======

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
>>>>>>> 85f06a44306517eb37aa2c6e2387a52f6cd78b2c
    query.exec();
}

<<<<<<< HEAD

<<<<<<< HEAD
}
=======







>>>>>>> 85f06a44306517eb37aa2c6e2387a52f6cd78b2c

=======
>>>>>>> 848c5228c8899697e0afec387a334a7e54ce915c
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
<<<<<<< HEAD
}
*/

/*
void sortComputers()
{
    QSqlDatabase SciDatabase;
    QSqlQuery query(SciDatabase);
    query.sortNameAsc ("SELECT * FROM computers c ORDER BY c.name "); // Sort computers by name Ascending
    query.sortNameDesc ("SELECT * FROM computers c ORDER BY c.name DESC"); // Sort computers by name Descending
}*/

/*
void sortScientists()
{
    QSqlDatabase SciDatabase;
    QSqlQuery query(SciDatabase);
    query.sortNameAsc ("SELECT * FROM Scientists s ORDER BY s.name "); // Sort scientists by name Ascending
    query.sortNameDesc ("SELECT * FROM Scientists s ORDER BY s.name DESC"); // Sort scientists by name Descending
}*/
=======
}*/

>>>>>>> 848c5228c8899697e0afec387a334a7e54ce915c
