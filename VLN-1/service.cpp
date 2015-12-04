#include "service.h"


Service::Service()
{
   sciList = list<anItem>();
}

list<anItem> Service::getList()
{
    return sciList;
}
/*
void Service::putList(list<anItem> inputList)
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
        anItem info = extract(next);
        sciList.push_back(info);

    }while (inStream);

    inStream.close();

}

anItem Service::extract (string aString)
{
    char SYMBOL = ',';
    int pos1 = 0;
    int pos2 = aString.find(SYMBOL);
    int pos3 = aString.find(SYMBOL, pos2 + 1);
    int pos4 = aString.find(SYMBOL, pos3 + 1);

    string name = aString.substr(pos1, pos2);
    string gender = aString.substr(pos2+1, pos3-pos2-1);
    string bYear = aString.substr(pos3+1, pos4-pos2-1);
    string dYear = aString.substr(pos3+1, pos4-pos2-1); //eftir að laga

    char birth [bYear.size()];
    for(unsigned int i = 0; i<bYear.size(); i++){
        birth[i] = bYear[i];
    }

    char death [dYear.size()];
    for(unsigned int i = 0; i<dYear.size(); i++){
        death[i]=dYear[i];
    }

    int birthYear = atoi(birth);
    int deathYear = atoi(death);

    anItem sciInfo (name, gender, birthYear, deathYear);

return sciInfo;
}

bool sortlikethis(anItem a, anItem b)
{
    return a.getName() < b.getName();
}

list<anItem> Service::sortListS()
{
    list<anItem> temp = sciList;
    temp.sort(sortlikethis);

    return temp;
}

list<anItem> Service::sortListR()
{
    list<anItem> temp = sciList;
   // temp.sort(sortlikethis);
    temp.reverse();

    return temp;
}

list<anItem> Service::findData(string nameSearch)
{
    list<anItem> temp = list<anItem> ();
    list<anItem>::iterator it;

    for(it = sciList.begin(); it != sciList.end(); it++)
    {
        if((*it).getName() == nameSearch)
        {
          temp.push_back(*it);
        }
    return temp;
    }
}



