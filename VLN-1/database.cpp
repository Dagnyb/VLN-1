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

