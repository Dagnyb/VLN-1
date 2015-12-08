#include "scientist.h"


Scientist::Scientist()
{

}

Scientist::Scientist (string aName, string aGender, int aBirthYear, int aDeathYear)
{
    name = aName;
    gender = aGender;
    birthYear = aBirthYear;
    deathYear = aDeathYear;
}

string Scientist::getName() const
{
    return name;
}

string Scientist::getGender() const
{
    return gender;
}

int Scientist::getBirthYear() const
{
    return birthYear;
}

int Scientist::getDeathYear() const
{
    return deathYear;
}
ostream& operator << (ostream& outs, const Scientist& Scientist)
{
    outs << setw(30);
    outs.setf(ios::left);
    outs << Scientist.name
         << Scientist.gender << "\t"
         << Scientist.birthYear << "\t" ;
         if(Scientist.deathYear == 0)
         {
            outs << " " << endl;
         }
         else

          outs  << Scientist.deathYear // ef núll þá prentast ekkert
         << endl;
    return outs;
}
