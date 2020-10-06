#ifndef HPP054_INCLUDED
#define HPP054_INCLUDED

class Human {
public:
	string name="John";
	string lastname="Doe";
	unsigned year=2000;
	Human();
	Human(string n, string l, unsigned y);
	void show();
};

// deklarujê sobie te¿ jak¹œ funkcjê
/** ta funkcja coœ robi ... */
unsigned int r();


#include "054_1.cpp"

#endif // MYHPP_INCLUDED
