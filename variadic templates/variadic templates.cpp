// variadic templates.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <sstream>

template <typename T>
std::string toStringInstance(const T& a)
{
    std::stringstream ss;
    ss << a;
    return ss.str();
}
template<typename ... Param>
std::vector<std::string> toString(const Param& ... p)
{
    return { toStringInstance(p)... };
}

int main()
{
    const auto vec = toString("Martin", 111.2, 0, -9999, 1.4f);
    
    for (const auto& i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}

