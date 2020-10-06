// class_templates.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Container.h"
// CLASS SPECIALIZATION
template<>
class Container<char>
{
public:
    explicit Container(char&& arg);
    char uppercase();

private:
    char element;

};
//-------------------------------------------------------
// PARTIAL SPECIALIZATION
template<typename T,typename U>
struct Class 
{
    Class() { std::cout << " Class <T,U> \n"; }
};

template<typename T>
struct Class<T, T>
{
    Class() { std::cout << "Class <T,T> \n"; }
};

template<typename T>
struct Class<T, int>
{
    Class() { std::cout << "Class<T,int>\n"; }
};

template<>
struct Class<int, int>
{
    Class() { std::cout << "Class <int,int>\n"; }
};

int main()
{

    Class<int, double> a;
    Class<int, int> b;
    Class<float, int> c;

    /*
    Container<int> integer(5);
    std::cout << integer.increase() << std::endl;
    Container<char> character('a');
    std::cout << character.uppercase() << std::endl;
    */
    return 0;
}

Container<char>::Container(char&& arg) : element{ arg } {}

char Container<char>::uppercase()
{
    if ((element >= 'a') && (element <= 'z'))
    {
        element += 'A' - 'a';
    }
    return element;
}