// array.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <array>

int main()
{
    
    std::array<std::string, 6> names{ "Janusz","Grazyna","Czesiek" };

    // mozna  elegancko
    for (auto& e : names)
    {
        e += "s"; // zeby potwierdzic, ze lecim na orginale
        std::cout << e << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < names.size(); i++) // a mozna tez oldfashion i mamy indeks tez
        std::cout << i << ":=" << names[i] << " " << std::endl;

    std::cout << "Korzystam z iteratorow: ";
    for (auto iterator = names.begin(); iterator != names.end(); iterator++) {
        std::cout << *iterator << " "; // wyluskuje wartosc na ktora wskazuje iterator
    }
    std::cout << std::endl;
    auto it = names.begin();
    std::cout << typeid(it).name() << std::endl;

    std::array<int,20>tab{1,2,4,6};
    std::cout << "tab.size()" << tab.size() << std::endl;
    
    std::cout << "INDEKS O = " << tab.at(0) << std::endl;

    //std::cout << "INDEKS O = " << tab.at(20) << std::endl; // at kontroluje zakres spoko rzecz bardzo
    names.back() = "Jonasz";
    std::cout << names.back() << std::endl;
    std::cout << names.front() << std::endl;

    std::cout << "Memory:" << names.data() << std::endl;
   
    std::array<char, 10>x{};

    strcpy_s(x.data(), x.size(), "dero\0");

    std::cout << x.data() << std::endl;
    

}


