
// templates_in_templates.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

template<template<int N> typename C, int K>
void f(C<K>)
{
    std::cout << K << std::endl;
}

template<int N>
class SomeClass {};
/////////////////////////
void print2()
{

}
template<typename T,typename...D>
void print2(T param1, D ... param2)
{
    std::cout << param1 << std::endl;

    print2(param2 ...);
}

int main()
{
    SomeClass<1> c1;
    SomeClass<2> c2;

    f(c1); // wywolanie funkcji na argumencie c1, czyli na SomeClass<1> , czyli N=K
    f(c2); // wywolanie funkcji na argumencie c2 , czyli na SomeClass<2> , czyli N=K
    std::cout << std::string(60, '*');
    std::cout << "\n";
    print2(1, 2, 3, "Hello", 'a', 'b', 2.3, 4.1);


}

