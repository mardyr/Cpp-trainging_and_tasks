// enumtest.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

enum class Color {red,green,blue};
void func(Color cl)
{
    switch (cl)
    {
        case Color::red: std::cout << " red color\n"; break;
        case Color::blue: std::cout << " blue color\n"; break;
        case Color::green: std::cout << " green color\n"; break;
        default: std::cout << "Different color\n"; break;
    }
}
int main()
{
    Color c = Color::green;
    func(c);

}

