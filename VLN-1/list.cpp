#include "list.h"

List::List()
{
    list<anItem> sciList = list<anItem>();
}
list<anItem> List::getList()
{
    return sciList;
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


    //muna að taka út í endalegri útgáfu:
    cout << "prufa :" << sciInfo;
return sciInfo;
}

void List::searchData()
{
        string nameSearch;
        UserInterface obj;

        list<anItem>::iterator it;

        cout << "Please enter the name of scientist you wish to find: ";
        cin.sync();
        getline(cin, nameSearch);

        for(it = sciList.begin(); it != sciList.end(); it++)
        {
            if((*it).getName() == nameSearch)
            {
                cout << "print fallið" << endl;
            }
                else
                {
                    cout << "Scientist not found\n";

                    char ans;

                    cout << "Do want to try again? Y/N ";
                    cin >> ans;

                    if(ans=='Y' || ans=='y')
                    {
                        searchData();
                    }
                    else if (ans=='N' || ans=='n')
                    {
                         obj.options();
                    }
                    else
                    {
                        cout << "Sorry this was invalid input. You will be directed to the main menu";
                        cout << endl << endl;
                        obj.options();
                    }
                }

         }
}


