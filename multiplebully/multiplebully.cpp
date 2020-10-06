
// multiplebully.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <tuple>
#include <array>

std::tuple<std::string, int, char> fun(bool flg)
{
    if (flg) return std::make_tuple("Mee", 23, 'x');
    else return std::make_tuple("Bee", 11, 'z');
}
int main()
{
    auto [a, b, c] = fun(true);
    std::cout << a << " " << b << " " << c << std::endl; 
    const std::array<int, 5> Arr;

}

