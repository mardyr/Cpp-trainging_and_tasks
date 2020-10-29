
#include <iostream>


template< typename T>
class LessThan
{
    T x;
public:
    LessThan(T _x) :x{ _x } {}
    bool operator()(T i) { return i < x; }
        
};


int main()
{
    LessThan<int> t(40);
    bool a = t(41);
    std::cout << a << "\n";
}

