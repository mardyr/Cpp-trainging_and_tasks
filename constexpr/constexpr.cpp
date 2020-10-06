// constexpr.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <map>
#include <ctime>
#include <typeinfo>
#include <type_traits>
using namespace std;

template <typename T>
class A {
	T value;
public:
	A(T&& v) : value{ v } {}
	void show() {
		if constexpr (is_same_v<T, std::string> || is_convertible_v<T, double>) {
			std::cout << value << std::endl;
		}
		else if constexpr (is_same_v<T, vector<std::string>> ||
			is_same_v<T, vector<double>> ||
			is_same_v<T, vector<float>> ||
			is_same_v<T, vector<int>>)
		{ // T to wektor z liczbami			
			for (auto& element : value) {
				std::cout << element << " ";
			}
			std::cout << std::endl;
		}
		else {
			std::cout << "Brak możliwości wyświetlenia. Brak implementacji w show()." << std::endl;
		}
		std::cout << std::endl;
	}
	template <typename X>
	void multiple(X&& m) {
		if constexpr (std::is_convertible_v<X, double> && std::is_convertible_v<T, double>) { // liczby ?
			value *= m;
		}
		else if constexpr (is_same_v<T, string> && is_convertible_v<X, int>) {
			string temp = value;
			for (int i = 1; i <= abs((int)m) - 1; i++) value += " " + temp;
		}
		else if constexpr (std::is_convertible_v<X, double> &&
			(std::is_same_v<T, vector<double>> || std::is_same_v<T, vector<float>>)) { // vektor<double> * liczba ? (float * liczba)
			for (auto& element : value) {
				element *= m;
			}
		}
		else {
			std::cout << "Nie nastąpiło mnożenie. Brak implementacji w multiple()." << std::endl;
		}

	}
};

constexpr size_t wow() { return 10; } // działa jakby wow() było stałą.


int main()
{
	constexpr int x = 10; // zmienna x będzie traktowana jak stała
	array<int, x> arr1{}; // wiemy, że array potrzebuje stałej gdy określamy typ, x jednak jest stałą obliczaną w czasie kompilacji.
	cout << arr1.size() << endl;
	array<int, wow()> arr2{}; // funkcja może być interpretowana jak stała 
	cout << arr2.size() << endl;
	

	// jeżeli użyjemy konstrukcji
	if constexpr (x > 0) { // constrexpr użyte w if-else sprawia, że warunek jest sprawdzony podczas kompilacji. Niby skutek taki sam, ale w kodzie jest umieszczona jedna gałąź a nie wszystkie.
		cout << "hejka!\n";
	}
	else {
		cout << " --- \n";
	}

	A o1(string("rabarbar"));
	o1.show();
	o1.multiple(5);
	o1.show();

	A o2(100);
	o2.multiple(1.5);
	o2.show();

	A o3(vector<double>{1.0, 2.0, 3.0, 4.0});
	o3.show();
	o3.multiple(2);
	o3.show();


	A o4(vector<string>{"Ala", "ma", "kota"});
	o4.show();

	A o5(vector<float>{1, 2, 3});
	o5.show();
	o5.multiple(10);
	o5.show();

	A o6(vector<unsigned>{1});
	o6.show();

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
