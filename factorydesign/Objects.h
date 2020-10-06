#pragma once

#include "Toy.h"

class Car : public Toy
{
public:
	void prepareParts();
	void combineParts();
	void assembleParts();
	void applyLabel();
	void showProduct();

};
class Bike : public Toy
{
public:
	void prepareParts();
	void combineParts();
	void assembleParts();
	void applyLabel();
	void showProduct();

};
class Plane : public Toy
{
public:
	void prepareParts();
	void combineParts();
	void assembleParts();
	void applyLabel();
	void showProduct();

};

