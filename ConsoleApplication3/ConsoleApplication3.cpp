// ConsoleApplication3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>

template < typename ... Args>
auto sum(Args ... param)
{
    return(param + ... + 0);
}
template <typename T, typename ... Args>
void vecInsertion(T& vec, Args ... param)
{
    (vec.emplace_back(param), ...);
}
template<typename T>
void show(T t)
{
    for (const auto element : t)
    {
        std::cout << element<<" ";
    }
    std::cout<<std::endl;
}
template<typename T, typename ... Args>
bool within(T min, T max, Args... param)
{
    return((min <= param && param <= max) && ...);
}


int main()
{
    std::cout << sum(2, 4.3, 2, 4, 11, 3) << std::endl;
    std::vector<int> v;
    vecInsertion(v, 100, 200, 1, 3, 4, 2, 2, 1);
    show(v);
    std::cout << within(10, 20, 21);
}

