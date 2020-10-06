// try_lock.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
// std:try_lock(m1,m2,m3.m4) , jeśli uda sie zamknac wszystkie mutexy to funkcja zwraca -1 
// w innym przypadku zwraca wartosc rowna indeksowi wystapienia, np jak już bedzie zablokowana i m3 bedzie chciało, 
// ale nie wejdzie to zwroci 2 i ZWOLNI wczesniej zrobione locki


int main()
{
    std::cout << "Hello World!\n";
}

