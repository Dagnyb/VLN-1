#include "database.h"


Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);
}


void Database::add(Scientist scientist)
{/*
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);
*/
    db.open();
    QSqlQuery query(db);

    query.prepare("INSERT INTO Scientists (Name, Gender, YearOfBirth, YearOfDeath) VALUES (:Name, :Gender, :YearOfBirth, :YearOfDeath)");
    query.bindValue(":Name",         QString::fromStdString(scientist.getName()));
    query.bindValue(":Gender",       QString::fromStdString(scientist.getGender()));
    query.bindValue(":YearOfBirth",  QString::number(scientist.getBirthYear()));
    query.bindValue(":YearOfDeath",  QString::number(scientist.getDeathYear()));
    query.exec();
}

void Database::searchScientists()
{


    db.open();
    QSqlQuery query(db);

    query.prepare("SELECT * FROM Scientists WHERE name LIKE '%'||:name||'%'");
    query.bindValue(":name", QString::fromStdString("inputFromUser"));
}

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


void Database::sortComputersAsc()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    QSqlQuery query(db);

   /* query.prepare ("SELECT * FROM computers c ORDER BY c.name "); // Sort computers by name Ascending
    query.bindValue(":name","%" + QString::fromStdString("ae") + "%");
    query.exec();*/

    string name = query.value("Name").toString().toStdString();
    cout << name << endl;
}

/*void sortComputersDesc()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    QSqlQuery query(db);

    query.prepare ("SELECT * FROM computers c ORDER BY c.name DESC"); // Sort computers by name Descending
    query.bindValue(":name","%");
    query.exec();
}*/

list <Scientist> Database::sortScientists()
{
    /*
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);
    */
    db.open();

    QSqlQuery query(db);
    /*
    query.prepare ("SELECT * FROM scientists s ORDER BY s.name "); // Sort scientists by name Ascending
    query.bindValue(":name","%");
    query.prepare ("SELECT * FROM scientists s ORDER BY c.name DESC"); // Sort scientists by name Descending
    query.bindValue(":name","%");
    */

    query.exec("SELECT * FROM scientists");
    list <Scientist> result = list<Scientist>();
    result = databaseToList(query);

    return result;

}
list <Scientist> Database::databaseToList(QSqlQuery query)
{
    list <Scientist> result = list<Scientist>();

    while (query.next())
    {
        string name = query.value("Name").toString().toStdString();
        string gender = query.value("Gender").toString().toStdString();
        int birthYear = query.value("YearOfBirth").toInt();
        int deathYear = query.value("YearOfDeath").toInt();

        Scientist newLine(name, gender, birthYear, deathYear);
        result.push_back(newLine);
    }

    return result;
}
