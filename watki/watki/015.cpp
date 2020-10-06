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
#include <ctime>
#include <iterator>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <future> // to interfejs wysokiego poziomu 
#include <thread> // tu mam w¹tki niskiego poziomu
#include <chrono>
#include <fstream>
#include <sstream> // stringstream
#include "numbers.h"


using namespace std;



auto start = chrono::system_clock::now();
int ZMIENNA = 100;

/*
	W¥TKI.
	Interfejs wysokiego poziomu czyli <future> i metoda async.
	Interfejs niskiego poziomu czyli thread.
	---------------------------------------------------------------------------------------------
	std::thread to klasa reprezentuj¹ca poszczególne w¹tki wykonania.
	W¹tek jest sekwencj¹ instrukcji, które mog¹ byæ wykonywane równolegle z innymi takimi w¹tkami. W¹tki dziel¹ tê sam¹ przestrzeñ adresow¹. Ka¿dy w¹tek ma unikalny identyfikator.
*/
// wyœwietla literki alfabetu od a=97 lub A=65
int letters(int a=65) {
	cout << "\nSTART letters: thread id=> " << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
	int step = 0, i;
	ostream_iterator<char> out(std::cout,"");
	do {
		step++;
		*out++ = i = rand() % 26 + a; // nasze interatory wstawiaj¹ce do strumienia		
		this_thread::sleep_for(chrono::milliseconds(150)); // troszkê poczekaj
	} while (i != a + 25 || step < 15); // nie koñcz za szybko!
	cout << "\nEND letters: thread id=>" << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
	return step;
}
// funkcji wyœwietla n znaków char z, i przedstawia id w¹tku
void line(char z, unsigned n) {
	cout << "\nSTART line thread id=> " << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;	
	while (n--) {
		cout << z;
		this_thread::sleep_for(chrono::milliseconds(125));
	}
	cout << "\nEND line thread id=> " << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
}
// funkcji wyœwietla n znaków char z, i przedstawia id w¹tku
void f(unsigned int mili) {
	this_thread::sleep_for(chrono::milliseconds(mili));	
	cout << "\nEND f thread id=> " << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
}
void setValue(int* a) { *a = 100; ZMIENNA = 200; }

void _015() {
	srand(time(0));
	
	cout << "Start programu: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()-start).count() << endl;
	cout << "W¹tek g³ówny=" << this_thread::get_id() << endl;
	
		// 1) Funkcja letters ruszy jako oddzielny w¹tek, jednak decyzjê o starcie pozostawiam maszynie 
		//a zatem w¹tek mo¿e w ogóle nie ruszyæ (a¿ do wywo³ania jawnie metody .get()).	
		std::future<int> result1(std::async(launch::async,letters, 65));
		/// uruchamia ale program idzie dalej (nie stoi w tym miejscu)
		/* Uwaga! Jeœli wywo³anie asynchroniczne nie jest mo¿liwe w tym miejscu, program zg³osi wyj¹tek std::system_error. Je¿eli uda³o siê uruchomiæ, 
		wynik dzia³ania w¹tku zostanie przypisany specjalnemu obietowi result_1 klasy future<int>
		*/
		/*
			.get() wywo³ane na obiekcie result1 klasy future "domaga" siê zwrócenia wyniku, wiêc je¿eli w¹tek do tej pory jeszcze nie ruszy³ - rusza
			i program ju¿ teraz czeka a¿ zwróci wynik i siê zakoñczy.
		*/
		int s2 = letters(97); // tu wywo³anie w g³. w¹tku, normalnie - ma³e literki. 		
		cout << result1.get() << endl; // zwraca wynik dzia³ania letters, je¿eli jeszcze nie odpali³ siê - to siê odpali.
		cout << s2 << endl;

		// Wywo³anie .get() na obiekcie future praktycznie niszczy ten obiekt, 
		// wiêc ponowne wywo³anie .get() nie bêdzie mo¿liwe
		// .valid() sprawdza czy obiekt result1 jeszcze jest wa¿ny
		if (result1.valid()) cout << "result1 jest `valid`, mo¿na go .get()\n";
		else cout << "result1 nie jest `valid`, nie da siê go .get()\n";
		cout << endl;

		std::future<int> result2(std::async(letters, 65)); // du¿e lierki
		result2.wait(); // metoda .wait() wywo³ana na obiekcie future wymusza start i czeka na skoñczenie (idea w¹tku trochê pada)
		cout << "\n\nPO WAIT() " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
		
	/// UWAGA! w ostatecznoœci to, czy coœ "zyskamy" na wielow¹tkowoœci zale¿y od wielu czynników, choæby od zu¿ycia zasobów,
	// obci¹¿eniu systemu, jakoœci tego, coœmy sp³odzili itp. itd.
	/// Ró¿ne w¹tki mog¹ mieæ dostêp do tych samych danych w pamiêci, co mo¿e prowadziæ do nieprzewidzianych skutków. 
	// Programowanie wielow¹tkowe jest pozornie proste, w praktyce musi byæ bardzo dobrze zaprojektowane,
	//aby w¹tki faktycznie wykorzystywa³y moce procesorów i aby nie kolidowa³y, tworz¹c kompletnie nieprzewidywalne zachowania programu.	
	
	std::thread thread1(line, '!', 50); // start funkcji w tle
	cout << thread1.get_id() << endl; // thread1 - pobieranie jego id w w¹tku g³ównym
	this_thread::sleep_for(chrono::milliseconds(1000)); // poczekaj 1s
	line('*', 10); 

	thread1.join(); // .join() ka¿e czekaæ procesowi g³ównemu na skoñczenie w¹tku thread1
	/*
		Je¿eli .join() zabraknie, to w¹tek g³ówny skoñczy siê PRZED zakoñczeniem w¹tku thread1 !! Tymczasem proces-w¹tek potomny nie skoñczy³ dzia³ania,	dlatego zobaczymy b³¹d, a w¹tek thread1 zostanie zdmuchniêty. ( std::terminate() )
	*/

	/// Od³¹czam w¹tek od obiektu, 
	/// Nawet, gdy w¹tek g³ówny siê skoñczy, w¹tek thread2 zostanie "od³¹czony" od g³ównego i bêdzie samodzielnie dzia³aæ.
	
	std::thread thread2(f, 500); // start funkcji w tle
	cout << thread2.get_id() << endl; // thread2 - pobieranie jego id w w¹tku g³ównym	
	thread2.detach();
	f(2500); // czeka i tworzy plik ze znacznikiem czasu

	cout << "\n\nEND " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << "\n\n";
		
	/*
		W¹tki niskiego poziomu uruchamiamy tworz¹c obiekt klasy std::thread (biblioteka <thread>)
		DLACZEGO uruchomienie w¹tku jako w¹tku (klasa std::thread) jest NISKOPOZIOMOWE w stosunku do async() ? Miêdzy innymi dlatego, ¿e:
		*Uruchomienie takie jak <std::thread thread1 (line,'!',40);> nie gwarantuje strategii startu w¹tku.	
		[Strategia startu/uruchomienia w¹tku to np. fakt, ¿e w¹tek mo¿e nie wystartowaæ od razu, ale z opóŸnieniem.
		Mo¿na go wymusiæ, lub po utworzeniu uruchomiæ w innym momencie itp. itd.]
		*Nie ma ¿adnego interfejsu przechwytuj¹cego wynik dzia³ania w¹tku. Mo¿na co najwy¿ej sprawdziæ identyfikator w¹tku.
			[Mo¿na jednak przekazaæ wynik dzia³aj¹cego w¹tku wykorzystuj¹c referencjê/wskaŸnik]
			[Mo¿na te¿ skorzystaæ z promes, ale to ju¿ w innym kursie ... ;) ]
	*/

	/// UWAGA! Od³¹czone w¹tki (.detach()) mog¹ stanowiæ PROBLEM, je¿eli nie zostan¹ zabite :)
	
	int x;
	thread thread3(setValue, &x);
	thread3.detach();
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << endl << x << "," << ZMIENNA << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
	
}
/**
	Z£OTA ZASADA!
		Jedyna bezpieczna sytuacja, kiedy ró¿ne w¹tki maj¹ dostêpdo tych samych danych (równolegle) jest wtedy,
		gdy WSZYSTKIE mog¹ dane tylko czytaæ.
		Mniej bezpieczna, ale jeszcze ³atwa do przewidzenia jest sytuacja, gdy TYLKO jeden konkretny w¹tek mo¿e dane zmieniaæ.
		Wszystkie inne sytuacje s¹ ju¿ k³opotliwe i zawsze generuj¹ ryzyko chaosu. le zaprojektowane w¹tki mog¹ tak zadzia³aæ, zrobiæ
		takie combo, ¿e nikt nie przewidzi co siê stanie ze wspólnymi danymi ... :-D
		Jak sobie radziæ z problemami wspó³bie¿noœci? O tym w innym kursie !
*/
