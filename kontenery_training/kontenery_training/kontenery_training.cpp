// kontenery_training.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <algorithm>
#include <functional>
#include <unordered_map>

int main()
{
    std::vector<int> v{ 1,8}; // porownywanie leksykograficzne , czyli co jest wyzej na 1 pozycji to jest wieksze
    if (!v.empty()) std::cout << v.size() << "..." << v.max_size() << std::endl;

    // operacje = <= >= <> sa mozliwe (kontenery tego samego typu)
    std::vector<int> v2{ 3,2,1 };
    std::vector<int> v3{ 1,2,3};
    std::vector<int> v4{ 1,2,3,4 };

    std::cout << (v == v2) << (v == v3) << (v == v4) << std::endl;
    std::cout << (v <= v2) << (v <= v3) << (v <= v4) << std::endl;
    std::cout << (v < v2) << (v < v3) << (v < v4) << std::endl;
    std::cout << (v > v2) << (v > v3) << (v > v4) << std::endl;
    std::cout << (v >= v2) << (v >= v3) << (v >= v4) << std::endl;

    // swap
    auto vit = v.begin();
    auto v2it = v2.begin();
    std::cout << *vit << " " << *v2it << std::endl; // 1 3
    std::cout << &v[0] << " " << v[0] << " " << &v2[0] << " " << v2[0] << std::endl;
    v.swap(v2); // SWAP tak naprawde zamienia pamiec, 
    std::cout << &v[0] << " " << v[0] << " " << &v2[0] << " " << v2[0] << std::endl;
    // po swap iteratory sa tu przypisane do elementu(pamiec),  bo wykonaniu swap, trzeba od nowa przypisac iteratory
    std::cout << *vit << " " << *v2it << std::endl; // 1 3 , tylko teraz ten vit jest iteratorem w v2 , a v2it w v
    while (vit != v2.end()) // pogubimy sie tak, lepiej znowu przypisac
    {
        std::cout << *vit<<" ";
        ++vit;
    }

    // array
    std::array<float, 10> ar{}; // same 0 beda
    for (auto& e : ar)   std::cout << e << " ";
    std::cout << std::endl;
    ar.fill(-5); // zastepuje wszystkie elementy liczba -5
    for (auto& e : ar)   std::cout << e << " ";
    std::cout << std::endl;
    
    // list

    std::list<int> l1{ 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 };
    auto pos = l1.begin();
    std::advance(pos, 4); // include <iterator>, pozwala przesunąć iterator 4 razy po elemencie, wiec z 1 jestem na 5
    std::cout << *pos << std::endl;
    pos = std::prev(pos); // cofamy sie o jedna pozycje
    std::cout << *pos << std::endl;
    pos = std::prev(pos, 2); // cofamy o dwie 
    std::cout << *pos << std::endl;
    pos = next(pos, 3);   // pos jest o 3 miejsca od pos, czyli do pos przypisuje pos przesuniety o 3 elementy
    std::cout << *pos << std::endl;
    // distance , oblicza roznice miedzy iteratorami
    std::cout << distance(l1.begin(), pos) << std::endl; // 4 pozycje
    std::cout << distance(l1.begin(), l1.end()) << std::endl; // ilosc elementow w liscie

    // iter_swap - podmienia wartosci wskazane przez iteratory. Iteratory muszą wskazywać na elementy tego samego typu

    std::cout << *l1.begin() << " " << *v.begin() << std::endl;
    iter_swap(l1.begin(), v.begin());
    std::cout << *l1.begin() << " " << *v.begin() << std::endl;

    std::vector<int> exp3 = { 1,6,8,0,3,-5,0,9,4 }; // biblioteka algorithm
    auto minimum = min_element(exp3.cbegin(), exp3.cend());
    std::cout << *minimum << " " << *max_element(exp3.cbegin(), exp3.cend());
    std::cout << std::endl;
    std::sort(exp3.begin(), exp3.end(),std::greater<int>()); // od najwiekszego, sam sort to od najmniejszego

    for (auto a : exp3) std::cout << a<< " ";
    std::cout << "dd"<<std::endl;
    
    for (int i = -5; i < 10; i++)
    {
        auto pos = find(exp3.begin(), exp3.end(), i);
        if (pos != exp3.end()) std::cout << *pos<<" "; // jesli w tym vectorze znalazłem wartosc i , to wydrukuj ja
    }
    std::cout << std::endl;

    std::reverse(exp3.begin(), exp3.end());
    for (auto a : exp3) std::cout << a << " ";
    std::cout << std::endl;
    ///////////////////////////////////////
    std::reverse(find(exp3.begin(),exp3.end(),3), exp3.end()); // znajduje iterator na miejsce w ktorym jest trojka jesli jest 
    // i od tego miejsca co jest do konca odwracam kolejnosc
    for (auto a : exp3) std::cout << a << " ";
    std::cout << std::endl;
    std::vector<int> exp4 = { 2,3,4,5 };
    std::vector<int> exp5 = { 2,4,0,0};
    std::list<int> exp6 = { 2,3,4,5 };
    std::list<int> exp7 = { 0,0 };
    // porownujac elementy z exp4 z tymi z exp5. Liczba w exp5 musi byc nie mniejsza niz elementow w exp4
    std::cout << equal(exp4.begin(), exp4.end(), exp5.begin()) << std::endl; // nie taka sama wartosc
    std::cout << equal(exp4.begin(), exp4.end(), exp6.begin()) << std::endl; // taka sama wartosc 1

    // kopiowanie do wartosci z wektora do listy
    //1 . najpierw robie resize listy, zeby zwiekszyc pamiec, bo to nie jest insert tylko copy
    exp7.resize(exp4.size(), -5); // zwiekszam size i w te puste miejsca wstawiam -5
    for (auto a : exp7) std::cout << a << " ";
    std::cout << std::endl;
    
    std::copy(exp4.begin(), exp4.end(), exp7.begin()); // od do zrodlo , a tylko begin drugiego
    for (auto a : exp7) std::cout << a << " ";
    std::cout << std::endl;

    std::vector<int> col = { 1,2,3,4,4,4,5,6 };
    std::remove(col.begin(), col.end(), 4); // usuwam wszystkie 4
    for (auto& i : col) std::cout << i << " ";
    std::cout << std::endl;
    // funkcja remove zwraca nowy koniec kontenera
    col = { 1,2,3,4,4,4,5,6 };
    auto newend = remove(col.begin(), col.end(), 4);
    for (auto i = col.begin(); i != newend; i++)
    {
        std::cout << *i << " ";
    } std::cout << std::endl;
    std::cout << "Skasowano elementow = " << distance(newend, col.end()) << std::endl; // tyle elementow trzeba jeszcze usunac

    col.erase(newend, col.end()); // a tu usune ten nadmiar
    for (auto i : col) std::cout << i << " " ;
    std::cout << std::endl;

    /////////////////////////////////////

    std::list<int> li = { 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 };
    auto newE = std::remove_if(li.begin(), li.end(), [](auto& e) { return e >= 4; }); // usuwam elementy jesli są większe lub równe 4
    // pamietajmy, że jak remove to pozniej trzeba dowalic erase, bo removeif jest ogolne
    li.erase(newE, li.end());
    li.remove(1); // metoda wlasna listy , usuwam wszystkie 1
    for (auto a : li) std::cout << a << " ";
    std::cout << std::endl;

    std::unordered_map<int, int> myMap{ {-1,0},{0,0},{1,1},{2,2},{3,3},{1,10},{1,20} };
    for (auto i : myMap) std::cout << i.first << ":" << i.second << std::endl;

    for_each(myMap.begin(), myMap.end(),
        [](const auto& p) {std::cout << p.first << "*" << p.second + 1 << "\t"; });


}

