#include "Cuboid.h"
#include <iostream>

Cuboid::Cuboid(double a_, double b_, double c_) : a{ a_ }, b{ b_ }, c{ c_ } {}

Cuboid::~Cuboid(){}

void Cuboid::enterData()
{
	std::cout << "Podaj krawedzie prostopadloscianu: [a/b/ c-wysokosc]: ";
	std::cin >> a >> b >> c;
}

void Cuboid::showLength()
{
	std::cout << "Dlugosc krawedzi podstawy: " << a <<" i " << b << ", a wysokosc " << c << std::endl;
}

double Cuboid::calculateCapacity()
{
	return a * b * c;
}

double Cuboid::calculateArea()
{
	return 2 * a * b + 2 * a * c + 2 * b * c;
}

void Cuboid::showCalculatedInfo()
{
	std::cout << "Objetosc prostopadloscianu wynosi: " << this->calculateCapacity() << " a jego powierzchnia calkowita to : " << this->calculateArea() << std::endl;
}
