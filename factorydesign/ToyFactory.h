#pragma once
#include "Toy.h"

enum class Vehicles{ car,plane,bike};
class ToyFactory 

{
public:
	static Toy* createToy(Vehicles type);

};

