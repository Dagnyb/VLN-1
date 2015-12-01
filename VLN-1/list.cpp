#include "list.h"


List::List()
{
   list<anItem> sciList = list<anItem>();
}

list<anItem> List::getList()
{
    return sciList;
}

void List::putList(list<anItem> inputList)
{
    sciList = inputList;
}

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


list<anItem> List::sortListS()
{
   // list<anItem>::iterator a = sciList.begin();
    //sciList.sort();

    return sciList;
}

list<anItem> List::sortListR()
{
  //  anItem item1;
  //  anItem item2;
   //list<anItem>::iterator a = sciList.begin();
 //  sciList.sort(anItem, string.CASE_INSENSITIVE_ORDER);
  // sciList.reverse();

    return sciList;

}
//anItem List::search(list<anItem> list)

void List::findData()
{

        string nameSearch;
        UserInterface obj;
        obj.printList(sciList);
        cout << "virkar";
        list<anItem>::iterator it;

        cout << "Please enter the name of scientist you wish to find: ";
        cin.sync();
        getline(cin, nameSearch);

        for(it = sciList.begin(); it != sciList.end(); it++)
        {
            if((*it).getName() == nameSearch)
            {

                cout << *it;
                cout << endl;

            }
                else
                {
                    cout << "Scientist not found\n";

                    char ans;

                    cout << "Do want to try again? Y/N ";
                    cin >> ans;

                    if(ans=='Y' || ans=='y')
                    {
                        findData();
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



