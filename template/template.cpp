
#include <iostream>
template<class T,class T2>
auto getMax(T x, T2 y)
{
    return x > y ? x : y;
}

int const& max(const int& a, const int& b)
{
    std::cout << "int max(int,int)\n";
    return a > b ? a : b;
}
template<class T1>
T1 const& max(T1 const& a, T1 const& b)
{
    std::cout << "T max(T,T)\n";
    return a > b ? a : b;
}

template<typename T1>
T1 const& max(T1 const& a, T1 const& b,T1 const& c)
{
    std::cout<<"T max(T,T,T)\n";
    return max(max(a, b), c);
}

int main()
{
    ::max(10.0, 20.0);
    ::max(10, 1);
    ::max<double>(12, 12.2);
    ::max<>(10, 10);
    ::max(1, 4, 3);

    return 0;
}

