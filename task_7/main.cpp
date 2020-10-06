#include <iostream>

using namespace std;

class Istota
{
   int wiek;
   string pochodzenie;
public:
    string imie;
    Istota(int=15,string="Chiny",string="Noname");
    void setAge(int);
};
class Ssak : public Istota
{
    float temperature;
    string birth_type;
public:
    Ssak(int=15,string="Chiny",string="Noname",float=36.6);
    void setAge(float,string);

};
class Pies : private Ssak
{
    float height,weight;
    string color;
public:
    Pies(int age=10,string kraj="Niemcy",string imie="Hau",float temp=36.7,float=0.7,float=0.5,string ="brown");
    void getInformation();
};
class Rasa : public Pies
{
    string lineage;
    string pochodzenie;
    float money;
public:
    Rasa(string,string,float);
    void Info();

};
int main()
{
    Pies p;
    p.getInformation();
    return 0;
}
/*****************KLASA ISTOTA*****************/
Istota::Istota(int age,string kraj,string imie)
{
    this->wiek = age;this->pochodzenie=kraj;this->imie = imie;

}
void Istota::setAge(int a)
{
    this->wiek=a;
}
/*****************KLASA SSAK*****************/
Ssak::Ssak(int age,string kraj,string imie,float temp) : Istota(wiek,pochodzenie,imie)
{
    this->temperature=temp;

}
void Ssak::setAge(int age,string n)
{
    this->wiek = setAge(age); this->imie = n;
    cout << "Ssak o imieniu "<<this->imie << "ma lat "<<this->wiek<<endl;
}
/*****************KLASA PIES*****************/
Pies::Pies(int age,string kraj,string imie,float temp,float height,float weight,string color): Ssak(temp)
{
    this->height = height; this->weight = weight; this->color = color;

}
void Pies::getInformation()
{
    cout<<this->setAge(15,"LOL")<< endl;
}


