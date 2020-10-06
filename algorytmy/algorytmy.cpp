// algorytmy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <algorithm>

bool myfunction(int i, int j)
{
    return (i == j);
}


int main()
{
    std::vector<int> v(3, 5);
    for (auto i : v) std::cout << i << " ";
    v.push_back(1);
    v.push_back(123);
    v.push_back(11);
    v.insert(v.begin(), 3, 300);
    v.insert(v.begin(), 18);
    v.insert(v.begin(), 21);
    std::cout << std::endl;
    std::vector<int>::iterator it = v.begin();
    
    it = std::adjacent_find(it, v.end(),myfunction);
    if (it != v.end())
    {
        while (*it == *(it + 1))
        {
            std::cout << *(it++);
          
        }
    }
    
}
