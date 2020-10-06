#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <map>
#include <ctime>
#include <typeinfo>
#include <type_traits>
#include "numbers.h"

// C++17
using namespace std;
/*
	Idea C++ : unika� tworzenia niepotrzebnych kopii i warto�ci tymczasowych. W efekcie pewne 
	elementy lepiej przenie�� jak kopiowa�.

	R-value & L-value 
	
	Przeniesienie i referencje do r-warto�ci (&&).
	(s�u�y unikaniu tworzenia niepotrzebnych kopii i warto�ci tymczasowych)
	l-warto�� (l-value) jest wtedy, gdy warto�� istnieje d�u�ej ni� jedno 
		wyra�enie i mo�na pobra� adres warto�ci, np. ++x, zmienna.
	r-warto�� (r-value) jest wtedy, gdy warto�� istnieje tylko 
		przez jedno wyra�enie, np. x+y albo x++	, litera�, lista inicjalizacyjna

	A po co to? Ano referencja do r-warto�ci i mechanika przeniesienia jej do funkcji pozwala lepiej 
	zarz�dza� zasobami i pokazuje jak drobiazgowy, jak pieczo�owity mo�e by� C++ pod k�tem wydajno�ci
	i optymalizacji.
*/


/*
f(v,a,b,c) dodaje elementy a,b,c do wektora coll
coll - referencja do wektora
a - referencja do r-warto�ci (przenosi r-warto�� do a!!!)
b - znana zwyk�a referencja
c - c jest referencj� ale i sta��, czyli nie mo�na b�dzie zmieni� warto�ci c
*/
void f(vector<int>& coll, int&& a, int b, const int& c) {
	coll.push_back(a); // push_back() - je�eli nie wiesz - wk�ada a na koniec tego kontenera wektor
	++b; // b jest referencj�, wi�c mog� zmieni� b
	coll.push_back(b);
	// ++c; // nie przejdzie, bo c jest sta�� (const) i nie mog� go zmienia�
	coll.push_back(c); // ale doda� na koniec kontenera wektor mog� ;)
}

void _009() {
	
	vector<int>v{};
	int a1, a2;
	a1 = a2 = 5;
	f(v, a1 + a2, a1, a2); // a1+a2 to r-warto�� i dzi�ki definicji funkcji f 
	// z argumentem int&& na drugiej pozycji, ta warto�� b�dzie przeniesiona.
	// (normalnie r-warto�� a1+a2 zosta�aby skopiowana do zmiennej 
	// w f, a tak mechanika referencji do r-warto�ci t� sum� "adoptuje" i wsadzi do vectora v.
	// Pisz�c "adoptuje" mam na my�li to, �e podbiera jej stan i zasoby)
	// 
	/// a1+a2 w�a�nie przyk�ad to r-value
	printSTL(v, " ", true); // 10, 6, 5
	cout << a1 << endl; // by�o 5-k�, ale referencja...	
	
	// spr�buj� wywo�a� to samo wstawiaj�c w miejsce r-value co� co jest l-value (a1 zamiast a1+a2)
	// f(v, a1, a1, a1);


}








