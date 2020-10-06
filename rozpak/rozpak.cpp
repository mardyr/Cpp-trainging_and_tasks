// rozpak.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <set>
#include <functional>
#include <vector>

class Person
{
public:
    int age;
    std::string name;
    bool operator > (const Person& rhs) const { return age > rhs.age; }
    bool operator < (const Person& rhs) const { return age < rhs.age; }
};

int main()
{
    std::vector<int> vec {1, 2, 4, 2, 1, 4, 11, 3, 8, 11, 2};

    auto newend = std::remove(vec.begin(), vec.end(),11);
    for (auto& i : vec) std::cout << i << " ";
    std::cout << std::endl;
    vec.erase(newend, vec.end());
    for (auto& i : vec) std::cout << i << " ";
    std::cout << std::endl;

    std::set<Person,std::greater<Person>> Set = { {30,"Martin"},{21,"Dunkan"},{25,"Maciej"},{18,"Roman"} };

    for (auto& p : Set)
    {
        std::cout << p.age << " " << p.name << std::endl;
    }

    return 0;
}

