// function_pointer.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

/*int add(int a, int b)
{
    return a + b;
}
int fun1(int(*someFun)(int, int))
{
    int c = someFun(1, 2);
    return c;
}*/

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

typedef int(*mathFun)(int, int);

mathFun fun(int type)  // int(*fun(int type))(int,int)
{
    if (type == 1) return add;
    else if (type == 2) return sub;
}

    

int main()
{
    int c = fun1(add);
    std::cout << c << std::endl;


    return 0;
}

