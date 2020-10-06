// folding.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

template <typename ... Args> // ciag argumentow
auto function1(Args ... args) // kazdy kolejny element bedzie reprezentowany w zmiennej args
{
    return(args + ... + 0);
}
template <typename ... Args>
auto function2(Args ... args)
{
    return(args - ...)
}
template <typename ... Args>
auto function3(Args ... args)
{
    return(... - args ) // jakby funkcja wykonuje sie od tylu , (1,2,3,4) -> (-4)->((-3)(-4)->(((-2)-3)-4)->((((1-2)-3)-4)
}
int main()
{
    std::cout << function1(1, 2, 3, 4, 102.4f) << std::endl;
    std::cout << function1() << std::endl;
    std::cout << function2(1, 2, 3, 4)<< std::endl;
    std::cout << function3(1, 2, 3, 4) << std::endl;
}

