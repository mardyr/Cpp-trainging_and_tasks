// ConsoleApplication30.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#include <memory>

void passByConstRef(const std::unique_ptr<int>& ptr)
{
    *ptr += 10;
    std::cout << "Value ptr is equal: " << *ptr << std::endl;
}

int main()
{
    double d = 3.2;
    std::unique_ptr<int> pt = std::make_unique<int>(20);
    auto p = std::make_unique<decltype(d)>(d);
    std::cout << *p << std::endl;
    /// usage 1 
    std::size_t runTime{ 10 };
    std::unique_ptr<int[]> array = std::make_unique<int[]>(runTime); // alokowanie tablicy o rozmiarze 10
    auto testData = std::make_unique<int[]>(1000);
    ///
    auto intptr = std::make_unique<int>(11);
    passByConstRef(intptr);
    ////////

    std::unique_ptr<int> ip(new int);

    int axa = 8;
    *ip = axa;
    std::cout << *ip << std::endl;
    std::cout << std::string(60, '*') << std::endl;

    ///////////////////////////////////////////////////////////////
    std::set<std::pair<int, int>> intervals;
    intervals.insert({ 1,5 });
    intervals.insert({ 40,100 });
    intervals.insert({ 10,20 });
    intervals.insert({ 250,400 });

    for (auto& [k, v] : intervals) { std::cout << k << " " << v << std::endl; }
    int number = 50;

    auto it = intervals.upper_bound({ number,INT_MAX });
    it--;
    std::cout << "Number: " << number << " is between " << it->first << " " << it->second << std::endl;
}

