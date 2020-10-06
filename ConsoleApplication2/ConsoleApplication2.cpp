// ConsoleApplication2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>


class Base
{
    int x,y;
public:
    Base() : Base(0,0) {}
    Base(int&&a) : Base(a, 0) {}
    Base(int a, int&&b) : x{ a }, y{ b } {}
    Base& getX() { return *this ; }
    Base& getY() { return *this; }
    void Print() { std::cout << x << " " << y << std::endl; }

};


int main()
{
    Base d;
    d.getX().getY().Print();
    Base d1(15);
    d1.getX().getY().Print();
    Base d2(15, 21);
    d2.getX().getY().Print();



      
}

