#include "main.h"

/**
	Pliki .hpp czyli nag³ówkowe
	CTRL+F11 - wymusza zbudowanie wszystkiego (wszystkich plików)
*/
#include "054.h"

int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));

	Human You;
	Human Me("Tomasz","Jasniewski",1918);
	You.show();
	Me.show();

	cout << r();

	return 0;
}

