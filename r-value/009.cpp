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
	Idea C++ : unikaæ tworzenia niepotrzebnych kopii i wartoœci tymczasowych. W efekcie pewne 
	elementy lepiej przenieœæ jak kopiowaæ.

	R-value & L-value 
	
	Przeniesienie i referencje do r-wartoœci (&&).
	(s³u¿y unikaniu tworzenia niepotrzebnych kopii i wartoœci tymczasowych)
	l-wartoœæ (l-value) jest wtedy, gdy wartoœæ istnieje d³u¿ej ni¿ jedno 
		wyra¿enie i mo¿na pobraæ adres wartoœci, np. ++x, zmienna.
	r-wartoœæ (r-value) jest wtedy, gdy wartoœæ istnieje tylko 
		przez jedno wyra¿enie, np. x+y albo x++	, litera³, lista inicjalizacyjna

	A po co to? Ano referencja do r-wartoœci i mechanika przeniesienia jej do funkcji pozwala lepiej 
	zarz¹dzaæ zasobami i pokazuje jak drobiazgowy, jak pieczo³owity mo¿e byæ C++ pod k¹tem wydajnoœci
	i optymalizacji.
*/


/*
f(v,a,b,c) dodaje elementy a,b,c do wektora coll
coll - referencja do wektora
a - referencja do r-wartoœci (przenosi r-wartoœæ do a!!!)
b - znana zwyk³a referencja
c - c jest referencj¹ ale i sta³¹, czyli nie mo¿na bêdzie zmieniæ wartoœci c
*/
void f(vector<int>& coll, int&& a, int b, const int& c) {
	coll.push_back(a); // push_back() - je¿eli nie wiesz - wk³ada a na koniec tego kontenera wektor
	++b; // b jest referencj¹, wiêc mogê zmieniæ b
	coll.push_back(b);
	// ++c; // nie przejdzie, bo c jest sta³¹ (const) i nie mogê go zmieniaæ
	coll.push_back(c); // ale dodaæ na koniec kontenera wektor mogê ;)
}

void _009() {
	
	vector<int>v{};
	int a1, a2;
	a1 = a2 = 5;
	f(v, a1 + a2, a1, a2); // a1+a2 to r-wartoœæ i dziêki definicji funkcji f 
	// z argumentem int&& na drugiej pozycji, ta wartoœæ bêdzie przeniesiona.
	// (normalnie r-wartoœæ a1+a2 zosta³aby skopiowana do zmiennej 
	// w f, a tak mechanika referencji do r-wartoœci tê sumê "adoptuje" i wsadzi do vectora v.
	// Pisz¹c "adoptuje" mam na myœli to, ¿e podbiera jej stan i zasoby)
	// 
	/// a1+a2 w³aœnie przyk³ad to r-value
	printSTL(v, " ", true); // 10, 6, 5
	cout << a1 << endl; // by³o 5-k¹, ale referencja...	
	
	// spróbujê wywo³aæ to samo wstawiaj¹c w miejsce r-value coœ co jest l-value (a1 zamiast a1+a2)
	// f(v, a1, a1, a1);


}








