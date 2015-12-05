#ifndef DATABASE_H
#define DATABASE_H
#include "scientist.h"
#include <QCoreApplication>
#include <QtSql>
#include <string>
#include <iostream>


class Database
{
public:
    Database();
    void add(Scientist);
    //void searchScientists(); // Search for scientists on database
    //void searchCompters(); // Search for computer in database

private:

};


#endif // DATABASE_H
