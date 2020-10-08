#pragma once
#include "Block.h"
class Cuboid : public Block
{
private:
	double a, b, c;
public:
			Cuboid(double a_ = 0,double b_ =0,double c_ =0);
			~Cuboid();
	void	enterData()				override ;
	void	showLength()			override;
	double	calculateCapacity()		override;
	double	calculateArea()			override;
	void	showCalculatedInfo()	override;
};


