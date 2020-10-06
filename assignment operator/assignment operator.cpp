// assignment operator.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

class Base
{
    int x;
public:
    Base(int x=0) : x{x}{}
    friend class Test;
};

class Test {
    int* x;
public:
    Test(int val = 0) :x{ new int(val) } {}
    void setX(int val) { *x = val; }
    void print() { std::cout << "OUTPUT: " << *x << std::endl; }
    ~Test() { delete x; }
    Test& operator = (const Test& rhs)
    {
        if (this != &rhs) *x = *rhs.x;

        return *this;
    }
    Test& operator = (const Base& rhs)
    {
         *x = rhs.x;
        return *this;
    }
    Test(const Test& rhs)
    {
        x = new int(*rhs.x);

    }
};


int main()
{
    Test t1(10);
    Test t2;
    t2 = t1;
    t1.setX(20);
    t1.print();
    t2.print();
    Base b(110);
    t1 = b;
    t1.print();

    return 0;
}

