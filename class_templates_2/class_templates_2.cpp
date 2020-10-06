// class_templates_2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>


// default template parameters
template <typename T = int>
class Add
{
public:
    Add() {}
};
////////////
// Type template parameters , non type template parameters
template<typename T, int N>
class myArray
{
public:
    size_t getSize() const { return N; }
private:
    T m_Array[N];

};

int main()
{

    myArray<int, 5> array;
    std::cout<<array.getSize();
    Add<double> dodaj;
    Add<> x;
}

