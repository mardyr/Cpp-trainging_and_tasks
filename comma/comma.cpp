// comma.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

template<class T>
void func(T a)
{
    static int var = 10;
    std::cout << ++var << std::endl;
}
///

template<class T>
class Temp
{
    int a;
public:
    static T var;
    void PrintVal() { std::cout << ++var << std::endl; }
};

template<class T>
T Temp<T>::var = 0;

int main()
{
    Temp<int>t;
    t.PrintVal();
    Temp<int>t1;
    t1.PrintVal();
    Temp<float>f;
    f.PrintVal();

    std::cout << std::string(60, '=') << std::endl;
    func<int>(10);
    func<float>(2.43f);
    func<double>(1.1);
    func<int>(121);
}
