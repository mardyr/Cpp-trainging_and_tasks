#include "Objects.h"
#include <iostream>

void Car::prepareParts() { std::cout << "Preparing Car Parts\n"; }
void Car::combineParts() { std::cout << "Combining Car Parts\n"; }
void Car::assembleParts() { std::cout << "Assembling Car Parts\n"; }
void Car::applyLabel() { std::cout << "Assemble Parts\n"; name = "Car"; price = 10; }
void Car::showProduct() { std::cout << "Name: " << name << std::endl << "Price: " << price << std::endl; }


void Plane::prepareParts() { std::cout << "Preparing Plane Parts\n"; }
void Plane::combineParts() { std::cout << "Combining Plane Parts\n"; }
void Plane::assembleParts() { std::cout << "Assembling Plane Parts\n"; }
void Plane::applyLabel() { std::cout << "Assemble Parts\n"; name = "Plane"; price = 20; }
void Plane::showProduct() { std::cout << "Name: " << name << std::endl << "Price: " << price << std::endl; }

void Bike::prepareParts() { std::cout << "Preparing Bike Parts\n"; }
void Bike::combineParts() { std::cout << "Combining Bike Parts\n"; }
void Bike::assembleParts() { std::cout << "Assembling Bike Parts\n"; }
void Bike::applyLabel() { std::cout << "Assemble Parts\n"; name = "Bike"; price = 30; }
void Bike::showProduct() { std::cout << "Name: " << name << std::endl << "Price: " << price << std::endl; }


