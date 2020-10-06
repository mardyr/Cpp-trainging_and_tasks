// 222.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Human
{
	int IQ;

public:
	Human(int i) : IQ(i) {}
	bool operator < (Human& obj)
	{
		return IQ < obj.IQ;
	}
	friend std::ostream& operator << (std::ostream& output, Human& obj)
	{
		output << obj.IQ;
		return output;
	}
};


int main()
{
	std::vector<Human> h{ Human(90),Human(120),Human(81),Human(79),Human(118) };
	for (auto& v : h)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
	std::sort(h.begin(), h.end());
	for (auto& v : h)
	{
		std::cout << v << " ";
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
