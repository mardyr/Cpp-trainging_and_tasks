// 4.6.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <utility>
class Ork
{
    std::string name;
    int stamina;
    int strength;
public:
    Ork(std::string n, int s, int stren) : name{ n }, stamina{ s }, strength{ stren }{}
    std::string generateName();
    int setStamina();
    int setStrength();
};
int main()
{
    srand(time(NULL));
    std::vector<Ork> Orc;
    for (int i = 0; i < 10; i++)
    {
        Orc.push_back(Ork)
    }
   
}
std::string Ork::generateName()
{
        char name[] = "";
        int n;
        for (int i = 0; i < 5; i++)
        {
            n = rand() % 25 + 97;
            if (i == 0) { n -= 32; }
            name[i] = char(n);
        }
}
int Ork::setStamina()
{
    stamina = rand() % 100 + 1;
    return stamina;
}
int Ork::setStrength()
{
    strength = rand() % 100 + 1;
    return strength;
}
