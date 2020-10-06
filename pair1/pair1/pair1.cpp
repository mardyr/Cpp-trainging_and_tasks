// pair1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
int main()
{
    std::pair<int, int> p1(5, 10);
    std::cout << typeid(p1).name() << std::endl;

    auto p2(p1); // konstruktor kopiujący z p1

    std::pair<double, double> pd(p1); // konwersja z int do double

    std::cout << p1.first << " " << p1.second << std::endl;
    
    ++p2.second;

    std::cout << p2.first << " " << p2.second << std::endl;

    std::cout << (p1 == p2) << (p1 != p2) << (p1 > p2) << (p1 < p2) << std::endl; // (5,10) vs (5,11)

    p2.first = 4; p2.second = 11;

    std::cout << (p1 == p2) << (p1 != p2) << (p1 > p2) << (p1 < p2) << std::endl; // (5,10) vs (4,11) 0110

    std::cout << &p1 << " " << &p2 << std::endl;
    p1.swap(p2);  //zamiana czyli do p1 daje p2 a p2 do p1
    std::cout << &p1 << " " << &p2 <<std::endl; // adresy sie nie zmienily
    std::cout << p1.first << " " << p1.second << std::endl;
    std::cout << p2.first << " " << p2.second << std::endl;

    auto p3 = std::make_pair(1.0,std::string("Kaszanka jest smaczna"));
    // klucz double string value
    std::cout << typeid(p3).name() << std::endl;
    std::cout << p3.first << "  " << p3.second << std::endl;
    
    auto p4 = std::make_pair(10,std::vector<int>{100, 200, 300});
    std::cout << typeid(p4).name() << std::endl;
    std::cout << p4.first << " " << p4.second[2] << std::endl;

    std::pair < std:: string, std::string >*p_ptr;
    p_ptr = new std::pair<std::string, std::string>; // rezerwuje sobie pamiec na obiekt typu pair
    p_ptr->first = "RAZ";
    p_ptr->second = "DWA";
    std::cout << p_ptr->first << " " << p_ptr->second << std::endl;
    delete p_ptr;

    typedef std::pair<std::string, double> myPair;
    
    myPair p21{ "abc",2.34 };
    std::cout << p21.first << " " << p21.second << std::endl;

    std::pair nowa(std::string("mordo"), 102.3f); // od c++17 nie musze podawac pair<string,float> nazwa{wartosc1,wartosc2} 
    std::cout << nowa.first << "  " << nowa.second << std::endl;
    std::cout << typeid(nowa).name() << std::endl;



}


