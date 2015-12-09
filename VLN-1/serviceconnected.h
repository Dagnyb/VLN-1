#ifndef SERVICECONNECTED_H
#define SERVICECONNECTED_H

#include "connected.h"
#include "database.h"
#include <string>
#include <list>
#include <cstdlib>

using namespace std;

class ServiceConnected
{
    public:
        ServiceConnected();
        list <Connected> getConection();
        list <Connected> findConnectons(string stringSearch);
        list <Connected> viewSciToCom();
        bool connectSciToCom(Connected newConnection);

    private:
        list <Connected> conList;
        Database db;
};

#endif // SERVICECONNECTED_H
