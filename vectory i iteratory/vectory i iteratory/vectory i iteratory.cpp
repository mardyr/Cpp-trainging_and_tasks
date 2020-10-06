// vectory i iteratory.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>

int main()
{

    std::vector<int> vec1(20, 5); // 20 elementow kazda o wartosci 5
    for (auto& i : vec1)
        std::cout << i << "::";
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////
    std::vector<int> v{ 2,32,21,200,1 };

    for (auto&& it = v.begin(); it != v.end(); it++)
    {
        *it += 5;
        std::cout << *it << " ";
    }
    auto it = v.begin() + 3;
    std::cout << std::endl;// czyli tworze iprzesuwam iterator z 2 na 200 ( no 205 :)), dostep swobodny iteratorow
    std::cout << *it << std::endl; // booom
//////////////////////////////////////////////////////////////// 
     //std::vector<int>::const_iterator iter = v.begin(); // bez auto tworze sobie iterator staly, normalnie bez const

     //while (iter != v.end()) std::cout << *it++ << "  "; // pobieram i przesuwam i drukuje

    std::cout << v.front() << std::endl; // wartosc to jak wyluskanie
    std::cout << v.back() << std::endl;
    /////////////////////////////////
    // cbegin(), niemodyfikowalny iterator, czyli moze sie poruszac ale nie moze zmieniac wartosci tego w srodku 
    // crbegin() , to samo tylko reverse, wiec od tylu kontenera leci
    std::cout << *v.cbegin() << std::endl;
    std::cout << *--v.cend() << std::endl; // ide na lewo, wiec najpierw dekrementacja a pozniej wyluskanie , cend nie wskazuje na ostatni tylko na za ostatni
    ////////////////////
    std::cout << *++v.crbegin() << std::endl; // ide na koniec zbioru i pozniej ide do przodu, wiec ide na przedostatni, dodajac cofamy sie
    // poprostu odwracamy kontener i jedziemy
    for (auto&& ir = v.crbegin(); ir != v.crend(); ir++) std::cout << *ir << " "; // czyli od pierwszego elementu lecimy do ostatniego, w stosunku do wczesniejszego kontenera lecimy od ostatniego do pierwszego i stopujemy za pierwszym
    std::cout << std::endl;
    /////////////////////////////////////////////////////
    // capacity - na ile zarezerwowano miejsca
    // reserve(TYLE) - rezerwuje pamiec na tyle elementow
    std::cout << "ZABAWA Z WEKTOREM" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::vector<int> v1{ 1,2,3,4,5,6,7,8,9,10,2,42,1,2 };
    std::cout << &v1[0] << std::endl;
    std::cout << v1.at(10) << " " << v1.size() << std::endl; // liczymy od zera 
    v1.push_back(5); // na koniec dodaje 5;
    v1.pop_back(); // sciagam to z konca
    v1.reserve(100); // rezerwuje miesce na 100 intow , REALOKACJA NASTAPILA
    std::cout << v1.size() << " " << v1.capacity() << std::endl; // zajmuje 12 miejsc ale mam miejsce na 100 
    std::cout << &v1[0] << std::endl;
    std::cout << v1.capacity() << std::endl;
    //==========================================================
    //1 METODA
    //==========================================================
    auto newEnd = remove(v1.begin(), v1.end(), 2); // usuwam wszystkie 2 z wektora, i zwracam iterator na ostatni element
    // powinienem miec mniej elementow jezeli byly 2 , i iterator wskazuje na ostatni element ktory zostal wiec jak bylo 12 liczb(11 indeks(
    // i usunalem dwie liczby to na 9 indeksie
    for (auto& i : v1) std::cout << i << " "; // usuwam 2 , wszystkie elementy przesuniete , ale tyle ile usunalem tyle sie powtarza ostanich elementow
    std::cout << "Rozmiar " << v1.size() << std::endl;
    // mialem 1 2 3 4 5 6 2 6 7 8 , remove -> 13456678(tu new End)78

    std::cout << &v1[0] << std::endl; // TO SAMO MIEJSCE W PAMIECI
    std::cout << v1.capacity() << std::endl;
    // zeby zakonczyc proces remove musze usunac te zdublowane
    std::cout << "USUWAM TE DUBLE" << std::endl;
    // jak element ktory chce usunac do removea jest na koncu to luz tez sie usunie
    v1.erase(newEnd, v1.end());
    for (auto& i : v1) std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "Rozmiar: " << v1.size() << std::endl;
    std::cout << &v1[0] << std::endl;
    std::cout << v1.capacity() << std::endl << std::endl; // adres ten samo, bo nie ma potrzeby, mamy w ciul pamieci, można wrzucac
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "WJEZDZAM" << std::endl;
    v1.push_back(32);
    v1.push_back(33);
    std::cout << v1.capacity() << std::endl;
    /// ok skonczylem wrzucac, no to zwalniam to co mi zostalo
    v1.shrink_to_fit(); // dopasuje pamiec do size'a
    std::cout << &v1[0] << std::endl; // przerzuce gdzies gdzie mi wygodnie
    std::cout <<"Capacity: "<< v1.capacity() << std::string(2, '\n');
    //==========================================================
    //2 METODA
    //==========================================================
    // fajna metoda gdy nie zalezy na sortowaniu wartosci
    do
    {
        if (auto FoundIndex = find(v1.begin(), v1.end(), 5); FoundIndex != v1.end())
        {
            *FoundIndex = v1.back();
            v1.pop_back();
        }
        else break;

    } while (1);
    for (auto& i : v1) std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "Rozmiar: " << v1.size() << std::endl;
    std::cout <<"Capacity: "<< v1.capacity() << std::endl;
    std::cout << &v1[0] << std::endl;
    v1.shrink_to_fit();
    std::cout << std::string(1, '\n');
    std::cout << "Capacity po shrinku: " << v1.capacity() << std::endl; // shrink to fit wiaze sie z realokacja
    std::cout << &v1[0] << std::endl;
    v1.resize(50, 1); // zwieksza size do 50 , i nowe zapelniam 1
    std::cout << v1.size() << " " << v1.capacity() << " " << &v1[0] << std::endl; // resize to tez realokacja
    for (auto x : v1) std::cout << x << " ";
}           

