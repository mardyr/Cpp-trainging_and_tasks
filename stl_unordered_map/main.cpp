#include "main.h"
#include <unordered_map>
using namespace std;

/* Unordered map = kontener (mapa nieuporzadkowana) w dzialaniu podobna do tablic asocjacyjnych, gdzie indeksem elementu nie musi
byc typ calkowity. Moze byc string. Zatem elementami tej mapy beda pary KLUCZ->WARTOSC, gdzie jedno i drugie moze miec dowolny typ*/

template<typename T> void show(T &K)
{
    cout << "\t\t["<<K.size()<<"]>>\n"; // zakladam, ze typ T ma metode size() , kontenery maja
    for(auto x:K) // x bedzie kolejnym elementem kontenera K(typu T), x chwyta na raz klucz i wartosc
    {
       cout << setfill(' ')<<setw(20)<<x.first<<setfill('.')<<setw(20)<<x.second<<endl; // x.first - klucz , x.second - wartosc, w tablicy kluczem jest indeks elementu w tablicy
    }
    cout << endl;
}
int main()
{
    unordered_map<string,double>stats = {{"potencjal",75.9},{"szerokosc",111}} ; // string double, para klucz wartosc, kluczem string
    stats.emplace("wiek",24.5);
    stats.emplace("wzrost",189.92);
    stats.emplace("waga",97.1);
    stats.emplace("asertywnosc",14.3);
    stats.emplace("zlosliwosc",100);
    stats.emplace("zlosliwosc",150); // IGNOROWANIE, taki klucz jest wiêc nie bêdzie nadpisania, KLUCZ TWORZYMY TYLKO RAZ, MOZNA ZMIENIC WARTOSC , ALE TO W INNY SPOSOB
    show(stats);

    stats["zlosliwosc"] = 150; // zmiana wartosci o kluczu zlosliwosc
    show(stats);
    cout << stats.count("wiek")<<endl;// >0 gdy istnieje klucz, sprawdzam czy istnieje
    cout<< stats.count("gangrena")<<endl; // 0 gdy nie ma tej wartosci
    cout << stats.empty()<<endl; // czy jest pusty , 1 jak pusty

    unordered_map<string,double>::const_iterator i = stats.find("wzrost"); // szukam na mapie iteratora o podanym kluczu, ustawiam uchwyt na i
    cout << i->first<<" "<<i->second<<endl; // wyswietlam klucz i wartosc

    stats.erase("asertywnosc"); // usuwam po kluczu
    stats.erase(stats.begin()); // usuwam elementu, ktory jest pierwszy (po interatorze na pierwszy element)
    show(stats);
    stats.clear();
    show(stats);



    return 0;
}
