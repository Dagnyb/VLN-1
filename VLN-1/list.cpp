#include "list.h"

List::List()
{

}

anItem List::extract (string aString)
{
    int pos1 = 0;
    int pos2 = aString.find(';');
    int pos3 = aString.find(';', pos2 + 1);
    int pos4 = aString.find(';', pos3 + 1);

    string name = aString.substr(pos1, pos2);
    string gender = aString.substr(pos2+1, pos3-pos2-1);
    string bYear = aString.substr(pos3+1, pos4-pos2-1);
    string dYear = aString.substr(pos3+1, pos4-pos2-1);

    char birth [bYear.size()];
    for(int i = 0; i<bYear.size(); i++){
        birth[i] = bYear[i];
    }

    char death [dYear.size()];
    for(int i = 0; i<dYear.size(); i++){
        death[i]=dYear[i];
    }

    int birthYear = atoi(birth);
    int deathYear = atoi(death);

    anItem sciInfo (name, gender, birthYear, deathYear);

    //muna að taka út í endalegri útgáfu:
    cout << "prufa :" << sciInfo;
return sciInfo;
}
