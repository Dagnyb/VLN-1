#include "database.h"


Database::Database()
{/*
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = ".\dbScience.sqlite";
    db.setDatabaseName(dbScienc);
*/
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
{/*
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);
*/
    db.open();
    QSqlQuery query(db);

    query.prepare ("SELECT * FROM computers c ORDER BY c.name "); // Sort computers by name Ascending
    query.bindValue(":name","%" + QString::fromStdString("ae") + "%");
    query.exec();
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
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "hrund_db.sqlite";
    db.setDatabaseName(dbScienc);


    db.open();
    if(!db.open())
    {
        exit(1);
    }
    else cout <<"connection open\n";

    QSqlQuery query(db);
    string create = "INSERT INTO VALUES(Name, Gender, YearOfBirth, YearOfDeath)";
    query.exec(QString(create.c_str()));

    query.prepare ("SELECT * FROM Scientists ORDER BY Name"); // Sort scientists by name Ascending
  //  query.bindValue(":Name","%");
    /*
    query.prepare ("SELECT * FROM Scientists s ORDER BY s.name DESC"); // Sort scientists by name Descending
    query.bindValue(":name","%");
    */

    if (query.exec())//(query.exec())
    {
        cout << "exec works\n";
    }
    else
    {
        cout << "does not work\n";
        qDebug() << query.lastError().text();
    }
    list <Scientist> result = list<Scientist>();
    result = databaseToList(query);

    db.close();

    return result;

}
list <Scientist> Database::databaseToList(QSqlQuery& query)
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
