// copy,copy_if.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
void print(std::vector<int>& vec)
{
    std::copy(vec.begin(), vec.end(),std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}


int main()
{
    std::vector<int> from_vector(10);
    std::iota(from_vector.begin(), from_vector.end(), 0);
    for (auto& i : from_vector) { std::cout << i << " "; }
    std::cout << std::endl;

    std::vector<int> to_vector1(from_vector.size());
    std::copy(from_vector.begin(), from_vector.end(), to_vector1.begin());
    print(to_vector1);

    std::vector<int> to_vector2;
    std::copy(from_vector.begin(), from_vector.end(), std::back_inserter(to_vector2));
    print(to_vector2);

    std::vector<int> to_vector3;
    std::copy_if(from_vector.begin(), from_vector.end(),std::back_inserter(to_vector3),
        [](int x) {return x & 1; });
    print(to_vector3);


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
