
// dynamic_cast.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <memory>
#include <exception>

class Base
{
    virtual void print() { std::cout << "Base" << std::endl; }
};
class Derived1 : public Base
{
    void print() { std::cout << "Derived1 " << std::endl; }
};
class Derived2 : public Base
{
    void print() { std::cout << " Derived2" << std::endl; }
};

int main()
{
    Derived1* d2 = new Derived1;

    Base* dp =dynamic_cast<Base*>(d2);

    Derived1* dp2 = dynamic_cast<Derived1*>(dp);
    dp2 == nullptr ? std::cout << "NULL\n" : std::cout << "VALID\n";
    delete d2;

    Derived1 dx;
    try {
        Derived2& n = dynamic_cast<Derived2&>(dx);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
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
