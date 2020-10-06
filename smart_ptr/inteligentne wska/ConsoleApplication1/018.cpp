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
		cout << name << " przepad�.\n";
	}
};

void _018() {
	/* shared_ptr : wska�nik ten pozwala mie� wiele odniesie� do obiektu, a z chwil� kasowania ostatniego takiego
	wska�nika na dany obiekt, kasowany z pami�ci jest te� ten obiekt (domy�lnie za pomoc� delete).
	Wska�niki shared_ptr pilnuj� wi�c zwalniania zasob�w.

	unique_ptr: pozwoli istnie� tylko jednemu wska�nikowi do obiektu w danym momencie.

	weak_ptr: niekiedy shared_ptr, cho� jest rozwi�zaniem �wietnym, mo�e si� okaza� niewystarczaj�cym w pewnych sytuacjach. Np. kiedy dwa obiekty odwo�uj� si� do siebie nawzajem (takie cykliczne odwo�anie), nigdy nie dojdzie do zwolnienia zasob�w. S� te� inne sytuacje problematyczne.
	Tymczasem weak_ptr pozwala wsp�dzieli� dost�p do obiektu wskazywanego ale bez przyjmowania wsp�w�asno�ci tego obiektu (czyli przestaje by� odpowiedzialny za jego zwolnienie). weak_ptr wymaga wska�nika wsp�dzielonego shared_ptr, i kiedy ostatni wsp�dzielony wymusi zwolnienie obiektu wskazywanego, to wska�niki s�abe wskazuj�ce na ten obiekt zostan� wyzerowane (puste).
	Obiekty wskazane przez weak_ptr nie jest wprost dost�pny przez * i ->. Dlaczego? 
	1) Kiedy tworz� wska�nik wsp�dzielony ze wska�nika s�abego mog� sprawdzi�, czy obiekt wskazywany wci�� istnieje. Je�eli nie, zg�oszony b�dzie wyj�tek lub zostanie utworzony wska�nik pusty wsp�dzielony.
	2) Je�eli uda si� utworzy� wska�nik wsp�dzielony to do momentu jego zwolenia obiekt wskazywany nie b�dzie usuni�ty.
	weak_ptr ma prosty interfejs: tworzy, kopiuje i przypisuje wska�nik oraz wykonuje konwersj� na wska�nik wsp�dzielony.
	*/

	shared_ptr<int> ptr2int = make_shared<int>(10); // metoda 1 z funkcj� make_shared
	shared_ptr<int> ptr2int2; // metoda 2 
	ptr2int2.reset(new int(20)); 
	shared_ptr<int> ptr2int3(new int(30)); // metoda 3
	cout << ptr2int << " " << ptr2int2 << " " << ptr2int3 << " " 
		<< *ptr2int << " " << *ptr2int2 <<  " " << *ptr2int3 << endl;

	shared_ptr<string> ptr2string = make_shared<string>("koci�apci");
	cout << *ptr2string << endl;
	cout << ptr2string->substr(0, 4) << endl; // ptr2string-> przechodzi na obiekt wskazywany, a ten jest typu string, wi�c ma swoj� metod� substr

	shared_ptr<string> p2s1 = ptr2string;
	shared_ptr<string> p2s2 = ptr2string;
	cout << *p2s1 << " " << *p2s2 << endl;
	cout << ptr2string.use_count() << endl; // ile wska�nik�w wskazuje ten sam obiekt ?
	{
		shared_ptr<string> p2s3 = ptr2string;
		cout << ptr2string.use_count() << endl; // ile wska�nik�w wskazuje ten sam obiekt ?
	}
	cout << ptr2string.use_count() << endl; // ile wska�nik�w wskazuje ten sam obiekt ?
	cout << *ptr2string << " " << *p2s1 << " " << *p2s2 << endl;
	/// GDYBYM TERAZ zako�czy� funkcj�, pami�� gdzie przybywa napis koci�apci zostanie zwolniona wraz ze �mierci� ostatniego wska�nika na ten napis.

	/* W�ASNA funkcja usuwaj�ca (z delete). Gdy zostanie zwolniony ostatni wska�nik wsp�dziel�cy dost�p do obiektu w pami�ci, wywo�ana
	jest funkcja (tutaj w postaci lambdy jako drugi argument) */
	{
		shared_ptr<int> p2i(new int(30),
			[](int* p) {
				cout << "rozpoczynam zwalnianie pami�ci " << p << " gdzie siedzi warto�� " << *p << endl;
				delete p;
			});
		{
			shared_ptr<int> temp = p2i; // ten temp od razu zginie, ale nie uruchomi lambdy
		}
		shared_ptr<int> p2i2 = p2i;
		shared_ptr<int> p2i3 = p2i;
		cout << p2i << " " << p2i2 << " " << p2i3 << endl; // ten sam adres
	}
	/// opuszczaj�c przestrze� inteligentne_ptry() zwolni� p2i, oraz p2i2 i p2i3 ... na koniec (jeden raz) zostanie wywo�ana lambda dla ostatniego
	/// zwalnianego shared_ptr<int>

	/// wska�niki na tablice wymagaj� delete[] a nie delete, zatem trzeba w takim przypadku jawnie zadeklarowa� funkcj� usuwaj�c�
	shared_ptr<int[]> temp(new int[100], [](int* p) { delete[] p;  });

	/* A co kiedy przypisz� now� warto�� ? */
	{
		shared_ptr<double> p2d(new double(1.5),
			[](double* p) {
				cout << "usuwam " << *p << endl;
				delete p;
			});
		p2d = nullptr; // zmieniam warto�� p2d, wi�c odpali si� lambda usuwaj�ca !!
		// kolejna nowa warto�� usuni� si� na koniec ca�ego bloku {} po znaku zapytania ?
		p2d.reset(new double(5.123), [](double* p) { cout << "usuwam " << *p << "\n\n"; delete p; });
		cout << "\n?\n";
	}

	/* UWAGA! Poni�szy kod wydaje si� poprawny, ale p1 i p2 nie s� w tej samej grupie wsp�dzielonej */
	{
		int* x = new int(5);
		shared_ptr<int> p1(x);
		//shared_ptr<int> p2(x); // B��D p1 i p2 nie b�d� wcale wsp�dzielone! co wi�cej, na koniec oba b�d� chcia�y zwalnia� pami�� i kupa...
		//cout << p1.use_count() << " " << p2.use_count() << endl; // to wy�wietli 1 i 1 ale potem b�dzie b��d

		// chyba, �e zrobimy tak - wtedy mamy faktycznie wsp�dzielone wska�niki
		int* y = new int(10);
		shared_ptr<int> p3(y);
		shared_ptr<int> p4(p3); // OK - p4 faktycznie jest wsp�dzielonym z p3
		cout << p3.use_count() << " " << p4.use_count() << endl; // to wy�wietli 2 i 2
	}

	/// unique_ptr tworzy wy��czny wska�nik i potrafi zwolni� obiekty wskazywane gdy sam jest usuwany
	{
		unique_ptr<int> uptr(new int(123));
		cout << *uptr << endl;
	} // uptr zwalnia znika i zwalnia pami��

	{
		unique_ptr<int> uptr = make_unique<int>(123);
		uptr.release();
	} // uptr odda�o wska�nik ale nie dba ju� o zwolnienie zasob�w - trzeba mie� �wiadomo�� "wycieku"
	{
		unique_ptr<int> uptr(new int(1234));
		cout << uptr << endl;
		/// unique_ptr<int> uptr2(uptr); // B��D !!!
		unique_ptr<int> uptr3(move(uptr)); // przenisienie ok
		cout << uptr << " " << uptr3 << endl;
		cout << *uptr3 << endl;
		cout << (nullptr==uptr) << endl;

	}
	// funkcja w�asna usuwaj�ca jako lambda
	{
		auto deLambda = [](int* p) {
			cout << *p << " deleted\n"; delete p;
		};
		unique_ptr<int, decltype(deLambda)> uptr(new int(357), deLambda); // , 		

		// albo z wykorzystaniem szablon�w , patrz wy�ej
		// template typename<T>
		// using uPtr = unique_ptr<T, void(*)(T*)>; // alias typu szablonu

		uPtr<float> f(new float(5), [](float* p) { cout << "alias delete " << *p << endl; delete p;  });

	}
	
	{ // weak_ptr (nie b�dzie blokowa� zwolnienia obiektu gdy zniknie ostatni shared_ptr)
		shared_ptr<A> king = make_shared<A>("Kr�l Mieszko XXV");
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
		peasant1 = peasant2 = nullptr; // nie wskazuj� ju� swojego seniora knight3
		// ale senior ma do nich weak_ptr w wasalach ! Zwalnia si� pami�� na obiekty ch�op�w,nikn� te� ich wska�niki wsp�dzielone na seniora Czarka
		knight3 = nullptr; // seniora knight3 te� ju� nie ma
		for (auto& i : king->vassals) {
			if (!i.expired()) cout << i.lock()->name << endl; // i to weak_ptr<A>
			else cout << "---" << endl;
		}
	}
	/// UWAGA! shared,unique,weak same z siebie nie nadaj� sie zbytnio do wykorzystania w programowaniu wielow�tkowym !
}
