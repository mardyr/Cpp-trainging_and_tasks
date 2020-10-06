// stream insertion.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
class Test
{
    int x;
public:
    Test(int _x = 0) : x{ _x } {}
    friend std::istream& operator >> (std::istream& input, Test& obj);
    friend std::ostream& operator << (std::ostream& output, Test& obj);
};

std::istream& operator >> (std::istream& input, Test& obj)
{
    input >> obj.x;
    return input;
}
std::ostream& operator << (std::ostream& output, Test& obj)
{
    output << obj.x;
    return output;
}
int main()
{
    Test t;
    std::cin >> t;
    std::cout << t;
    return 0;
}

