// template_specialization.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "min.h"

template<typename T>
void f(T x, T y)
{
    std::cout << "Template\n";
}
void f(int i, int j)
{
    std::cout << "Non-template\n";
}


int main()
{
    
    std::cout << "Min od (10.5,11.3) ";
    auto d = min(10.5, 11.3);
    std::cout << d << std::endl;

    std::cout << "Min od 11,18,1 ";
    auto z = min(11, 18, 1);
    std::cout << z << std::endl;


    f(1, 2);
    f(2.4, 22.1);
    f(1, 'b'); // templaty nie zamieniaja zmiennych, musza idealnie pasowac, nie ma tutaj zadnej domyslnej konwersji
 
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
