// wielowatkowsc.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <numeric>


void AccumulateRange(uint64_t& sum, uint64_t start, uint64_t end); 

int main()
{
    const int numberOfThreads = 2;
    const int numberOfElements = 1000 * 1000 * 1000;
    const int step = numberOfElements / numberOfThreads;

    std::vector<std::uint64_t> partial_sums(numberOfThreads);

    std::thread t1(AccumulateRange, std::ref(partial_sums[0]), 0, step);
    std::thread t2(AccumulateRange, std::ref(partial_sums[1]), step, numberOfThreads * step);

    t1.join();
    t2.join();

    std::uint64_t total = std::accumulate(partial_sums.begin(), partial_sums.end(), uint64_t(0));

    std::cout << total << std::endl;

    return 0;

}


void AccumulateRange(uint64_t& sum, uint64_t start, uint64_t end)
{
    sum = 0;
    for (uint64_t i = start; i < end; ++i)
    {
        sum += i;
    }
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
