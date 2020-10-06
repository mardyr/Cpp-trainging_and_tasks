// FunctObj.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

struct AddFunctor
{

    AddFunctor(int x) : m_x{ x } {}

    int operator()(int x) const
    {
        return m_x + x;
    }
private:
    int m_x;
};

int main()
{
    AddFunctor a(5);
    std::cout << "Sum is equal: " << a(7) << std::endl;
}

