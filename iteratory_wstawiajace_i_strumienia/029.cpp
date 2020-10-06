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
// wiêcej o iteratorach:
/*
	Przegl¹daj¹c ró¿ne strony, podrêczniki nigdzie nie spotka³em ultra-precyzyjnego wyjaœnienia tego, co za chwilê spróbujê nieudolnie pokazaæ. Wszêdzie s¹ jakieœ niedopowiedzenia, jakieœ nieœcis³oœci definicyjne. Wszêdzie a¿ prosi siê o zestaw pytañ. Jestem pewny, ¿e twórcy tych wyjaœnieñ nie odpowiedz¹ jasno na pytanie: "czy osoba, która siê uczy i nie spotka³a siê nigdy z tym zagadnieniem w ogóle zrozumie, co do niej mówimy?" 	
	C++ niekiedy jest w mojej ocenie tak abstrakcyjny, ¿e - po prostu - sprawia du¿¹ trudnoœæ poznawcz¹. Praktyka pokazuje, ¿e pewne rzeczy trudniej opisaæ, a ³atwiej zrozumieæ czym s¹ poprzez prezentacjê tego, co robi¹. W procesie edukacji nie raz zdarza³o mi siê - nie wstydzê siê tego powiedzieæ - najpierw zobaczyæ jak coœ dzia³a, nie do koñca to rozumiej¹c a nawet nie potrafi¹c tego wyraŸnie od samego œrodka opisaæ. Zastanawiam siê nawet, czy jest to zawsze konieczne? A potem powoli i po pewnym czasie pojawi³o siê takie "aaaa, dobra, wiem!" Zg³êbi³em sens, dzia³anie i istotê tego, co tu siê wyprawia póŸniej. Wielu uczniów korzysta np. ze wskaŸników ale do koñca nie umie o tym opowiedzieæ, co w³aœciwie siê dzieje. Ale z czasem naturalnie staje siê to zrozumia³e. Ucz¹c sam muszê w pe³ni zrozumieæ i nie zawsze jest to mo¿liwe "od rêki".
	Podobny problem i podobny mechanizm napotka³em ucz¹c siê o adaptatorach iteratorów. Nawet samo pojêcie trudno wyjaœniæ, poniewa¿ nigdzie nie znalaz³em jego bezpoœredniej jasnej definicji. Jest to raczej definicja poprzez opis dzia³ania. To trochê tak, jakby bardzo doœwiadczeni programiœci tworz¹cy jêzyk zrealizowali zrozumia³¹ tylko sobie g³êbok¹ abstrakcjê, wpier napisan¹ i dzia³aj¹c¹ a dopiero potem opisali teoretycznie to co wymyœlili. Ten nowe rzeczy trudno jest nauczyæ siê kolejnym osobom, szczególnie nie posiadaj¹cych takiego doœwiadczenia, które sprawia, ¿e jêzyk nie tyle siê "zna" co dog³êbnie rozumie, nim siê wrêcz myœli. Tak. Jêzyk jest czymœ tak ¿ywym, ¿e wymaga sam w sobie pewnej dojrza³oœci i rozumienia. Dlatego bogactwo jêzyka faktycznie zmienia myœlenie a tym samym osoba rozumiej¹ca jêzyk g³êbiej siê nim wyra¿a, pe³niej opisuje to, co myœli. Jestem pewny, ¿e moje wyobra¿enie tego, co mogê "napisaæ w tym jêzyku" jest p³ytkie w porównaniu do wyobra¿enia tych, co jêzyk tworzyli i pos³uguj¹ siê nim z rozmachem i obficie. Taka wyobraŸnia, jakie bogactwo jêzyka! Obrazy bowiem porusz¹ tylko zmys³ wzroku, a jêzyk istotê rzeczy! Równie¿ jêzyk C++.
*/

void _029() {

	// <iterator>
	// Iteratory wstawiaj¹ce ! Bardzo ciekawa mechanika sprzê¿ona z pewnymi funkcjami kontenerów	
	// Iterator, który wstawia na koñcu konetenera w momencie przypisania doñ wartoœci:
	// na koñcu (wstawiacz koñcowy) Uwaga! kontener musi mieæ jak¹œ metodê wstawiaj¹c¹ na koniec
	vector<int> x; // vector ma metody wstawiania na koniec (push_back)
	auto it = back_inserter(x);
	cout << typeid(it).name() << endl; // back_insert_iterator<vector<int>> - specjalny iterator wstawiania na koniec
	back_inserter(x) = 100; // to jakbym mia³ *iterator = 100; iterator++; back_inserter to taka funkcja - tzw. adaptator iteratorów: back_inserter wstawia coœ do kontenera zawsze na koñcu. Adaptator to taka funkcja, która przystosowuje iteratory do u¿ytku trochê innego ni¿ by³o przeznaczone. 
	
	back_inserter(x) = 200;
	printSTL(x, ",", false);
	// albo
	x.reserve(x.size() * 2); // rezerwujê sobie odpowiednio miejsca by unikaæ realokacji i w efekcie podczas operacji kopiowania nie zgubiæ wartoœci iteratorów 
	copy(x.begin(), x.end(), back_inserter(x)); // kopiuje ze Ÿrod³a okreœlonego zasiêgiem do miejsca przeznaczenia, którym jest ten sam kontener <algorithm>, do algorytmów jeszcze wrócimy.
	printSTL(x, ",", false); // 100,200,100,200

	cout << endl;
	deque<int> set1 = { 1,2,3,4,5,6,5,4,3 };
	vector<int> set2;
	transform(set1.cbegin(), set1.cend(), // Ÿrod³o
		back_inserter(set2), 
		[](const auto& p) { return p + p;  }); // tu obliczam element z set1 zanim wstawiê do set2
	printSTL(set2, " ", false);

	// wstawiacz pocz¹tkowy (iterator wstawiaj¹cy na pocz¹tku), a wiêc np. do listy, czy kolejki o dwóch koñcach (praktycznie push_front())
	deque<int> y;
	front_inserter(y) = 300;
	front_inserter(y) = 400;
	printSTL(y, ",", false); // 400,300
	copy(y.begin(), y.end(), front_inserter(y)); // nie muszê przydzielaæ pamiêci
	printSTL(y, ",", false);//300,400,400,300 :)

	// wstawiacz ogólny praktycznie dla ka¿dego kontenera z wyj¹tkiem array i forward_list
	list<int> L1;
	list<int> L2;
	inserter(L1, L1.end()) = 500;
	inserter(L1, --L1.end()) = 600; // przed 500
	inserter(L1, L1.end()) = 700; // na koniec	
	printSTL(L1, ",", false);//600,500,700
	copy(L1.begin(), L1.end(), // Ÿród³o
		inserter(L2, L2.begin())); // miejsce docelowe
	printSTL(L2, "->", false);
	
	/// iteratory strumienia

	// Iteratory strumieni wyjœciowych zapisuj¹ przypisywane wartoœci do strumienia 	wyjœciowego.Wykorzystuj¹c iteratory strumieni wyjœciowych, algorytmy mog¹ zapisywaæ dane bezpoœrednio do strumieni.
	ostream_iterator<int> out(cout, ":"); // argumentem jest strumieñ, a potem ogranicznik
	for (auto i : { 1,2,3,4,5 }) { // wyœlê w praktyce elementy typi int do cout
		*out = i;		
		out++;
	}
	cout << endl;
	vector<int> data{ 1,2,3,4,5,6,7,8,9,10 };
	copy(data.begin(), data.end(), out); // "kopiujê" z wektora do strumienia wyjœcia
	cout << endl;
	// mo¿na te¿ nie definiowaæ out
	copy(data.begin(), data.end(), ostream_iterator<int>(cout, "<-"));
	cout << endl;

	
	// Iterator strumienia wejœciowego odczytuje elementy ze strumienia wejœciowego. 
	vector<int> fromUser; // wkrótce zape³ni siê danymi :)
	copy(istream_iterator<int>(cin), // pocz¹tek, iterator pocz¹tkowy strumienia cin gotowy do pobierania int'ów 
		istream_iterator<int>(), // domyœlny konstruktor iteratora strumienia, dziêki któremu mamy okreœlony iterator koñca strumienia, bo tego oczekuje algorytm copy() 
		back_inserter(fromUser)); /// kopiuje ze strumienia wejœcia a¿ do EOF lub b³êdu (np. nie int) [EOF to Ctrl+Z]	
	printSTL(fromUser,",",true); /// wszystkie wprowadzone liczby :)
	unique_copy(fromUser.begin(), fromUser.end(),
		ostream_iterator<int>(cout, ",")); // kopiuje z kolekcji na strumieñ wyjœcia (ale pomija ju¿ wyœwietlone)
	cin.clear();
	
	vector<string> strings;
	istream_iterator<string> endOfStream; // iterator koñca strumienia
	copy(istream_iterator<string>(cin), // kopiuj z cin 
		endOfStream, // dopóki nie osi¹gnie koñca 
		back_inserter(strings)); /// dodawaj na koniec strings
	printSTL(strings," ",false); /// wszystkie wprowadzone napisy :)
	cin.clear();
	
	strings.clear();
	istream_iterator<string> getString(cin); // wprowadŸ np. a b c d e
	while (getString != endOfStream) {
		cout << *getString << " " << *getString << endl; // dwa razy iterator tego samego elementu
		++getString; // przechodzi na nastêpny
		//advance(getString, 2); // przechodzi co drugi, ale pilnuj, by nie wyjœæ poza endOfStream!
	}

	cin.clear();
	
}
/*
		Iteratory i ich rodzaj - podsumowanie
	array,vector,deque,string: swobodne iteratory
	list: -- ++
	forward_list: jednokierunkowa: ++
	set, multiset: ++ -- (elementy s¹ sta³e)
	map, multimap: ++ -- (klucz jest sta³y)
	unordered_map, unordered_multimap, unordered_set, unordered_multiset: ++
	*/