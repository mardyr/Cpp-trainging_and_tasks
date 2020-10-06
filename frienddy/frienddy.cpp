// frienddy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

class Base
{
public:
    int d;
    int fun(char c) { std::cout << "Character\n"; return c; }
};

class Derived : public Base
{ 
public:
    int a, b;
    //using Base::fun;
    void fun() { std::cout << "Call on me\n"; }
    int fun(int d) { std::cout << "Integer\n"; return d; }
};



int main()
{
    int arr[2] = { [0] = 5,[1] = 32};

    Derived* d = new Derived;
    d->fun('a');
    d->fun(2);
   // d->fun(); 

    return 0;
}

