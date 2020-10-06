// stopcopyandadress.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

class Base
{
    int _x;
public:
    Base() : Base(0) {};
    Base(int x) : _x{ x } {}
    Base(const Base& rhs) = delete;
    Base& operator = (const Base& rhs) = delete;
    Base* operator &(const Base& rhs) = delete;
};


int main()
{
    std::cout << "Hello World!\n";
}

