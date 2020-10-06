// zbiór, mulitizb.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
// set(zbior) elementy nie mogą sie powtorzyc, multiset(multizbior) elementy moga sie powtarzac

#include <iostream>
#include <set> // ciag sam sie sortuje, defaultowo ciag rosnacy
#include <functional>

template<typename T>
void show(T& a)
{
    for (auto i : a) std::cout << i << " ";
    std::cout << std::endl;
    std::cout << std::string(60, '=') << std::endl;
}

int main()
{
    // elementy w zbiorze w zasadzie stale, nie mozemy zmienic ich wartosci, dlatego jak chcemy zmienic wartosc to lepiej usunac caly element i wstawic nowy
    std::set<std::string> snames{ "Kowalski","Nowak","Dudek","Kowalski" };
    show(snames);
    snames.insert({ "Kowalski","Lato","Adamowski" });
    show(snames);
    auto&& [pos, success] = snames.insert("Elo");
    std::cout << *pos << " " << success << std::endl;
    show(snames);
    if (!snames.insert("Kowalski").second) std::cout << "we got him" << std::endl; // jak wstawiasz cos do zbioru to insert generuje sie para
    // z kluczem(iterator) tej wstawianej wartosci oraz info logiczne czy sie udalo

    auto [pos2, success2] = snames.insert("Kowalski");
    std::cout << *pos2 <<" "<< success2<< std::endl; // mam iterator na to miejsce gdzie ten element juz jest
    std::cout << std::string(60, '=') << std::endl;
    // zbior z porzadkowaniem malejacym
    std::set<int,std::greater<int>> mono{ 2,3,4,5,3,2,4,5,7,8,3,5,22,11,43 }; // greater obiekt funkcyjny , liczby sie nie powtarzaja, bo to nie multilista

    show(mono);
    // zbior z porzadkowaniem rosnacym
    std::set<int,std::less<int>> mono2{ 2,3,4,5,3,2,4,5,7,8,3,5,22,11,43 };

    show(mono2);

    if (!mono2.empty()) std::cout << "Nie jest pusty" << std::endl;

    mono2.clear();

    show(mono2);

    mono.erase(2);
    show(mono);
    mono.insert({ 444,2 });
    auto iter = mono.find(8);
    mono.insert(iter, 201);

    show(mono);

    /// multiset

    std::multiset<std::string>dogs{ "Burek","Reksio","Burek","Kot","Apofis" };
    show(dogs);
    dogs.insert({ "Burek","Julek" });
    show(dogs);
    auto itx = dogs.find("Kot");
    dogs.insert((--itx), "Pies");
    show(dogs);
    auto Insert = dogs.emplace("Murek");
    show(dogs);
    std::cout << dogs.count("Burek") << std::endl;

    std::multiset<std::string> ::iterator it = find(dogs.begin(), dogs.end(), "Burek"); // dogs.find() , zwraca iterator na pierwszego Burka
    if(it != dogs.end())
    {
        std::cout << *it << std::endl;
        dogs.erase(it);
        show(dogs);
    }

    it = dogs.lower_bound("Reksio"); // iterator na pierwszy element Reksio, zwraca to samo co find na reksia
    std::cout << *it << std::endl; 
    std::cout << (dogs.find("Burek") == dogs.lower_bound("Burek"));

    it = dogs.upper_bound("Burek"); // iterator na pierwszy element za burkiem, ZA OSTATNIM BURKIEM
    std::cout << "Za burkiem : " << *it << std::endl;
    show(dogs);

    auto [first, last] = dogs.equal_range("Burek"); // lower bound + upper bound zwraca element na pierwszego burka i na za ostatnim burkiem
    std::cout << *first << " " << *last << std::endl;
    while (first != last) // to co miedzy burkiem a julkiem
    {
        std::cout << *first << " ";
        first++;
    }



}

