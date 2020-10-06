// new and delete.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

class Test
{
    int x;
public:
    Test(int x = 0) :x{ x } {}
    void* operator new (size_t size)
    {
        std::cout << "Overloaded new operator Size: " << size << std::endl;
        void *p = malloc(size);
        return p;
    }
    void operator delete(void* p)
    {
        std::cout << "Overloaded Delete Operator" << std::endl;
        free(p);
    }

};

void *operator new (size_t size, int val)
{
    std::cout << "with val Overloaded new operator size " << size << std::endl;
    void* p = malloc(size);
    if (p != nullptr) { *static_cast<int*>(p) = val; }
    return p;
}
void* operator new(size_t size)
{
    std::cout << "HEAP ALLOCATION\n";
    void* p = malloc(size);
    return p;
}
void operator delete(void* p)
{
    std::cout << "Delete operator\n";
    free(p);
}
/*
void* operator new [](size_t size)
{
    std::cout << "Overloaded new array operator" << std::endl;
    void* p = malloc(size);
    return p;
}
void operator delete[](void*p)
{
    std::cout << "Delete overloaded array operator\n";
    free(p);
}
*/
int main()
{
    int* z = new(10) int;
    delete z;
    int* y = new int;
    delete y;
    //int* x = new int[10];
    //Test* t = new Test();
   // delete []x;
   // delete t;
}

