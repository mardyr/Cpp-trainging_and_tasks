#pragma once
#include "Block.h"
class Pyramid : public Block
{
private:
	double a, h, H;
public:
	Pyramid(double a_ = 0, double h_ = 0, double H_ = 0);
	~Pyramid();
	void	enterData()				override;
	void	showLength()			override;
	double	calculateCapacity()		override;
	double	calculateArea()			override;
	void	showCalculatedInfo()	override;
};


