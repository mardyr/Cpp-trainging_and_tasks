// THREADYYY.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>
#include <ctime>
#include <chrono>
#include <ratio>
#include <algorithm>
typedef unsigned long ull;

ull OddSum=0;
ull EvenSum = 0;
void findEven(ull start, ull end)
{
    for (ull i = start; i <= end; i++)
    {
        if ((i & 1)) EvenSum += 1;

    }
}


void findOdd(ull start, ull end)
{
    for (ull i = start; i <= end; i++)
    {
        if (!(i & 1)) OddSum += 1;

    }
}

int main()
{
    ull start = 0, end = 1000000000;
    
    auto startTime = std::chrono::high_resolution_clock::now();

    
    std::thread t1(findOdd,start,end);
    std::thread t2(findEven, start, end);
   
   if (t1.joinable()) t1.join();
   if (t2.joinable()) t2.join();

   auto stopTime = std::chrono::high_resolution_clock::now();


    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime);

    std::cout << OddSum << std::endl;
    std::cout << duration.count()/1000 << std::endl;

    return 0;
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
