#include "Pyramid.h"
#include <iostream>

Pyramid::Pyramid(double a_, double h_, double H_) : a{ a }, h{ h_ }, H{ H_ }{}

Pyramid::~Pyramid(){}

void Pyramid::enterData()
{
	std::cout<<"Podaj dlugosc krawedzi podstawy, wysokosc sciany bocznej oraz wysokosc ostroslupa: ";
	std::cin >> a >> h >> H ;
}

void Pyramid::showLength()
{
	std::cout << "Dlugosc krawedzi podstawy " << a << " wysokosci sciany bocznej " << h << " wysokosci ostroslupa " << H << std::endl;
}

double Pyramid::calculateCapacity()
{
	return (a * a * H)/3;
}

double Pyramid::calculateArea()
{
	return a * a + 2 * a * h;
}

void Pyramid::showCalculatedInfo()
{
	std::cout << "Objetosc ostroslupu prawidlowego czworokatnego wynosi: " << this->calculateCapacity() << " a jego powierzchnia calkowita to : " << this->calculateArea() << std::endl;

}
