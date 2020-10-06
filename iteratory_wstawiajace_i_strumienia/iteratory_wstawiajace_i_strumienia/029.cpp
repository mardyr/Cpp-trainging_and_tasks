#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <stack>
#include <typeinfo>
#include <string>
#include <ctime>
#include "numbers.h"
#include <iterator>
#include <algorithm>

// C++17

using namespace std;
// wi�cej o iteratorach:
/*
	Przegl�daj�c r�ne strony, podr�czniki nigdzie nie spotka�em ultra-precyzyjnego wyja�nienia tego, co za chwil� spr�buj� nieudolnie pokaza�. Wsz�dzie s� jakie� niedopowiedzenia, jakie� nie�cis�o�ci definicyjne. Wsz�dzie a� prosi si� o zestaw pyta�. Jestem pewny, �e tw�rcy tych wyja�nie� nie odpowiedz� jasno na pytanie: "czy osoba, kt�ra si� uczy i nie spotka�a si� nigdy z tym zagadnieniem w og�le zrozumie, co do niej m�wimy?" 	
	C++ niekiedy jest w mojej ocenie tak abstrakcyjny, �e - po prostu - sprawia du�� trudno�� poznawcz�. Praktyka pokazuje, �e pewne rzeczy trudniej opisa�, a �atwiej zrozumie� czym s� poprzez prezentacj� tego, co robi�. W procesie edukacji nie raz zdarza�o mi si� - nie wstydz� si� tego powiedzie� - najpierw zobaczy� jak co� dzia�a, nie do ko�ca to rozumiej�c a nawet nie potrafi�c tego wyra�nie od samego �rodka opisa�. Zastanawiam si� nawet, czy jest to zawsze konieczne? A potem powoli i po pewnym czasie pojawi�o si� takie "aaaa, dobra, wiem!" Zg��bi�em sens, dzia�anie i istot� tego, co tu si� wyprawia p�niej. Wielu uczni�w korzysta np. ze wska�nik�w ale do ko�ca nie umie o tym opowiedzie�, co w�a�ciwie si� dzieje. Ale z czasem naturalnie staje si� to zrozumia�e. Ucz�c sam musz� w pe�ni zrozumie� i nie zawsze jest to mo�liwe "od r�ki".
	Podobny problem i podobny mechanizm napotka�em ucz�c si� o adaptatorach iterator�w. Nawet samo poj�cie trudno wyja�ni�, poniewa� nigdzie nie znalaz�em jego bezpo�redniej jasnej definicji. Jest to raczej definicja poprzez opis dzia�ania. To troch� tak, jakby bardzo do�wiadczeni programi�ci tworz�cy j�zyk zrealizowali zrozumia�� tylko sobie g��bok� abstrakcj�, wpier napisan� i dzia�aj�c� a dopiero potem opisali teoretycznie to co wymy�lili. Ten nowe rzeczy trudno jest nauczy� si� kolejnym osobom, szczeg�lnie nie posiadaj�cych takiego do�wiadczenia, kt�re sprawia, �e j�zyk nie tyle si� "zna" co dog��bnie rozumie, nim si� wr�cz my�li. Tak. J�zyk jest czym� tak �ywym, �e wymaga sam w sobie pewnej dojrza�o�ci i rozumienia. Dlatego bogactwo j�zyka faktycznie zmienia my�lenie a tym samym osoba rozumiej�ca j�zyk g��biej si� nim wyra�a, pe�niej opisuje to, co my�li. Jestem pewny, �e moje wyobra�enie tego, co mog� "napisa� w tym j�zyku" jest p�ytkie w por�wnaniu do wyobra�enia tych, co j�zyk tworzyli i pos�uguj� si� nim z rozmachem i obficie. Taka wyobra�nia, jakie bogactwo j�zyka! Obrazy bowiem porusz� tylko zmys� wzroku, a j�zyk istot� rzeczy! R�wnie� j�zyk C++.
*/

void _029() {

	// <iterator>
	// Iteratory wstawiaj�ce ! Bardzo ciekawa mechanika sprz�ona z pewnymi funkcjami kontener�w	
	// Iterator, kt�ry wstawia na ko�cu konetenera w momencie przypisania do� warto�ci:
	// na ko�cu (wstawiacz ko�cowy) Uwaga! kontener musi mie� jak�� metod� wstawiaj�c� na koniec
	vector<int> x; // vector ma metody wstawiania na koniec (push_back)
	auto it = back_inserter(x);
	cout << typeid(it).name() << endl; // back_insert_iterator<vector<int>> - specjalny iterator wstawiania na koniec
	back_inserter(x) = 100; // to jakbym mia� *iterator = 100; iterator++; back_inserter to taka funkcja - tzw. adaptator iterator�w: back_inserter wstawia co� do kontenera zawsze na ko�cu. Adaptator to taka funkcja, kt�ra przystosowuje iteratory do u�ytku troch� innego ni� by�o przeznaczone. 
	
	back_inserter(x) = 200;
	printSTL(x, ",", false);
	// albo
	x.reserve(x.size() * 2); // rezerwuj� sobie odpowiednio miejsca by unika� realokacji i w efekcie podczas operacji kopiowania nie zgubi� warto�ci iterator�w 
	copy(x.begin(), x.end(), back_inserter(x)); // kopiuje ze �rod�a okre�lonego zasi�giem do miejsca przeznaczenia, kt�rym jest ten sam kontener <algorithm>, do algorytm�w jeszcze wr�cimy.
	printSTL(x, ",", false); // 100,200,100,200

	cout << endl;
	deque<int> set1 = { 1,2,3,4,5,6,5,4,3 };
	vector<int> set2;
	transform(set1.cbegin(), set1.cend(), // �rod�o
		back_inserter(set2), 
		[](const auto& p) { return p + p;  }); // tu obliczam element z set1 zanim wstawi� do set2
	printSTL(set2, " ", false);

	// wstawiacz pocz�tkowy (iterator wstawiaj�cy na pocz�tku), a wi�c np. do listy, czy kolejki o dw�ch ko�cach (praktycznie push_front())
	deque<int> y;
	front_inserter(y) = 300;
	front_inserter(y) = 400;
	printSTL(y, ",", false); // 400,300
	copy(y.begin(), y.end(), front_inserter(y)); // nie musz� przydziela� pami�ci
	printSTL(y, ",", false);//300,400,400,300 :)

	// wstawiacz og�lny praktycznie dla ka�dego kontenera z wyj�tkiem array i forward_list
	list<int> L1;
	list<int> L2;
	inserter(L1, L1.end()) = 500;
	inserter(L1, --L1.end()) = 600; // przed 500
	inserter(L1, L1.end()) = 700; // na koniec	
	printSTL(L1, ",", false);//600,500,700
	copy(L1.begin(), L1.end(), // �r�d�o
		inserter(L2, L2.begin())); // miejsce docelowe
	printSTL(L2, "->", false);
	
	/// iteratory strumienia

	// Iteratory strumieni wyj�ciowych zapisuj� przypisywane warto�ci do strumienia 	wyj�ciowego.Wykorzystuj�c iteratory strumieni wyj�ciowych, algorytmy mog� zapisywa� dane bezpo�rednio do strumieni.
	ostream_iterator<int> out(cout, ":"); // argumentem jest strumie�, a potem ogranicznik
	for (auto i : { 1,2,3,4,5 }) { // wy�l� w praktyce elementy typi int do cout
		*out = i;		
		out++;
	}
	cout << endl;
	vector<int> data{ 1,2,3,4,5,6,7,8,9,10 };
	copy(data.begin(), data.end(), out); // "kopiuj�" z wektora do strumienia wyj�cia
	cout << endl;
	// mo�na te� nie definiowa� out
	copy(data.begin(), data.end(), ostream_iterator<int>(cout, "<-"));
	cout << endl;

	
	// Iterator strumienia wej�ciowego odczytuje elementy ze strumienia wej�ciowego. 
	vector<int> fromUser; // wkr�tce zape�ni si� danymi :)
	copy(istream_iterator<int>(cin), // pocz�tek, iterator pocz�tkowy strumienia cin gotowy do pobierania int'�w 
		istream_iterator<int>(), // domy�lny konstruktor iteratora strumienia, dzi�ki kt�remu mamy okre�lony iterator ko�ca strumienia, bo tego oczekuje algorytm copy() 
		back_inserter(fromUser)); /// kopiuje ze strumienia wej�cia a� do EOF lub b��du (np. nie int) [EOF to Ctrl+Z]	
	printSTL(fromUser,",",true); /// wszystkie wprowadzone liczby :)
	unique_copy(fromUser.begin(), fromUser.end(),
		ostream_iterator<int>(cout, ",")); // kopiuje z kolekcji na strumie� wyj�cia (ale pomija ju� wy�wietlone)
	cin.clear();
	
	vector<string> strings;
	istream_iterator<string> endOfStream; // iterator ko�ca strumienia
	copy(istream_iterator<string>(cin), // kopiuj z cin 
		endOfStream, // dop�ki nie osi�gnie ko�ca 
		back_inserter(strings)); /// dodawaj na koniec strings
	printSTL(strings," ",false); /// wszystkie wprowadzone napisy :)
	cin.clear();
	
	strings.clear();
	istream_iterator<string> getString(cin); // wprowad� np. a b c d e
	while (getString != endOfStream) {
		cout << *getString << " " << *getString << endl; // dwa razy iterator tego samego elementu
		++getString; // przechodzi na nast�pny
		//advance(getString, 2); // przechodzi co drugi, ale pilnuj, by nie wyj�� poza endOfStream!
	}

	cin.clear();
	
}
/*
		Iteratory i ich rodzaj - podsumowanie
	array,vector,deque,string: swobodne iteratory
	list: -- ++
	forward_list: jednokierunkowa: ++
	set, multiset: ++ -- (elementy s� sta�e)
	map, multimap: ++ -- (klucz jest sta�y)
	unordered_map, unordered_multimap, unordered_set, unordered_multiset: ++
	*/