// rozpakowywanie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <array>
#include <map>

std::pair<int, int> function1(int x, int y)
{
    return std::make_pair<int,int>(x * 2, y * 4);
}
class C1
{
public:
    std::string w = "slowo";
    int a = 55;
    double b = 999.9;
    int z = 0;
    C1()
    {
        std::cout << this << "+C1=" << a << " " << b << " " << w << std::endl;
    }
    C1(const std::string&& setw, const int&& seta, const double&& setb)
    {
        w = setw;
        a = seta;
        b - setb;
        std::cout << this << " +C1= " << a << " " << b << " " << w << std::endl;
    }
    ~C1()
    {
        std::cout << this << " -C1= " << a << " " << b << " " << w << std::endl;
    }
    void show()
    {
        std::cout << this << " Info: " << w << "," << a << "," << b << std::endl;
    }
};


int main()
{
    std::array<int,3> a{1,2};

    auto& [x1,x2,x3] = a ;

    std::cout << x1 << ":" << x2 << ":" << x3 << std::endl;

    auto&& [v1, v2] = function1(5, 10); // po funkcja zwraca r wartosc to jest jakas liczba / para liczb  , i bierzemy referencja do r wartosci
    std::cout << v1 << " " << v2 << std::endl;

    C1 obiekt_c1("lol", 23, 3.2);
    auto& [v3, v4, v5,v6] = obiekt_c1; // jedziemy na orginale
    std::cout <<"hola"<< v3 << "," << v4 << "," << v5 <<" "<< v6<<std::endl;
    v3 = "zmiana!";
    std::cout << &obiekt_c1 << " " << obiekt_c1.w << std::endl;

    std::map<std::string, C1> mapka // mapa to zbior par
    {
        {"raz",C1("A",2,2.5)}, // klucz wartosc
        {"dwa",C1("B",4,21.2)}
    };

    std::cout << &mapka["raz"] <<std::endl;
    std::cout << &mapka["dwa"] << std::endl;

    for (auto& [key, value] : mapka) // dla kazdego elementu z mapka, wpisz klucz do key i wartosc do value
    {
        std::cout << "[" << key << "]" << std::endl;
        value.show(); // value to jest obiekt klasy C1
    }
    
    

}

