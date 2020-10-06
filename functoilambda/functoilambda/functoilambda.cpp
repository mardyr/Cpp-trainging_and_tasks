// functoilambda.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <array> // tablica
#include <vector> // wektor
#include <deque> // kolejka z dwoma końcami
#include <list> // lista
#include <forward_list> // lista jednokierunkowa
#include <set> // zbiór
#include <map> // asocjacyjne kontenery 
#include <unordered_set>
#include <unordered_map> 
#include <stack> // stos
#include <queue> // kolejka
#include <algorithm> // algorytmy
#include <typeinfo> // typeid
#include <type_traits> // cechy typowe
#include <bitset> // bitset
#include <utility> // np. pair
#include <tuple> // krotki tuple
#include <memory> // inteligentne wskaźniki
#include <functional> // reference_wrapper<>
#include <chrono> // czas
#include <iomanip> // manipulatory io
#include <string> // wiadomo
#include <thread> // wątki 
#include <ctime>
#include <iterator>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "numbers.h"

// C++11, C++17
using namespace std;
// lambda, definicja pewnej funkcjonalności, która działa wprost w miejscu jej użycia, jest taką funkcją anonimową, bo nie posiada konieczności podawani nazwy. Każde wyrażenie lambda ma swój unikatowy typ: anonimowy obiekt funkcyjny (funktor). Chodzi o to, że mogę stworzyć zmienną (obiekt) takiego typu, jakiego jest moja lambda i przypisać do niego lambdę. Taki obiekt to właśnie funktor. 
// Uwaga! Deklarowanie obiektów tego typu wymaga słowa auto, co za chwilę zobaczycie.

// klasa definuje sytuację, gdy obiekt zachowuje się jak ... funktor
class Funktory {
public:
	int pole;
	int operator() (int a) const {
		return a * pole;
	}
};

void _016() {
	[] {
		cout << "\nJestm prymitywnie prostą lambdą - czyli jakby wywołaną tu i teraz jednorazową, nienazwaną funkcją anonimową.\n";
	}(); // () wywołuje ją !	

	// funktor-obiekt typu auto do którego przypisuję lambdę ale nie wywołuję jej (brak () na końcu)
	// funktor jest obiektem funkcyjnym, bo zachowuje się jak funkcja. 
	auto lambda1 = [] {
		cout << "\nJestm kolejną lambdą zapisaną do zmiennej :)\n";
	}; // zwróć uwagę na brak () (nie wywołuję jej w tym miejscu)
	lambda1(); // teraz wywołam lambdę posługując się zmienną lambda1
	// teraz wciągnę do lambdy zmienne zewnętrzne
	int wciąg_mnie = 1;
	[wciąg_mnie] {
		cout << "Wciągnąłem wartość: " << wciąg_mnie << endl; // tak wciągnięta wartość nie może być modyfikowana
	}();
	cout << wciąg_mnie << endl;
	[&wciąg_mnie] {	 // a tu wciągam przez referencję, modyfikacja wciągniętej możliwa
		++wciąg_mnie;
		cout << "Wciągnąłem i zmieniłem wartość: " << wciąg_mnie << endl;
	}();
	cout << wciąg_mnie << endl; // lambda zmieniła wartość

	// lambda może mieć argumenty i coś zwracać
	auto lambda2 = [wciąg_mnie](int a, const double& b) {
		return (wciąg_mnie + a) * b;
	};
	cout << "lambda2 = " << lambda2(2, 3.5) << endl; // lambda zwraca, przyjmuje argumenty i ... wciąż nie ma nazwy

	// lambda może jawnie wymuszać typ zwracany
	auto lambda3 = [wciąg_mnie](int a, const double& b) -> long int {
		return (long int)((wciąg_mnie + a) * b); // 
	};
	cout << "lambda3 = " << lambda3(2, 3.1) << endl; // wynik 12.4 obcięty do 12, bo jest narzucony typ zwracanej przez lambdę wartości jako long int

	// wciągam co się da za pomocą =
	int var1 = 1;
	int var2 = 2;
	[=] {
		cout << "Wciągam wszystko zewnętrzne do lambdy = " << wciąg_mnie << " " << var1 << " " << var2 << endl; // zmienne jednak jak var1 itp. nie mogą być zmieniane
	}();

	// a co jak wciągnę bez referencji ale tak, by dało się modyfikować tylko "na niby" ?
	[var1]() mutable {
		++var1;
		cout << "var1=" << var1 << " ale tylko wewnątrz lambdy. Mogę zmieniać, bo jest słowo mutable!" << endl;
	}();
	cout << "var1= " << var1 << endl; // ale wartość i tak nie jest zmieniona

	//Mogę stworzyć obiekt jako obiekt funkcyjny
	Funktory funktor2, funktor3;
	funktor2.pole = 2;
	funktor3.pole = 3;
	cout << funktor2.pole << " " << funktor2(20) << endl; //2 40
	cout << funktor3.pole << " " << funktor3(20) << endl; //3 60   
	/* Po co funktory? Sztuka dla sztuki? Udziwnienie kodu C++ aby sprawiał wrażenie jeszcze bardziej kosmicznego?
	1) obiekty funkcyjne to coś więcej niż funkcja, gdyż wywoływane jako obiekt mogą posiadać jakby własny stan (normalna funkcja tego nie potrafi) patrz przykład wyżej oczywiście dałoby się to zrobić metodami poza-klasą ale to jest gorsze pod względem organizacji kodu, pewnego porządku. Każdy obiekt zachowując się jak funkcja (niby taka sama!) jest jednak inny, tak jak inny jest każdy obiekt. W przykładzie dwa funktory, wywołujące tę samą funkcję z tym samym argumentem 20,dały inny wynik!!!
	2) przekazywanie obiektów funkcyjnych zamiast zwykłych funkcji może działać szybciej
	*/

	// Istnieją predefiniowane funktory, z którymi się już spotkaliśmy :) To właśnie były funktory.
	/*
		less<> - przy sortowaniu funktor sortujący wg kryterium <
		greater<> - > np. set<int,greater<int>> coll;
		negate<> (odwróć znaki),
		multiplies<> (do kwadratu)
	*/
	deque<int> dq = { 1, 2, 3, 5, 7, 11, 13, 17, 19 };
	printSTL(dq, ",", true);
	transform(dq.cbegin(), dq.cend(),
		dq.begin(),
		negate<int>());
	printSTL(dq, ",", false);

	vector<int> other;
	copy(dq.begin(), dq.end(), back_inserter(other)); // other - kopia dq
	// drobna modyfikacja elementów
	srand((unsigned int)time(0)); // do losowości
	transform(other.begin(), other.end(), other.begin(), [](auto& i) { return i + rand() % 2; });
	printSTL(other, ",", false);

	transform(dq.begin(), dq.end(), // źrodło 1
		other.begin(), // źródło 2
		dq.begin(), // miejsce docelowe
		multiplies<int>()); // mnożę elementy z ze źródła 1 i 2 (kolejne)
	printSTL(dq, ",", false); // dq=dq*other (elementy na tych samych pozycjach wymnożone)
	/*
		bind - wiązanie wywołania: predefiniowane obiekty funkcyjne możemy łączyć z innymi wartościami:
		wynikiem bind jest też funktor
	*/
	set<int, greater<int>> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	deque<int> coll2;
	// Uwaga: użyte kryterium sortowania greater<>() powoduje uporządkowanie odwrotne elementów:
	printSTL(coll1, ",", false);

	// przekształć wszystkie elementy do kolekcji coll2 jako iloczyny 10
	// bind(multiplies<int>(),placeholders::_1, 10)); // operacja - definiuje obiekt funkcyjny mnożąc pierwszy obiekt wywołania _1 przez 10
	transform(coll1.cbegin(), coll1.cend(), // źródło
		back_inserter(coll2), // przeznaczenie		
		bind(multiplies<int>(), placeholders::_1, 10)); // operacja	
	printSTL(coll2, ",", false);

	// zastąp elementy o wartości 70 elementami o wartości 142
	replace_if(coll2.begin(), coll2.end(), // zakres
		bind(equal_to<int>(), placeholders::_1, 70), // kryterium zastąpienia: dla 70 wstawi 142
		142); // nowa wartość
	printSTL(coll2, ",", false);

	// usuń wszystkie elementy o wartościach pomiędzy 50 i 80
	coll2.erase(
		// wywal elementy od
		remove_if(coll2.begin(), coll2.end(),
			bind(logical_and<bool>(),
				bind(greater_equal<int>(), placeholders::_1, 50),
				bind(less_equal<int>(), placeholders::_1, 80)
			)
		),
		// do
		coll2.end()
	);
	printSTL(coll2, ",", false);
	// placeholders::_1 - symbol zastępczy dla argumentów

}
