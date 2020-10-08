#pragma once
class Block
{
public:
	virtual			~Block() = 0;
	virtual void	enterData() = 0;
	virtual void	showLength() = 0;
	virtual double	calculateCapacity() = 0;
	virtual double	calculateArea() = 0;
	virtual void	showCalculatedInfo() = 0;
};

