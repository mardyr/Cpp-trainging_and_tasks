// templ.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <sstream>

template<typename T>
T addAll(std::vector<T> list)
{
    T count = 0;
    for (auto& elem : list) { count += elem; }

    return count;
}

template<>
std::string addAll(std::vector<std::string>list)
{
    int count = 0;
    for (auto& str : list)
    {
        for (const char& elem : str)
            count += elem;
    }
    std::ostringstream ostr;
    ostr << count;
    std::string stringCount = ostr.str();
    return stringCount;
}


int main()
{
    std::vector<int> VecInt = { 4,3,2,5,6,1 };
    std::vector<double> VecDouble = { 4.0,3.0,2.0,5.0,6.0,1.0 };
    std::vector<std::string> VecString = { "ab" };
    std::cout << addAll(VecInt) << std::endl;
    std::cout << addAll(VecDouble) << std::endl;
    std::cout << addAll(VecString) << std::endl;
    return 0;
}

