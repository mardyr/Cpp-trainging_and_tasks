// movesema.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <utility>
#include <vector>

struct Foo
{

    Foo(std::vector<int>&& v) : v(move(v)) // tutaj v jest lvalue 
    {
       
    }
    /* rule of 5
     Foo() = default;
    Foo(const Foo& other) = default;
    Foo& operator=(const Foo& other) = default;
    Foo(Foo&& other) = default;
    Foo& operator=(Foo&& other) = default;
    virtual ~Foo() = default; // inheritance class
    
    */
    std::vector<int> v;
};

void FillVector(std::vector<int>& v)
{

}

int main()
{
    std::vector<int> v;
    FillVector(v);
    if (!v.empty())
    {
        Foo f(move(v));// tutaj przez move v jest rvalue

    }
    else
    {

    }

}

