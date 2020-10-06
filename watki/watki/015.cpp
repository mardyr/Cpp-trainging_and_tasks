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
#include <ctime>
#include <iterator>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <future> // to interfejs wysokiego poziomu 
#include <thread> // tu mam w�tki niskiego poziomu
#include <chrono>
#include <fstream>
#include <sstream> // stringstream
#include "numbers.h"


using namespace std;



auto start = chrono::system_clock::now();
int ZMIENNA = 100;

/*
	W�TKI.
	Interfejs wysokiego poziomu czyli <future> i metoda async.
	Interfejs niskiego poziomu czyli thread.
	---------------------------------------------------------------------------------------------
	std::thread to klasa reprezentuj�ca poszczeg�lne w�tki wykonania.
	W�tek jest sekwencj� instrukcji, kt�re mog� by� wykonywane r�wnolegle z innymi takimi w�tkami. W�tki dziel� t� sam� przestrze� adresow�. Ka�dy w�tek ma unikalny identyfikator.
*/
// wy�wietla literki alfabetu od a=97 lub A=65
int letters(int a=65) {
	cout << "\nSTART letters: thread id=> " << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
	int step = 0, i;
	ostream_iterator<char> out(std::cout,"");
	do {
		step++;
		*out++ = i = rand() % 26 + a; // nasze interatory wstawiaj�ce do strumienia		
		this_thread::sleep_for(chrono::milliseconds(150)); // troszk� poczekaj
	} while (i != a + 25 || step < 15); // nie ko�cz za szybko!
	cout << "\nEND letters: thread id=>" << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
	return step;
}
// funkcji wy�wietla n znak�w char z, i przedstawia id w�tku
void line(char z, unsigned n) {
	cout << "\nSTART line thread id=> " << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;	
	while (n--) {
		cout << z;
		this_thread::sleep_for(chrono::milliseconds(125));
	}
	cout << "\nEND line thread id=> " << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
}
// funkcji wy�wietla n znak�w char z, i przedstawia id w�tku
void f(unsigned int mili) {
	this_thread::sleep_for(chrono::milliseconds(mili));	
	cout << "\nEND f thread id=> " << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
}
void setValue(int* a) { *a = 100; ZMIENNA = 200; }

void _015() {
	srand(time(0));
	
	cout << "Start programu: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()-start).count() << endl;
	cout << "W�tek g��wny=" << this_thread::get_id() << endl;
	
		// 1) Funkcja letters ruszy jako oddzielny w�tek, jednak decyzj� o starcie pozostawiam maszynie 
		//a zatem w�tek mo�e w og�le nie ruszy� (a� do wywo�ania jawnie metody .get()).	
		std::future<int> result1(std::async(launch::async,letters, 65));
		/// uruchamia ale program idzie dalej (nie stoi w tym miejscu)
		/* Uwaga! Je�li wywo�anie asynchroniczne nie jest mo�liwe w tym miejscu, program zg�osi wyj�tek std::system_error. Je�eli uda�o si� uruchomi�, 
		wynik dzia�ania w�tku zostanie przypisany specjalnemu obietowi result_1 klasy future<int>
		*/
		/*
			.get() wywo�ane na obiekcie result1 klasy future "domaga" si� zwr�cenia wyniku, wi�c je�eli w�tek do tej pory jeszcze nie ruszy� - rusza
			i program ju� teraz czeka a� zwr�ci wynik i si� zako�czy.
		*/
		int s2 = letters(97); // tu wywo�anie w g�. w�tku, normalnie - ma�e literki. 		
		cout << result1.get() << endl; // zwraca wynik dzia�ania letters, je�eli jeszcze nie odpali� si� - to si� odpali.
		cout << s2 << endl;

		// Wywo�anie .get() na obiekcie future praktycznie niszczy ten obiekt, 
		// wi�c ponowne wywo�anie .get() nie b�dzie mo�liwe
		// .valid() sprawdza czy obiekt result1 jeszcze jest wa�ny
		if (result1.valid()) cout << "result1 jest `valid`, mo�na go .get()\n";
		else cout << "result1 nie jest `valid`, nie da si� go .get()\n";
		cout << endl;

		std::future<int> result2(std::async(letters, 65)); // du�e lierki
		result2.wait(); // metoda .wait() wywo�ana na obiekcie future wymusza start i czeka na sko�czenie (idea w�tku troch� pada)
		cout << "\n\nPO WAIT() " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
		
	/// UWAGA! w ostateczno�ci to, czy co� "zyskamy" na wielow�tkowo�ci zale�y od wielu czynnik�w, cho�by od zu�ycia zasob�w,
	// obci��eniu systemu, jako�ci tego, co�my sp�odzili itp. itd.
	/// R�ne w�tki mog� mie� dost�p do tych samych danych w pami�ci, co mo�e prowadzi� do nieprzewidzianych skutk�w. 
	// Programowanie wielow�tkowe jest pozornie proste, w praktyce musi by� bardzo dobrze zaprojektowane,
	//aby w�tki faktycznie wykorzystywa�y moce procesor�w i aby nie kolidowa�y, tworz�c kompletnie nieprzewidywalne zachowania programu.	
	
	std::thread thread1(line, '!', 50); // start funkcji w tle
	cout << thread1.get_id() << endl; // thread1 - pobieranie jego id w w�tku g��wnym
	this_thread::sleep_for(chrono::milliseconds(1000)); // poczekaj 1s
	line('*', 10); 

	thread1.join(); // .join() ka�e czeka� procesowi g��wnemu na sko�czenie w�tku thread1
	/*
		Je�eli .join() zabraknie, to w�tek g��wny sko�czy si� PRZED zako�czeniem w�tku thread1 !! Tymczasem proces-w�tek potomny nie sko�czy� dzia�ania,	dlatego zobaczymy b��d, a w�tek thread1 zostanie zdmuchni�ty. ( std::terminate() )
	*/

	/// Od��czam w�tek od obiektu, 
	/// Nawet, gdy w�tek g��wny si� sko�czy, w�tek thread2 zostanie "od��czony" od g��wnego i b�dzie samodzielnie dzia�a�.
	
	std::thread thread2(f, 500); // start funkcji w tle
	cout << thread2.get_id() << endl; // thread2 - pobieranie jego id w w�tku g��wnym	
	thread2.detach();
	f(2500); // czeka i tworzy plik ze znacznikiem czasu

	cout << "\n\nEND " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << "\n\n";
		
	/*
		W�tki niskiego poziomu uruchamiamy tworz�c obiekt klasy std::thread (biblioteka <thread>)
		DLACZEGO uruchomienie w�tku jako w�tku (klasa std::thread) jest NISKOPOZIOMOWE w stosunku do async() ? Mi�dzy innymi dlatego, �e:
		*Uruchomienie takie jak <std::thread thread1 (line,'!',40);> nie gwarantuje strategii startu w�tku.	
		[Strategia startu/uruchomienia w�tku to np. fakt, �e w�tek mo�e nie wystartowa� od razu, ale z op�nieniem.
		Mo�na go wymusi�, lub po utworzeniu uruchomi� w innym momencie itp. itd.]
		*Nie ma �adnego interfejsu przechwytuj�cego wynik dzia�ania w�tku. Mo�na co najwy�ej sprawdzi� identyfikator w�tku.
			[Mo�na jednak przekaza� wynik dzia�aj�cego w�tku wykorzystuj�c referencj�/wska�nik]
			[Mo�na te� skorzysta� z promes, ale to ju� w innym kursie ... ;) ]
	*/

	/// UWAGA! Od��czone w�tki (.detach()) mog� stanowi� PROBLEM, je�eli nie zostan� zabite :)
	
	int x;
	thread thread3(setValue, &x);
	thread3.detach();
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << endl << x << "," << ZMIENNA << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
	
}
/**
	Z�OTA ZASADA!
		Jedyna bezpieczna sytuacja, kiedy r�ne w�tki maj� dost�pdo tych samych danych (r�wnolegle) jest wtedy,
		gdy WSZYSTKIE mog� dane tylko czyta�.
		Mniej bezpieczna, ale jeszcze �atwa do przewidzenia jest sytuacja, gdy TYLKO jeden konkretny w�tek mo�e dane zmienia�.
		Wszystkie inne sytuacje s� ju� k�opotliwe i zawsze generuj� ryzyko chaosu. �le zaprojektowane w�tki mog� tak zadzia�a�, zrobi�
		takie combo, �e nikt nie przewidzi co si� stanie ze wsp�lnymi danymi ... :-D
		Jak sobie radzi� z problemami wsp�bie�no�ci? O tym w innym kursie !
*/
