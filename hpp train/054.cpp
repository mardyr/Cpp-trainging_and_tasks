#include "main.hpp"

/**
	Pliki .hpp czyli nag��wkowe
	CTRL+F11 - wymusza zbudowanie wszystkiego (wszystkich plik�w)
*/
#include "054.hpp"

int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));

	Human You;
	Human Me("Tomasz","Ja�niewski",1918);
	You.show();
	Me.show();

	cout << r();

	return 0;
}


