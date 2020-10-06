// overload typecast.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

double dollartoRupeeExchangeRate() { return 71.5; }
class Dollar;
class Rupee
{
    double rupee;
public:
    Rupee(double );
    void print();
    operator Dollar();
};

class Dollar
{
    double dollar;
public:
    Dollar(double );
    void print();
    operator Rupee ();
};

Rupee::Rupee(double d = 0) : rupee{ d } {}
void Rupee::print() { std::cout << rupee << std::endl; }
Rupee::operator Dollar() { return Dollar(rupee * 21.1);}

Dollar::Dollar(double d = 0) : dollar{ d } {}
void Dollar::print() { std::cout << dollar << std::endl; }
Dollar::operator Rupee() { return Rupee(dollar * dollartoRupeeExchangeRate()); }
int main()
{
    Rupee r(10);
    Dollar d =r;
    d.print();
}

