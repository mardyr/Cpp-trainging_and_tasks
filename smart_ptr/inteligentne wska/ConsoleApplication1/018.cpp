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

// C++17
using namespace std;
/*
	inteligentne ptr'y
*/
template <typename T>
using uPtr = unique_ptr<T, void(*)(T*)>; // alias typu szablonu

class A {
public:
	string name;
	shared_ptr<A> senior; // senior
	vector<weak_ptr<A>> vassals; // wasale
	A(const string& n, shared_ptr<A> s = nullptr) : name(n), senior(s) {}
	~A() {
		cout << name << " przepad³.\n";
	}
};

void _018() {
	/* shared_ptr : wskaŸnik ten pozwala mieæ wiele odniesieñ do obiektu, a z chwil¹ kasowania ostatniego takiego
	wskaŸnika na dany obiekt, kasowany z pamiêci jest te¿ ten obiekt (domyœlnie za pomoc¹ delete).
	WskaŸniki shared_ptr pilnuj¹ wiêc zwalniania zasobów.

	unique_ptr: pozwoli istnieæ tylko jednemu wskaŸnikowi do obiektu w danym momencie.

	weak_ptr: niekiedy shared_ptr, choæ jest rozwi¹zaniem œwietnym, mo¿e siê okazaæ niewystarczaj¹cym w pewnych sytuacjach. Np. kiedy dwa obiekty odwo³uj¹ siê do siebie nawzajem (takie cykliczne odwo³anie), nigdy nie dojdzie do zwolnienia zasobów. S¹ te¿ inne sytuacje problematyczne.
	Tymczasem weak_ptr pozwala wspó³dzieliæ dostêp do obiektu wskazywanego ale bez przyjmowania wspó³w³asnoœci tego obiektu (czyli przestaje byæ odpowiedzialny za jego zwolnienie). weak_ptr wymaga wskaŸnika wspó³dzielonego shared_ptr, i kiedy ostatni wspó³dzielony wymusi zwolnienie obiektu wskazywanego, to wskaŸniki s³abe wskazuj¹ce na ten obiekt zostan¹ wyzerowane (puste).
	Obiekty wskazane przez weak_ptr nie jest wprost dostêpny przez * i ->. Dlaczego? 
	1) Kiedy tworzê wskaŸnik wspó³dzielony ze wskaŸnika s³abego mogê sprawdziæ, czy obiekt wskazywany wci¹¿ istnieje. Je¿eli nie, zg³oszony bêdzie wyj¹tek lub zostanie utworzony wskaŸnik pusty wspó³dzielony.
	2) Je¿eli uda siê utworzyæ wskaŸnik wspó³dzielony to do momentu jego zwolenia obiekt wskazywany nie bêdzie usuniêty.
	weak_ptr ma prosty interfejs: tworzy, kopiuje i przypisuje wskaŸnik oraz wykonuje konwersjê na wskaŸnik wspó³dzielony.
	*/

	shared_ptr<int> ptr2int = make_shared<int>(10); // metoda 1 z funkcj¹ make_shared
	shared_ptr<int> ptr2int2; // metoda 2 
	ptr2int2.reset(new int(20)); 
	shared_ptr<int> ptr2int3(new int(30)); // metoda 3
	cout << ptr2int << " " << ptr2int2 << " " << ptr2int3 << " " 
		<< *ptr2int << " " << *ptr2int2 <<  " " << *ptr2int3 << endl;

	shared_ptr<string> ptr2string = make_shared<string>("koci³apci");
	cout << *ptr2string << endl;
	cout << ptr2string->substr(0, 4) << endl; // ptr2string-> przechodzi na obiekt wskazywany, a ten jest typu string, wiêc ma swoj¹ metodê substr

	shared_ptr<string> p2s1 = ptr2string;
	shared_ptr<string> p2s2 = ptr2string;
	cout << *p2s1 << " " << *p2s2 << endl;
	cout << ptr2string.use_count() << endl; // ile wskaŸników wskazuje ten sam obiekt ?
	{
		shared_ptr<string> p2s3 = ptr2string;
		cout << ptr2string.use_count() << endl; // ile wskaŸników wskazuje ten sam obiekt ?
	}
	cout << ptr2string.use_count() << endl; // ile wskaŸników wskazuje ten sam obiekt ?
	cout << *ptr2string << " " << *p2s1 << " " << *p2s2 << endl;
	/// GDYBYM TERAZ zakoñczy³ funkcjê, pamiêæ gdzie przybywa napis koci³apci zostanie zwolniona wraz ze œmierci¹ ostatniego wskaŸnika na ten napis.

	/* W£ASNA funkcja usuwaj¹ca (z delete). Gdy zostanie zwolniony ostatni wskaŸnik wspó³dziel¹cy dostêp do obiektu w pamiêci, wywo³ana
	jest funkcja (tutaj w postaci lambdy jako drugi argument) */
	{
		shared_ptr<int> p2i(new int(30),
			[](int* p) {
				cout << "rozpoczynam zwalnianie pamiêci " << p << " gdzie siedzi wartoœæ " << *p << endl;
				delete p;
			});
		{
			shared_ptr<int> temp = p2i; // ten temp od razu zginie, ale nie uruchomi lambdy
		}
		shared_ptr<int> p2i2 = p2i;
		shared_ptr<int> p2i3 = p2i;
		cout << p2i << " " << p2i2 << " " << p2i3 << endl; // ten sam adres
	}
	/// opuszczaj¹c przestrzeñ inteligentne_ptry() zwolniê p2i, oraz p2i2 i p2i3 ... na koniec (jeden raz) zostanie wywo³ana lambda dla ostatniego
	/// zwalnianego shared_ptr<int>

	/// wskaŸniki na tablice wymagaj¹ delete[] a nie delete, zatem trzeba w takim przypadku jawnie zadeklarowaæ funkcjê usuwaj¹c¹
	shared_ptr<int[]> temp(new int[100], [](int* p) { delete[] p;  });

	/* A co kiedy przypiszê now¹ wartoœæ ? */
	{
		shared_ptr<double> p2d(new double(1.5),
			[](double* p) {
				cout << "usuwam " << *p << endl;
				delete p;
			});
		p2d = nullptr; // zmieniam wartoœæ p2d, wiêc odpali siê lambda usuwaj¹ca !!
		// kolejna nowa wartoœæ usuniê siê na koniec ca³ego bloku {} po znaku zapytania ?
		p2d.reset(new double(5.123), [](double* p) { cout << "usuwam " << *p << "\n\n"; delete p; });
		cout << "\n?\n";
	}

	/* UWAGA! Poni¿szy kod wydaje siê poprawny, ale p1 i p2 nie s¹ w tej samej grupie wspó³dzielonej */
	{
		int* x = new int(5);
		shared_ptr<int> p1(x);
		//shared_ptr<int> p2(x); // B£¥D p1 i p2 nie bêd¹ wcale wspó³dzielone! co wiêcej, na koniec oba bêd¹ chcia³y zwalniaæ pamiêæ i kupa...
		//cout << p1.use_count() << " " << p2.use_count() << endl; // to wyœwietli 1 i 1 ale potem bêdzie b³¹d

		// chyba, ¿e zrobimy tak - wtedy mamy faktycznie wspó³dzielone wskaŸniki
		int* y = new int(10);
		shared_ptr<int> p3(y);
		shared_ptr<int> p4(p3); // OK - p4 faktycznie jest wspó³dzielonym z p3
		cout << p3.use_count() << " " << p4.use_count() << endl; // to wyœwietli 2 i 2
	}

	/// unique_ptr tworzy wy³¹czny wskaŸnik i potrafi zwolniæ obiekty wskazywane gdy sam jest usuwany
	{
		unique_ptr<int> uptr(new int(123));
		cout << *uptr << endl;
	} // uptr zwalnia znika i zwalnia pamiêæ

	{
		unique_ptr<int> uptr = make_unique<int>(123);
		uptr.release();
	} // uptr odda³o wskaŸnik ale nie dba ju¿ o zwolnienie zasobów - trzeba mieæ œwiadomoœæ "wycieku"
	{
		unique_ptr<int> uptr(new int(1234));
		cout << uptr << endl;
		/// unique_ptr<int> uptr2(uptr); // B£¥D !!!
		unique_ptr<int> uptr3(move(uptr)); // przenisienie ok
		cout << uptr << " " << uptr3 << endl;
		cout << *uptr3 << endl;
		cout << (nullptr==uptr) << endl;

	}
	// funkcja w³asna usuwaj¹ca jako lambda
	{
		auto deLambda = [](int* p) {
			cout << *p << " deleted\n"; delete p;
		};
		unique_ptr<int, decltype(deLambda)> uptr(new int(357), deLambda); // , 		

		// albo z wykorzystaniem szablonów , patrz wy¿ej
		// template typename<T>
		// using uPtr = unique_ptr<T, void(*)(T*)>; // alias typu szablonu

		uPtr<float> f(new float(5), [](float* p) { cout << "alias delete " << *p << endl; delete p;  });

	}
	
	{ // weak_ptr (nie bêdzie blokowa³ zwolnienia obiektu gdy zniknie ostatni shared_ptr)
		shared_ptr<A> king = make_shared<A>("Król Mieszko XXV");
		shared_ptr<A> knight1 = make_shared<A>( "Adam", king);
		shared_ptr<A> knight2 = make_shared<A>("Bogdan", king);
		shared_ptr<A> knight3 = make_shared<A>("Czarek", king);		
		king->vassals.push_back(knight1);
		king->vassals.push_back(knight2);
		king->vassals.push_back(knight3);		
		
		shared_ptr<A> peasant1 = make_shared<A>("Maciej", knight3);
		shared_ptr<A> peasant2 = make_shared<A>("Szczepan", knight3);
		knight3->vassals.push_back(peasant1);
		knight3->vassals.push_back(peasant2);

		cout << knight3.use_count() << endl;
		peasant1 = peasant2 = nullptr; // nie wskazuj¹ ju¿ swojego seniora knight3
		// ale senior ma do nich weak_ptr w wasalach ! Zwalnia siê pamiêæ na obiekty ch³opów,nikn¹ te¿ ich wskaŸniki wspó³dzielone na seniora Czarka
		knight3 = nullptr; // seniora knight3 te¿ ju¿ nie ma
		for (auto& i : king->vassals) {
			if (!i.expired()) cout << i.lock()->name << endl; // i to weak_ptr<A>
			else cout << "---" << endl;
		}
	}
	/// UWAGA! shared,unique,weak same z siebie nie nadaj¹ sie zbytnio do wykorzystania w programowaniu wielow¹tkowym !
}
