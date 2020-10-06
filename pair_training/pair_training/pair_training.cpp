// pair_training.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::pair<double, std::string>* ptr;
    ptr = new std::pair<double, std::string>{ 23.4,std::string("haloo") };
    std::cout << ptr->first << "  " << ptr->second << std::endl;
    delete ptr;

    auto p = std::make_pair(23.1f, 21.1);
    std::cout << typeid(p).name() << std::endl;

    std::pair<std::string, std::vector<int>> p4( "ale", {30,30,303,3} );

    std::cout << p4.first << " " << p4.second;
}