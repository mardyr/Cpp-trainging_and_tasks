#include "ToyFactory.h"
#include "Objects.h"
#include "Toy.h"
#include <iostream>

Toy* ToyFactory::createToy(Vehicles type)
{
	Toy *toy = nullptr;

	switch(type)
	{
		case Vehicles::car: {
		toy = new Car;
		break;
		}
		case Vehicles::bike: {
			toy = new Bike;
			break;
		}
		case Vehicles::plane: {
			toy = new Plane;
			break;
		}
	}
	toy->prepareParts();
	toy->combineParts();
	toy->assembleParts();
	toy->applyLabel();

	return toy;
}
