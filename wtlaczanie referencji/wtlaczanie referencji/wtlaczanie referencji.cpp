// wtlaczanie referencji.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
// UNIKANIE NADMIARU STOSOWANIA SZABLONOW
#include <iostream>
#include <functional>


template<typename T>
void fufu(T a)  // tutaj mamy kopie
{
    std::cout << "Fufu: " << a++ << std::endl;
}
template<typename T>
void fofo(T a)
{
    std::cout << "Fofo: " << a << std::endl;
}
int fifi(float a, std::string b)
{
    std::cout << a << " " << b << std::endl;
    return static_cast<int>(a * 2); // rzutuje na int
}
int main()
{
    int x{ 10 };
    fufu(x);
    std::cout << x << std::endl;
    fufu(std::ref(x));
    fofo(std::cref(x));

    // jakiego typu jest ta referencja
    std::vector<std::reference_wrapper<int>> temp; // obiekty ktore sa takiego typu jakiego jest wywolanie ref na jakiejs zmiennej typu int
    // czyli reference_wrapper to jest ref(x) - to jest np 10 , 11 , czyli to co przesylamy przez referencje
    temp.emplace_back(std::ref(++x)); // tu ciagle zwiekszamy x
    temp.emplace_back(std::ref(++x));
    temp.emplace_back(std::ref(++x));
    std::cout << typeid(std::ref(x)).name() << std::endl;

    for (auto& i : temp) std::cout << i << " "; // wiec tutaj bedziemy miec 14,14,14
    std::cout << std::endl;

    std::function<int(float, std::string)>f; // tworze jawnie obiekt funkcyjny
    f = fifi;
    std::cout << f(3, "elo") << std::endl;
}


