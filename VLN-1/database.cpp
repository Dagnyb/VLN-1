#include "database.h"

Database::Database()
{
    /*db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);*/

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
    //QSqlQuery query(db);

    QSqlQuery q = db.exec("SELECT * FROM scientists");
    if(!q.lastError().isValid())
    {
        qDebug()<<"works!";
    }else qDebug() << "Failed, error: " <<q.lastError().text();

    db.close();


    //query.prepare ("SELECT * FROM computers"); // TEST
    //query.prepare ("SELECT * FROM computers c ORDER BY c.name "); // Sort computers by name Ascending
    //query.bindValue(":name", QString::fromStdString("%"));

/*    if( !query.exec() )
    {
        qDebug() << query.lastError().text();
    }
*/
    /*if(query.exec())
    {
        cout << "exec virkar" << endl;
    }else cout << "Not Working" << endl;
    */

   /* while(query.next())
    {
    int id = query.value(0).toInt();
    string name = query.value("Name").toString().toStdString();
    string gender = query.value ("Gender").toString().toStdString();
    int birth = query.value ("YearOfBirth").toInt();
    int death = query.value("YearOfDeath").toUInt();
    cout << id << name << gender << birth << death << endl;
    }
    db.close();*/
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


list <Scientist> Database::sortScientistsReverse()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    if(!db.open())
    {
        exit(1);
    }

    QSqlQuery query(db);

    query.prepare ("SELECT * FROM Scientists ORDER BY Name DESC");

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Scientist> result = list <Scientist>();
    result = databaseToScientistList(query);

    db.close();

    return result;
}



list <Scientist> Database::sortScientistsAlpabetically()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    if(!db.open())
    {
        exit(1);
    }

    QSqlQuery query(db);

    query.prepare ("SELECT * FROM Scientists ORDER BY Name");

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Scientist> result = list <Scientist>();
    result = databaseToScientistList(query);

    db.close();

    return result;
}

list <Computer> Database::sortComputer()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    if(!db.open())
    {
        exit(1);
    }

    QSqlQuery query(db);

    query.prepare ("SELECT * FROM Computers ORDER BY Name");

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Computer> result = list <Computer>();
    result = databaseToComputerList(query);

    db.close();

    return result;
}

list <Scientist> Database::databaseToScientistList(QSqlQuery& query)
{
    list <Scientist> result = list <Scientist>();

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

list <Computer> Database::databaseToComputerList(QSqlQuery& query)
{
    list <Computer> result = list <Computer>();

    while (query.next())
    {
        string name = query.value("Name").toString().toStdString();
        int yearBuild = query.value("YearBuilt").toInt();
        string type = query.value("Type").toString().toStdString();
        bool wasItBuild = query.value("WasItBuilt").toBool();

        Computer newLine(name, yearBuild, type, wasItBuild);
        result.push_back(newLine);
    }

    return result;
}
