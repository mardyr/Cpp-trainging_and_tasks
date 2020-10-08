#pragma once
#include "Block.h"
class Sphere : public Block
{
private:
	double r;
public:
			Sphere(double r_ = 0);
			~Sphere();
	void	enterData()				override;
	void	showLength()			override;
	double	calculateCapacity()		override;
	double	calculateArea()			override;
	void	showCalculatedInfo()	override;
	
};

