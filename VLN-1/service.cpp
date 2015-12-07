#include "service.h"


Service::Service()
{
   sciList = list <Scientist>();
   comList = list <Computer>();

}

list <Scientist> Service::getList()
{
    return sciList;
}
list <Computer> Service::getComputerList()
{
    return comList;
}
/*
void Service::putList(list <Scientist> inputList)
{
    sciList = inputList;
} */

void Service::dataFromFile()
{
    ifstream inStream;

    inStream.open(FILENAME.c_str());
        if (inStream.fail())
        {
            cout << "Input file opening fail.\n";
            exit(1);
        }

    string next = "";
    do{
        getline(inStream,next);
        Scientist info = extract(next);
        sciList.push_back(info);

    }while (inStream);

    inStream.close();

}

Scientist Service::extract (string aString)
{
    aString.c_str();
    char SYMBOL = ',';
    int pos1 = 0;
    size_t pos2 = aString.find(SYMBOL);
    size_t pos3 = aString.find(SYMBOL, pos2 + 1);
    size_t pos4 = aString.find(SYMBOL, pos3 + 1);

    string name = aString.substr(pos1, pos2);
    string gender = aString.substr(pos2+1, pos3-pos2-1);
    string bYear = aString.substr(pos3+1, pos4-pos2-1);
    string dYear = aString.substr(pos3+1, pos4-pos2-1); //eftir að laga

    bYear.c_str();
    dYear.c_str();

    /*char birth [bYear.size()];
    for(unsigned int i = 0; i<bYear.size(); i++){
        birth[i] = bYear[i];
    }

    char death [dYear.size()];
    for(unsigned int i = 0; i<dYear.size(); i++){
        death[i]=dYear[i];
    }
*/
    int birthYear = atoi(bYear.c_str());
    int deathYear = atoi(dYear.c_str());

    Scientist sciInfo (name, gender, birthYear, deathYear);

return sciInfo;
}

// Óþarfi fyrir database - notast með .txt skjali
/*bool sortlikethis(Scientist a, Scientist b)
{
    return a.getName() < b.getName();
}*/
/* ---- hætt að nota þetta -------
list <Scientist> Service::sortListS()
{
    list <Scientist> temp = sciList;
    temp = db.sortScientists();
    return temp;
}-------- hrund -------------------*/

// Óþarfi fyrir database - notast með .txt skjali
/*list <Computer> Service::sortListR()
{
    list <Computer> temp = comList;
    temp = db.sortComputer();
    return temp;
}*/

list <Scientist> Service::viewScientistAlphabetically()
{
    list <Scientist> temp = sciList;
    temp = db.sortScientistsAlpabetically();
    return temp;
}

list <Scientist> Service::viewScientistReverse()
{
    list <Scientist> temp = sciList;
    temp = db.sortScientistsReverse();
    return temp;
}

list <Scientist> Service::findData(string nameSearch)
{
    list <Scientist> temp = list <Scientist> ();
    list <Scientist>::iterator it;

    for(it = sciList.begin(); it != sciList.end(); it++)
    {
        if((*it).getName() == nameSearch)
        {
          temp.push_back(*it);
        }
    }
    return temp;
}





