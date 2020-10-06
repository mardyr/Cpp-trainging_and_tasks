#include <iostream>
#include <array> // tablica
#include <vector> // wektor
#include <deque> // kolejka z dwoma ko�cami
#include <list> // lista
#include <forward_list> // lista jednokierunkowa
#include <set> // zbi�r
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
#include <memory> // inteligentne wska�niki
#include <functional> // reference_wrapper<>
#include <chrono> // czas
#include <iomanip> // manipulatory io
#include <string> // wiadomo
#include <thread> // w�tki 
#include <ctime>
#include <iterator>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "numbers.h"

// C++11, C++17
using namespace std;
// lambda, definicja pewnej funkcjonalno�ci, kt�ra dzia�a wprost w miejscu jej u�ycia, jest tak� funkcj� anonimow�, bo nie posiada konieczno�ci podawani nazwy. Ka�de wyra�enie lambda ma sw�j unikatowy typ: anonimowy obiekt funkcyjny (funktor). Chodzi o to, �e mog� stworzy� zmienn� (obiekt) takiego typu, jakiego jest moja lambda i przypisa� do niego lambd�. Taki obiekt to w�a�nie funktor. 
// Uwaga! Deklarowanie obiekt�w tego typu wymaga s�owa auto, co za chwil� zobaczycie.

// klasa definuje sytuacj�, gdy obiekt zachowuje si� jak ... funktor
class Funktory {
public:
	int pole;
	int operator() (int a) const {
		return a * pole;
	}
};

void _016() {	
	[] {
		cout << "\nJestm prymitywnie prost� lambd� - czyli jakby wywo�an� tu i teraz jednorazow�, nienazwan� funkcj� anonimow�.\n";
	}(); // () wywo�uje j� !	

	// funktor-obiekt typu auto do kt�rego przypisuj� lambd� ale nie wywo�uj� jej (brak () na ko�cu)
	// funktor jest obiektem funkcyjnym, bo zachowuje si� jak funkcja. 
	auto lambda1 = [] {
		cout << "\nJestm kolejn� lambd� zapisan� do zmiennej :)\n";
	}; // zwr�� uwag� na brak () (nie wywo�uj� jej w tym miejscu)
	lambda1(); // teraz wywo�am lambd� pos�uguj�c si� zmienn� lambda1
	// teraz wci�gn� do lambdy zmienne zewn�trzne
	int wci�g_mnie = 1;
	[wci�g_mnie] {	
		cout << "Wci�gn��em warto��: " << wci�g_mnie << endl; // tak wci�gni�ta warto�� nie mo�e by� modyfikowana
	}();
	cout << wci�g_mnie << endl;
	[&wci�g_mnie] {	 // a tu wci�gam przez referencj�, modyfikacja wci�gni�tej mo�liwa
		++wci�g_mnie;
		cout << "Wci�gn��em i zmieni�em warto��: " << wci�g_mnie << endl;
	}();
	cout << wci�g_mnie << endl; // lambda zmieni�a warto��

	// lambda mo�e mie� argumenty i co� zwraca�
	auto lambda2 = [wci�g_mnie](int a, const double& b) {
		return (wci�g_mnie + a) * b;
	};
	cout << "lambda2 = " << lambda2(2, 3.5) << endl; // lambda zwraca, przyjmuje argumenty i ... wci�� nie ma nazwy
	
	// lambda mo�e jawnie wymusza� typ zwracany
	auto lambda3 = [wci�g_mnie](int a, const double& b) -> long int {
		return (long int)((wci�g_mnie + a) * b); // 
	};
	cout << "lambda3 = " << lambda3(2, 3.1) << endl; // wynik 12.4 obci�ty do 12, bo jest narzucony typ zwracanej przez lambd� warto�ci jako long int
	
	// wci�gam co si� da za pomoc� =
	int var1 = 1;
	int var2 = 2;
	[=] {
		cout << "Wci�gam wszystko zewn�trzne do lambdy = " << wci�g_mnie << " " << var1 << " " << var2 << endl; // zmienne jednak jak var1 itp. nie mog� by� zmieniane
	}();

	// a co jak wci�gn� bez referencji ale tak, by da�o si� modyfikowa� tylko "na niby" ?
	[var1]() mutable {
		++var1;
		cout << "var1=" << var1 << " ale tylko wewn�trz lambdy. Mog� zmienia�, bo jest s�owo mutable!" << endl;
	}();
	cout << "var1= " << var1 << endl; // ale warto�� i tak nie jest zmieniona

	//Mog� stworzy� obiekt jako obiekt funkcyjny
	Funktory funktor2, funktor3;
	funktor2.pole = 2;
	funktor3.pole = 3;
	cout << funktor2.pole << " " << funktor2(20) << endl; //2 40
	cout << funktor3.pole << " " << funktor3(20) << endl; //3 60   
	/* Po co funktory? Sztuka dla sztuki? Udziwnienie kodu C++ aby sprawia� wra�enie jeszcze bardziej kosmicznego?
	1) obiekty funkcyjne to co� wi�cej ni� funkcja, gdy� wywo�ywane jako obiekt mog� posiada� jakby w�asny stan (normalna funkcja tego nie potrafi) patrz przyk�ad wy�ej oczywi�cie da�oby si� to zrobi� metodami poza-klas� ale to jest gorsze pod wzgl�dem organizacji kodu, pewnego porz�dku. Ka�dy obiekt zachowuj�c si� jak funkcja (niby taka sama!) jest jednak inny, tak jak inny jest ka�dy obiekt. W przyk�adzie dwa funktory, wywo�uj�ce t� sam� funkcj� z tym samym argumentem 20,da�y inny wynik!!!
	2) przekazywanie obiekt�w funkcyjnych zamiast zwyk�ych funkcji mo�e dzia�a� szybciej
	*/

	// Istniej� predefiniowane funktory, z kt�rymi si� ju� spotkali�my :) To w�a�nie by�y funktory.
	/*
		less<> - przy sortowaniu funktor sortuj�cy wg kryterium <
		greater<> - > np. set<int,greater<int>> coll;
		negate<> (odwr�� znaki), 
		multiplies<> (do kwadratu)
	*/
	deque<int> dq = { 1, 2, 3, 5, 7, 11, 13, 17, 19 };
	printSTL(dq,",",true);
	transform(dq.cbegin(), dq.cend(),
		dq.begin(),
		negate<int>());
	printSTL(dq,",",false);

	vector<int> other;
	copy(dq.begin(), dq.end(), back_inserter(other)); // other - kopia dq
	// drobna modyfikacja element�w
	srand((unsigned int)time(0)); // do losowo�ci
	transform(other.begin(), other.end(), other.begin(), [](auto& i) { return i + rand() % 2; } );
	printSTL(other, ",", false);

	transform(dq.begin(), dq.end(), // �rod�o 1
		other.begin(), // �r�d�o 2
		dq.begin(), // miejsce docelowe
		multiplies<int>()); // mno�� elementy z ze �r�d�a 1 i 2 (kolejne)
	printSTL(dq,",",false); // dq=dq*other (elementy na tych samych pozycjach wymno�one)
	/*
		bind - wi�zanie wywo�ania: predefiniowane obiekty funkcyjne mo�emy ��czy� z innymi warto�ciami: 
		wynikiem bind jest te� funktor
	*/
	set<int, greater<int>> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	deque<int> coll2;
	// Uwaga: u�yte kryterium sortowania greater<>() powoduje uporz�dkowanie odwrotne element�w:
	printSTL(coll1,",",false);

	// przekszta�� wszystkie elementy do kolekcji coll2 jako iloczyny 10
	// bind(multiplies<int>(),placeholders::_1, 10)); // operacja - definiuje obiekt funkcyjny mno��c pierwszy obiekt wywo�ania _1 przez 10
	transform(coll1.cbegin(), coll1.cend(), // �r�d�o
		back_inserter(coll2), // przeznaczenie		
		bind(multiplies<int>(), placeholders::_1, 10)); // operacja	
	printSTL(coll2,",",false);

	// zast�p elementy o warto�ci 70 elementami o warto�ci 142
	replace_if(coll2.begin(), coll2.end(), // zakres
		bind(equal_to<int>(), placeholders::_1, 70), // kryterium zast�pienia: dla 70 wstawi 142
		142); // nowa warto��
	printSTL(coll2,",",false);

	// usu� wszystkie elementy o warto�ciach pomi�dzy 50 i 80
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
	printSTL(coll2,",",false);
	// placeholders::_1 - symbol zast�pczy dla argument�w
	
}
