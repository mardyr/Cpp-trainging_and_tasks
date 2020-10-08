#define _USE_MATH_DEFINES
#include "Sphere.h"
#include <iostream>
#include <cmath>


Sphere::Sphere(double r_) : r{ r_ } {}

void Sphere::enterData()
{
	std::cout << "Podaj dlugosc promienia kuli: ";
	std::cin >> r;
}

void Sphere::showLength()
{
	std::cout << "Dlugosc promienia kuli wynosi: " << r << std::endl;
}

double Sphere::calculateCapacity()
{
	
	return (4 * M_PI * r * r * r)/3 ;
}

double Sphere::calculateArea()
{
	return 4 * M_PI * r * r;
}

void Sphere::showCalculatedInfo()
{
	std::cout << "Objetosc kuli wynosi: " << this->calculateCapacity() << " a jej powierzchnia calkowita to : " << this->calculateArea() << std::endl;
}

Sphere::~Sphere(){}
