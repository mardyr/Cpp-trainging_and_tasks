#pragma once
#include <iostream>
class Toy
{
protected:
	std::string name;
	float price;
public:
	virtual void prepareParts()		= 0;
	virtual void combineParts()		= 0;
	virtual void assembleParts()	= 0;
	virtual void applyLabel()		= 0;
	//virtual void ShowProduct()		= 0;
};
