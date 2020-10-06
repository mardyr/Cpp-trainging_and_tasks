// duple.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <tuple>
#include <vector>

class Base
{
    int var;
public:
    Base(){}
    Base(int v) : var{v} {}
    Base(const Base& obj) : var{ obj.var } {}
    Base& operator = (const Base& obj)
    {
        this->var = obj.var;
        return *this;
    }
    void print()
    {
        std::cout << var << std::endl;
    }
};
int main()
{
    Base* b = new Base(43);

    Base* d = new Base();
    *d = *b;

    std::tuple<int,std::tuple<int, float>> t1(5,{ 3, 3.5 });
    
    std::cout << std::get<0>(t1) << " " << std::get<1>(std::get<1>(t1)) << std::endl;

    auto& [a, x] = t1;
    auto& [i, j] = x;
    std::cout << a << ":" << i << "--" << j << std::endl;

}
