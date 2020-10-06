// plain enum and enum class.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

enum Color1{red,green,blue};
void fun(int c)
{
    switch (c)
    {
        case red: std::cout << "red\n"; break;
        case green: std::cout << "green\n"; break;
        case blue: std::cout << "blue\n"; break;
    }
}




int main()
{
    
    fun(0);
    fun(1);
 enum class Color2 {red , green,blue};
 Color2 c2 = Color2::red;

 switch (c2)
 {
     case Color2::red : std::cout << "red\n"; break;
     case Color2::green: std::cout << "green\n"; break;
     case Color2::blue: std::cout << "blue\n"; break;
 }

    return 0;
}

