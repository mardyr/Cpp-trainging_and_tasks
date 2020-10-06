// union.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

union MyUnion
{
    unsigned int value;
    char bytes[4];
};
struct BitFields
{
    int month : 25;
    int x : 7;
    
};

int main()
{
    std::cout << sizeof(BitFields) << std::endl;
    MyUnion m;
    m.value = 127;
    std::cout << static_cast<int>(m.bytes[3]);
    std::cout << static_cast<int>(m.bytes[2]);
    std::cout << static_cast<int>(m.bytes[1]);
    std::cout << static_cast<int>(m.bytes[0]);
}

