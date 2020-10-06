// ZLI.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <map>

int main()
{
    std::map < char, int> counter;
    int n;
    std::string napis="o";
    std::cin >> n;
    while (n < 151 )
    {
        std::cin >> napis;
        if (napis == "\0") break;
    }
    for (int i = 0; i != '\0'; i++)
    {
        if (napis[i] == '\n') {}
        if (counter.find(napis[i]) == counter.end())
        {
            counter[napis[i]] = 1;
        }
        else
        {
            counter[napis[i]]++;
        }
    }

    for (auto& [k, v] : counter)
    {
        std::cout << k << " " << v << std::endl;
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
