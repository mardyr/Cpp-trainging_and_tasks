#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <map>
#include <ctime>
#include <typeinfo>
#include <type_traits>
#include "numbers1.h"

// C++17
using namespace std;
/*
	Wyra¿enia FOLD (folding). Pozwalaj¹ skróciæ kod. Korzystaj¹ z mechaniki rekurencji.

	... 

	wyra¿enia foldingu: +, -, *, /, %, ^, &, |, =, <, >, <<, >>, +=, -=, *=, /=, %=, ^=, &=, |=, <<=, >>=, ==, !=, <=, >=, &&, ||, ,, .*, ->*
*/


template <typename ... Args>
auto function1(Args ... args) { // pakiet argumentów
	return (args + ... + 0); // 
}

template <typename ... Args>
auto function2(Args ... args) {
	return (args - ...); // prawy folding
}

template <typename ... Args>
auto function3(Args ... args) {
	return (... - args); // lewy folding
}
// ³¹czy napisy w string
template <typename ... Args>
auto function4(Args ... args) {
	cout << "sizeof:" << sizeof...(Args) << endl;
	return (... + (args + string(" ")) ); 
}

// zlicza wyst¹pienia czegoœ w zbiorze
template <typename C, typename ... Args>
auto countInside(const C& c, Args ... args) {
	return (std::count(begin(c),end(c),args) + ...);
}

// dodaj do kontenera z funkcj¹ push_back listê elementów
template <typename C, typename ... Args>
void massInsertion(C& c, Args ... args) {
	(c.push_back(args) , ...) ;
}

// mass cout
template <typename ... Args>
void massCout(Args&&... args) {	
	(std::cout << ... << args) << std::endl;	
}


void _007() {
	// sumowanie
	cout << function1(1, 2, 3, 4, 5, 100.f) << endl; // 115 ! :)
	cout << function1(1) << endl; // 1
	cout << function1() << endl; // 0
	
	// prawy folding
	cout << function2(107,50,3,15) << endl; // 107-(50-(3-15)) = 45
	
	// lewy folding
	cout << function3(107,50,3,15) << endl; // ((107-50)-3)-15 = 39
	
	// z³¹czy napisy
	cout << ":" << function4("Ala","ma","kota") << ":" << endl; //
	
	// zliczy wyst¹pienie czegoœ w zbiorze
	vector<int> v{5,6,7,5, 5,6,7,8 };
	cout << countInside(v, 1, 2, 3) << endl; // 5!  1,2,3 znaleziono w zbiorze 5 razy :)
	
	// dodaje masowo do kontenera
	massInsertion(v, 100, 200, 300, 500);
	printSTL(v, ", ", true); // :-D
	
	// masowy cout :)
	massCout("A", 1, 'c',"trauma",6.5f);
}







