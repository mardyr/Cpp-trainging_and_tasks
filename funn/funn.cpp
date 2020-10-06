// funn.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T=int>
class Numbers
{
public:
    Numbers(const int&value);
    template<typename U>
    auto add(T lhs, U rhs){ return lhs + rhs; }
    int getVal() const { return _value; }
private:
    int _value;
};


int main()
{
    Numbers<> n = Numbers<>(2);
    Numbers<float> n1 = Numbers<float>(4.3f);
    float i = n1.getVal();
    std::cout << i << std::endl;

    auto val = n.add(n.getVal(), 18.2);
    std::cout << val << std::endl;
    return 0;
}

template<typename T >
Numbers<T>::Numbers(const int& value) : _value{ value } {}

