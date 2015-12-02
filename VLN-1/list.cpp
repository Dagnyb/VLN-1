#include "list.h"


List::List()
{
   sciList = list<anItem>();
}

list<anItem> List::getList()
{
    return sciList;
}
/*
void List::putList(list<anItem> inputList)
{
    sciList = inputList;
} */

void List::dataFromFile()
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

anItem List::extract (string aString)
{
    char SYMBOL = ',';
    int pos1 = 0;
    int pos2 = aString.find(SYMBOL);
    int pos3 = aString.find(SYMBOL, pos2 + 1);
    int pos4 = aString.find(SYMBOL, pos3 + 1);

    string name = aString.substr(pos1, pos2);
    string gender = aString.substr(pos2+1, pos3-pos2-1);
    string bYear = aString.substr(pos3+1, pos4-pos2-1);
    string dYear = aString.substr(pos3+1, pos4-pos2-1);

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

list<anItem> List::sortListS()
{
    list<anItem> temp = sciList;
    temp.sort(sortlikethis);

    return temp;
}

list<anItem> List::sortListR()
{
    list<anItem> temp = sciList;
   // temp.sort(sortlikethis);
    temp.reverse();

    return temp;
}

list<anItem> List::findData(string nameSearch)
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



