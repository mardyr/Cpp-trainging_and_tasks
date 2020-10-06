// nth_element.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> v{ 4,5,2,3,2,11,8,9,14,12,13 };
    std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
    std::cout << v.at(v.size() / 2) << std::endl;

    std::nth_element(v.begin(), v.begin() + 2, v.end(),std::greater<int>()); // 3 z najwiekszych czyli 12
    std::cout << v.at(2);
}

