// overload=.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

/*class Base
{
    int x;
public:
    Base() {}
    Base(const Base& rhs)
    {
        x = rhs.x;
        std::cout << "Copy constructor\n";
    }
    Base& operator = (const Base& rhs)
    {
        x = rhs.x;
        std::cout << "Assignment operator\n";
        return *this;
    }
};*/


int main()
{
    std::cout << "Lool\"edf \\ \n";
    std::string a = R"foo(Hello
World
)foo";
    std::string b = R"(Hellol 
World)";

    std::cout << b << std::endl;
    /*Base b1, b2;
    Base b3 = b1;
    b2 = b3;*/
}

