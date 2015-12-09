#include "database.h"
#include <iostream> // TESTING ONLY

Database::Database()
{

}

QSqlDatabase Database::connectDatabase()
{
    QString dbScience = "dbScience.sqlite";
    QSqlDatabase db;

    if(QSqlDatabase::contains(dbScience))
    {
        db = QSqlDatabase::database(dbScience);
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE", dbScience);
        db.setDatabaseName(dbScience);

        db.open();
    }

    return db;
}

void Database::add(Scientist scientist)
{
    QSqlQuery query(connectDatabase());

    query.prepare("INSERT INTO Scientists (Name, Gender, YearOfBirth, YearOfDeath) VALUES (:Name, :Gender, :YearOfBirth, :YearOfDeath)");
    query.bindValue(":Name",         QString::fromStdString(scientist.getName()));
    query.bindValue(":Gender",       QString::fromStdString(scientist.getGender()));
    query.bindValue(":YearOfBirth",  QString::number(scientist.getBirthYear()));
    query.bindValue(":YearOfDeath",  QString::number(scientist.getDeathYear()));
    query.exec();
}

void Database::addComputer(Computer computer)
{
    QSqlQuery query(connectDatabase());

    query.prepare("INSERT INTO Computers (ComputersName, YearBuilt, Type, WasItBuilt) VALUES (:name, :year, :type, :built)");
    query.bindValue(":name",         QString::fromStdString(computer.getName()));
    query.bindValue(":year",         QString::number(computer.getYear()));
    query.bindValue(":type",         QString::fromStdString(computer.getType()));
    query.bindValue(":built",        QString::number(computer.getwasItBuilt()));
    query.exec();
}

list <Scientist> Database::searchScientists(string inputFromUser)
{
    QSqlQuery query(connectDatabase());

    query.prepare ("SELECT * FROM Scientists WHERE name LIKE '%'||:name||'%'");
    query.bindValue(":name", QString::fromStdString(inputFromUser));

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Scientist> result = list <Scientist>();
    result = databaseToScientistList(query);

    return result;
}

list <Computer> Database::searchComputers(string inputFromUser)
{
    QSqlQuery query(connectDatabase());

    query.prepare ("SELECT * FROM Computers WHERE ComputersName LIKE '%'||:name||'%'");
    query.bindValue(":name", QString::fromStdString(inputFromUser));

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Computer> result = list <Computer>();
    result = databaseToComputerList(query);

    return result;
}

list <Computer> Database::sortComputersAsc()
{
    QSqlQuery query(connectDatabase());

    query.prepare ("SELECT * FROM Computers ORDER BY LOWER(ComputersName), ComputersName");

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Computer> result = list <Computer>();
    result = databaseToComputerList(query);

    return result;
}

list <Computer> Database::sortComputersDesc()
{
    QSqlQuery query(connectDatabase());

    query.prepare ("SELECT * FROM Computers ORDER BY LOWER(ComputersName) DESC, ComputersName DESC");

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Computer> result = list <Computer>();
    result = databaseToComputerList(query);

    return result;
}

list <Scientist> Database::sortScientistsReverse()
{
    QSqlQuery query(connectDatabase());

    query.prepare ("SELECT * FROM Scientists ORDER BY Name DESC");

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Scientist> result = list <Scientist>();
    result = databaseToScientistList(query);

    return result;
}

list <Scientist> Database::sortScientistsAlpabetically()
{
    QSqlQuery query(connectDatabase());

    query.prepare ("SELECT * FROM Scientists ORDER BY Name");

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Scientist> result = list <Scientist>();
    result = databaseToScientistList(query);

    return result;
}

list <Computer> Database::sortComputer()
{
    QSqlQuery query(connectDatabase());

    query.prepare ("SELECT * FROM Computers ORDER BY ComputersName");

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Computer> result = list <Computer>();
    result = databaseToComputerList(query);

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
        string name = query.value("ComputersName").toString().toStdString();
        int yearBuild = query.value("YearBuilt").toInt();
        string type = query.value("Type").toString().toStdString();
        bool wasItBuild = query.value("WasItBuilt").toBool();

        Computer newLine(name, yearBuild, type, wasItBuild);
        result.push_back(newLine);
    }

    return result;
}

list <Connected> Database::AllScientistToComputer()
{
    QSqlQuery query(connectDatabase());

    query.prepare ("SELECT Scientists.Name, Computers.ComputersName FROM ScientistComputersConnect, Scientists, Computers WHERE ScientistComputersConnect.ScientistID = Scientists.Id AND ScientistComputersConnect.ComputersID = Computers.Id ORDER BY Scientists.Name");

    if (!query.exec())
    {
        qDebug() << query.lastError().text();

    }

    list <Connected> result = list <Connected>();
    result = databaseScientistToComputer(query);

    return result;
}

list <Connected> Database::databaseScientistToComputer(QSqlQuery& query)
{
    list <Connected> result = list <Connected>();

    while (query.next())
    {
        string SciName = query.value("Name").toString().toStdString();
        string CompName = query.value("ComputersName").toString().toStdString();

        Connected newLine(SciName, CompName);
        result.push_back(newLine);
    }

    return result;
}

list<Connected> Database::ComputerToScientistId(string Id)
{
    list<Connected> result = list<Connected>();

    QSqlQuery query(connectDatabase());

    query.prepare("SELECT * FROM Computers  "
                  "INNER JOIN ScientistComputersConnect, Scientists "
                  "ON ScientistComputersConnect.ScientistID = Scientists.Id "
                  "AND ScientistComputersConnect.ComputersID = Computers.Id "
                  "WHERE ScientistComputersConnect.ScientistID = :SciId "
                  "ORDER BY Scientists.Name" );

    query.bindValue(":SciId", QString::fromStdString(Id));

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    query.exec();

    result = databaseToComputerScientistlist (query);

    return result;
}

list <Connected> Database::databaseToComputerScientistlist(QSqlQuery& query)
{
    list <Connected> result = list <Connected>();

    while (query.next())
    {
        string SciName = query.value("Scientists.Name").toString().toStdString();
        string CompName = query.value("Computers.Name").toString().toStdString();

        Connected newLine(SciName, CompName);
        result.push_back(newLine);
    }

    return result;
}

list <Scientist> Database::searchScientistsId(string inputFromUser)
{
    QSqlQuery query(connectDatabase());

    query.prepare ("SELECT * FROM Scientists WHERE name LIKE :name");
    query.bindValue(":name", QString::fromStdString(inputFromUser));

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Scientist> result = list <Scientist>();
    result = databaseToScientistList(query);

    return result;
}

int Database::ScientistId(string inputFromUser)
{
    QSqlQuery query(connectDatabase());

    query.prepare ("SELECT Id FROM Scientists WHERE Name LIKE :name");
    query.bindValue(":name", QString::fromStdString(inputFromUser));

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    int sciId = query.value("Scientists.Id").toInt();

    return sciId;
}

list <Computer> Database::searchComputerId(string inputFromUser)
{
    QSqlQuery query(connectDatabase());

    query.prepare ("SELECT * FROM Computers WHERE ComputersName LIKE :name");
    query.bindValue(":name", QString::fromStdString(inputFromUser));

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    list <Computer> result = list <Computer>();
    result = databaseToComputerList(query);

    return result;
}

int Database::ComputerId(string inputFromUser)
{
    QSqlQuery query(connectDatabase());

    query.prepare ("SELECT Id FROM Computers WHERE ComputersName LIKE :name");
    query.bindValue(":name", QString::fromStdString(inputFromUser));

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    int comId = query.value("Computers.Id").toInt();

    return comId;
}

bool Database::conncetScientistToComputer(Connected newCon)
{
    bool result;

    string sciName = newCon.getNameOne();
    string comName = newCon.getNameTwo();

    int sciId = ScientistId(sciName);
    cout << "integerinn sci " << sciId;
    int comId = ScientistId(comName);
    cout << "integerinn com" << comId;

    QSqlQuery query(connectDatabase());

    query.prepare ("INSERT INTO ScientistComputersConnect VALUES(:sciId, :comId)");
    query.bindValue(":sciId", QString::number(sciId));
    query.bindValue(":comId", QString::number(comId));

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
        result = false;
    }

    return result;
}
