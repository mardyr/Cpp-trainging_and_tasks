// map.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <cstring>

int main()
{
    std::map<int, std::string> ids;
    ids = {
        {21,"goraca woda"},
        {8,"filizanka"},
        {11,"cukier"},
        {3,"spoon"},
        {19,"herbatka"}
    };

    ids.insert({ { 11,"cytrynka" },{ 12,"imbir" } }); // mapa może miec tylko wartosci o nie powtarzajacym kluczu, sortowanie rosnace , defaultowe
    ids[1000] = "kropla beskidu";
    for (auto i : ids) std::cout << i.first << "==" << i.second << std::endl;
    std::cout << std::endl;

    // obiekty funkcyjne do sortowania , greater do najwiekszego , 

    std::map<float, float, std::greater<float>> malej{ {1,2.6},{3.1,5.4},{0.9,10} }; // sortowane sa klucze nie wartosci
    for (auto [k, v] : malej) std::cout << k << "==" << v << " ";
    std::cout << "[" << malej.size() << "]" << std::endl;

    std::for_each
    (
        malej.begin(), malej.end(), [](std::pair<const float, float>& element) // dla kazdego elementu mapy(pary) z zakresu od begin do end , 
        {
            element.second += 1;
        }
    );
    for (auto [k, v] : malej) std::cout << k << "==" << v << " ";
    std::cout << "[" << malej.size() << "]" << std::endl;
    //////////////////////////////////////////////////////////////////////

    std::map<unsigned int, std::pair<const std::string, std::string>>
        m1{
            {1,{"kod","123"}}
            ,{2,{"kod","234"}}
    };
    // try_emplace - warunkowe tworzenie elementu(jezeli klucz istnieje, nie utworzy pary)
    // jak nie istnieje, dopiero zrobi parę z dwoch pozostalych elementow

    auto [it, ok] = m1.try_emplace(1, "kod", "456");
    std::cout << it->first << " " << it->second.second << " " << ok << std::endl; // zwraca wskaznik na element ktory juz istnieje , jego wartosc i info czy sie udalo

    auto [it2, ok2] = m1.try_emplace(3, "kod", "456");
    std::cout << it2->first << " " << it2->second.second << " " << ok2 << std::endl; // ok2 true bo wpisalismy nowy obiekt

    for (auto& e : m1)
    {
        auto& [k, v] = e;
        std::cout << k << "=>" << v.first << "," << v.second << " ";

    }
    std::cout << std::endl;
    /////////////////////////////
    for (auto& [k, v] : m1)
    {
        std::cout << k << "=>" << v.first << " " << v.second << " ";
    }
    std::cout << std::endl;
    // podpowiadanie zapewnia szybsze znalezienie poprawnego miejsca na klucz, podpowiedz jest poprawna jesli
    // iterator istniejacego elementu jest wiekszy niz element przeznaczony do wstawienia, wtedy klucz wstawi sie przed nim , zgodnie z ustawionym sortowaniem, 
    // jesli iterator jest poprawny to dodanie elementu bedzie mialo zlozonosc 1 a jesli nie to log(n)

    auto podpow = m1.end();
    podpow = m1.insert(podpow, {5,{"kod","500"} }); // zwracam pozycje nowego elementu
    podpow = m1.insert(podpow, { 4,{"kod","750"} });
    podpow = m1.insert(podpow, { 0,{"kod","900"} });
    for (auto& [k, v] : m1)
    {
        std::cout << k << "=>" << v.first << " " << v.second << " ";
    }
    std::cout << std::endl;
    // kluczy sie ogolnie nie modyfikuje, dlatego wczesniej sie usuwalo i dodawalo od nowa
    // ale od c++17 jest mozliwosc pewnej operacji
    std::map<int, std::string> m2{ {1,"Mleko"},{2,"Woda"},{3,"Kawa"},{4,"Herbata"},{5, "Piwo"}};
    for (auto& [k,v] : m2)
    {
        std::cout << k << "=>" << v << " ";
    }
    std::cout << std::endl;
    // wykorzystanie funkcji extract, gdzie klucz jest usuwany, ale nie ma skutkow ubocznych zwiazanych z pamiecia
    // ich struktura zostaje taka sama, wyciagamy elementy , zmieniam i wrzucam w mape znowu
    {
        auto temp1 = m2.extract(1); // klucz o wartosci 1 
        auto temp2 = m2.extract(5);
        //std::cout << typeid(temp1).name() << std::endl;
        std::swap(temp1.key(), temp2.key());
        m2.insert(move(temp1));
        m2.insert(move(temp2)); // insert od c++17 ma mozliwosc
    }
    std::cout << "Zamiana" << std::endl;
    for (auto& [k, v] : m2)
    {
        std::cout << k << "=>" << v << " ";
    }
    std::cout << std::string(3, '\n');
    
    // multimapa
    std::multimap<int, std::string> m{
        {1,"mapa"},
        {6,"atrapa"},
        {11,"sowa"},
        {18,"woda"},
    };
    m.insert({ { 6,"micha" }, { 11,"wicha"} });
    for (auto& [a, b] : m) std::cout << a << " " << b << std::endl;
}

