#include <iostream>
#include "train.h"


Train::Train(std::string n,int year)
{
    this->imie = n;
    this->wiek = year;
}
void Train::sayName()
{
    std::cout<<"Imie: "<<this->imie<<" Wiek: "<<this->wiek<<std::endl;
}
