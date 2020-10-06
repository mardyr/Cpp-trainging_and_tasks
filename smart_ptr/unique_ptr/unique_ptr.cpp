// unique_ptr.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <memory>
class MyClass
{
public:
    MyClass()
    {
        std::cout << "Konstruktor\n";
    }
    ~MyClass()
    {
        std::cout << "Destruktor\n";
    }
};

int main()
{
    std::unique_ptr<MyClass> ptr(new MyClass); // tutaj jesli nie chcemy odrazu inicjalizowac
    size_t size{ 10 };
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
    std::unique_ptr<int[]> tab = std::make_unique<int[]>(size);
    tab[2] = 3;
    for (int i = 0; i < size; ++i)
    {
        std::cout << tab[i] << std::endl;
    }
    return 0;
}