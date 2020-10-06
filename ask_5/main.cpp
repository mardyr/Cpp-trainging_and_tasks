#include <iostream>
/* Zaprojektuj klase/klasy, ktore dla kazdego domownika w twoim domu gromadzi informacje o stanie osobistej skarbonki
Klasa skarbonki ma zawierac kase i metody wkladania i wyjmowania kasy.
Klasa domownik ma zawierac dane osobowe i kase(jako polek lub odziedziczenie skarbonki)
Stworz tablice domownikow(obiekty klasy domownik)*/

using namespace std;
class piggyBank
{
    float money;
public:
    piggyBank(float =0);
    float putMoney(float); // put money to the bank
    float getMoney(float);   // get money from the bank
    float HowMuch();
};
class Householder : public piggyBank
{
    string name;
    int age;
public:
     Householder(string="Marcin",int=18);
     void SetData();

};
int main()
{
    Householder*people = new Householder[3];
    people ->SetData();
    cout<<"Payment "<<people -> putMoney(100)<<endl;
    cout <<"Pay out "<<people->getMoney(50)<<endl;
    cout<<"Money in the bank "<<people->HowMuch()<<endl;
    (people +1)->SetData();
    cout<<"Payment"<<(people+1)-> putMoney(500)<<endl;
    cout <<"Bank after pay out"<< (people+1)->getMoney(100)<<endl;
    cout<<"Money in the bank "<<(people+1)->HowMuch()<<endl;
    //piggyBank*a=new piggyBank(100);
    //cout << a->putMoney(20)<<endl;
    //cout<<  a->getMoney(80)<<endl;
    delete [] people;
    return 0;
}
//*********KONSTUKTOR*******************************/
piggyBank::piggyBank(float x)
{
    this->money =x;
}
Householder::Householder(string n,int a)
{
    this->name = n;this->age=a;

}
/********FUNKCJE CLASS MONEY********************/
float piggyBank::putMoney(float m)
{
    return this->money+=m;
}
float piggyBank::getMoney(float m)
{
    return this->money-=m;
}
float piggyBank::HowMuch()
{
    return this->money;
}
/*************************HOUSEHOLDER************/
void Householder::SetData()
{
    cout <<"Podaj imie i wiek ";
    cin >> this->name ; cin>> this->age;
    cout << this->name<<" Wiek: "<<this->age<<" Money in the bank: " << HowMuch() << endl;
}
