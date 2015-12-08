#include "database.h"

Database::Database()
{
   /* db = QSqlDatabase::addDatabase("QSQLITE");
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


void Database::addcomputer(Computer computer)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    db.open();
    QSqlQuery query(db);

    query.prepare("INSERT INTO Computers (Name, YearBuilt, Type, WasItBuilt) VALUES (:name, :year, :type, :built)");
    query.bindValue(":name",         QString::fromStdString(computer.getName()));
    query.bindValue(":year",         QString::number(computer.getYear()));
    query.bindValue(":type",         QString::fromStdString(computer.getType()));
    query.bindValue(":built",        QString::number(computer.getwasItBuilt()));
    query.exec();
}

list <Scientist> Database::searchScientists(string inputFromUser)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbScienc = "dbScience.sqlite";
    db.setDatabaseName(dbScienc);

    Database::Database();

    db.open();
    if(!db.open())
    {
        exit(1);
    }

    QSqlQuery query(db);

    query.prepare ("SELECT * FROM Scientists WHERE name LIKE '%'||:name||'%'");
    query.bindValue(":name", QString::fromStdString(inputFromUser));

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Scientist> result = list <Scientist>();
    result = databaseToScientistList(query);

    db.close();

    return result;
}

list <Computer> Database::searchComputers(string inputFromUser)
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

    query.prepare ("SELECT * FROM Computers WHERE name LIKE '%'||:name||'%'");
    query.bindValue(":name", QString::fromStdString(inputFromUser));

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Computer> result = list <Computer>();
    result = databaseToComputerList(query);

    db.close();

    return result;
}


list <Computer> Database::sortComputersAsc()
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

/*void sortComputersDesc()
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
