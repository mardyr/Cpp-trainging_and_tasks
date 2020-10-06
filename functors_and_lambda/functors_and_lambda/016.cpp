#include <iostream>
#include <array> // tablica
#include <vector> // wektor
#include <deque> // kolejka z dwoma koñcami
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
#include <memory> // inteligentne wskaŸniki
#include <functional> // reference_wrapper<>
#include <chrono> // czas
#include <iomanip> // manipulatory io
#include <string> // wiadomo
#include <thread> // w¹tki 
#include <ctime>
#include <iterator>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "numbers.h"

// C++11, C++17
using namespace std;
// lambda, definicja pewnej funkcjonalnoœci, która dzia³a wprost w miejscu jej u¿ycia, jest tak¹ funkcj¹ anonimow¹, bo nie posiada koniecznoœci podawani nazwy. Ka¿de wyra¿enie lambda ma swój unikatowy typ: anonimowy obiekt funkcyjny (funktor). Chodzi o to, ¿e mogê stworzyæ zmienn¹ (obiekt) takiego typu, jakiego jest moja lambda i przypisaæ do niego lambdê. Taki obiekt to w³aœnie funktor. 
// Uwaga! Deklarowanie obiektów tego typu wymaga s³owa auto, co za chwilê zobaczycie.

// klasa definuje sytuacjê, gdy obiekt zachowuje siê jak ... funktor
class Funktory {
public:
	int pole;
	int operator() (int a) const {
		return a * pole;
	}
};

void _016() {	
	[] {
		cout << "\nJestm prymitywnie prost¹ lambd¹ - czyli jakby wywo³an¹ tu i teraz jednorazow¹, nienazwan¹ funkcj¹ anonimow¹.\n";
	}(); // () wywo³uje j¹ !	

	// funktor-obiekt typu auto do którego przypisujê lambdê ale nie wywo³ujê jej (brak () na koñcu)
	// funktor jest obiektem funkcyjnym, bo zachowuje siê jak funkcja. 
	auto lambda1 = [] {
		cout << "\nJestm kolejn¹ lambd¹ zapisan¹ do zmiennej :)\n";
	}; // zwróæ uwagê na brak () (nie wywo³ujê jej w tym miejscu)
	lambda1(); // teraz wywo³am lambdê pos³uguj¹c siê zmienn¹ lambda1
	// teraz wci¹gnê do lambdy zmienne zewnêtrzne
	int wci¹g_mnie = 1;
	[wci¹g_mnie] {	
		cout << "Wci¹gn¹³em wartoœæ: " << wci¹g_mnie << endl; // tak wci¹gniêta wartoœæ nie mo¿e byæ modyfikowana
	}();
	cout << wci¹g_mnie << endl;
	[&wci¹g_mnie] {	 // a tu wci¹gam przez referencjê, modyfikacja wci¹gniêtej mo¿liwa
		++wci¹g_mnie;
		cout << "Wci¹gn¹³em i zmieni³em wartoœæ: " << wci¹g_mnie << endl;
	}();
	cout << wci¹g_mnie << endl; // lambda zmieni³a wartoœæ

	// lambda mo¿e mieæ argumenty i coœ zwracaæ
	auto lambda2 = [wci¹g_mnie](int a, const double& b) {
		return (wci¹g_mnie + a) * b;
	};
	cout << "lambda2 = " << lambda2(2, 3.5) << endl; // lambda zwraca, przyjmuje argumenty i ... wci¹¿ nie ma nazwy
	
	// lambda mo¿e jawnie wymuszaæ typ zwracany
	auto lambda3 = [wci¹g_mnie](int a, const double& b) -> long int {
		return (long int)((wci¹g_mnie + a) * b); // 
	};
	cout << "lambda3 = " << lambda3(2, 3.1) << endl; // wynik 12.4 obciêty do 12, bo jest narzucony typ zwracanej przez lambdê wartoœci jako long int
	
	// wci¹gam co siê da za pomoc¹ =
	int var1 = 1;
	int var2 = 2;
	[=] {
		cout << "Wci¹gam wszystko zewnêtrzne do lambdy = " << wci¹g_mnie << " " << var1 << " " << var2 << endl; // zmienne jednak jak var1 itp. nie mog¹ byæ zmieniane
	}();

	// a co jak wci¹gnê bez referencji ale tak, by da³o siê modyfikowaæ tylko "na niby" ?
	[var1]() mutable {
		++var1;
		cout << "var1=" << var1 << " ale tylko wewn¹trz lambdy. Mogê zmieniaæ, bo jest s³owo mutable!" << endl;
	}();
	cout << "var1= " << var1 << endl; // ale wartoœæ i tak nie jest zmieniona

	//Mogê stworzyæ obiekt jako obiekt funkcyjny
	Funktory funktor2, funktor3;
	funktor2.pole = 2;
	funktor3.pole = 3;
	cout << funktor2.pole << " " << funktor2(20) << endl; //2 40
	cout << funktor3.pole << " " << funktor3(20) << endl; //3 60   
	/* Po co funktory? Sztuka dla sztuki? Udziwnienie kodu C++ aby sprawia³ wra¿enie jeszcze bardziej kosmicznego?
	1) obiekty funkcyjne to coœ wiêcej ni¿ funkcja, gdy¿ wywo³ywane jako obiekt mog¹ posiadaæ jakby w³asny stan (normalna funkcja tego nie potrafi) patrz przyk³ad wy¿ej oczywiœcie da³oby siê to zrobiæ metodami poza-klas¹ ale to jest gorsze pod wzglêdem organizacji kodu, pewnego porz¹dku. Ka¿dy obiekt zachowuj¹c siê jak funkcja (niby taka sama!) jest jednak inny, tak jak inny jest ka¿dy obiekt. W przyk³adzie dwa funktory, wywo³uj¹ce tê sam¹ funkcjê z tym samym argumentem 20,da³y inny wynik!!!
	2) przekazywanie obiektów funkcyjnych zamiast zwyk³ych funkcji mo¿e dzia³aæ szybciej
	*/

	// Istniej¹ predefiniowane funktory, z którymi siê ju¿ spotkaliœmy :) To w³aœnie by³y funktory.
	/*
		less<> - przy sortowaniu funktor sortuj¹cy wg kryterium <
		greater<> - > np. set<int,greater<int>> coll;
		negate<> (odwróæ znaki), 
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
	// drobna modyfikacja elementów
	srand((unsigned int)time(0)); // do losowoœci
	transform(other.begin(), other.end(), other.begin(), [](auto& i) { return i + rand() % 2; } );
	printSTL(other, ",", false);

	transform(dq.begin(), dq.end(), // Ÿrod³o 1
		other.begin(), // Ÿród³o 2
		dq.begin(), // miejsce docelowe
		multiplies<int>()); // mno¿ê elementy z ze Ÿród³a 1 i 2 (kolejne)
	printSTL(dq,",",false); // dq=dq*other (elementy na tych samych pozycjach wymno¿one)
	/*
		bind - wi¹zanie wywo³ania: predefiniowane obiekty funkcyjne mo¿emy ³¹czyæ z innymi wartoœciami: 
		wynikiem bind jest te¿ funktor
	*/
	set<int, greater<int>> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	deque<int> coll2;
	// Uwaga: u¿yte kryterium sortowania greater<>() powoduje uporz¹dkowanie odwrotne elementów:
	printSTL(coll1,",",false);

	// przekszta³æ wszystkie elementy do kolekcji coll2 jako iloczyny 10
	// bind(multiplies<int>(),placeholders::_1, 10)); // operacja - definiuje obiekt funkcyjny mno¿¹c pierwszy obiekt wywo³ania _1 przez 10
	transform(coll1.cbegin(), coll1.cend(), // Ÿród³o
		back_inserter(coll2), // przeznaczenie		
		bind(multiplies<int>(), placeholders::_1, 10)); // operacja	
	printSTL(coll2,",",false);

	// zast¹p elementy o wartoœci 70 elementami o wartoœci 142
	replace_if(coll2.begin(), coll2.end(), // zakres
		bind(equal_to<int>(), placeholders::_1, 70), // kryterium zast¹pienia: dla 70 wstawi 142
		142); // nowa wartoœæ
	printSTL(coll2,",",false);

	// usuñ wszystkie elementy o wartoœciach pomiêdzy 50 i 80
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
	// placeholders::_1 - symbol zastêpczy dla argumentów
	
}
