// movesema2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <utility>

struct Foo
{
    Foo();
    Foo(int i) : m_i{ i } {}

    Foo(int i, bool b, float f, std::vector<int>const& v) :
        m_i{ i }, 
        m_b{ b }, 
        m_f{ f }, 
        m_v{ v } 
    {std::cout << "Normal ref"; }


    Foo(int i, bool b, float f, std::vector<int>&& v) :
        m_i{ i }, 
        m_b{ b },
        m_f{ f }, 
        m_v{ move(v) } 
    {std::cout << "Move ref"; }

    int m_i;
    bool m_b;
    float m_f;
    std::vector<int> m_v;
};

struct Bar
{
    template <typename ...Args>
    void AddFoo(Args && ... args) // forwarding reference przyjmuje lvalue lub rvalue
    {
        
        v.emplace_back(std::forward<Args>(args)...); // forward powoduje, ze args to dalej lvalue

    }
private:
    std::vector<Foo> v;
};

int main()
{
    Bar b;
    std::vector<int> v{ 1,2,3,4,5 };
    b.AddFoo(1, true, 2.4,move(v));
    return 0;
}
