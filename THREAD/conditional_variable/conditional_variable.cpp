// conditional_variable.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// conditional variable sa do komunikacji miedzy watkami, zawsze maja flage
// zawiadamiaja inne watki(notify)
// czekaja pod jakimis warunkami

std::condition_variable cv;
std::mutex m;
long balance;

void AddMoney(int money)
{
    std::lock_guard<std::mutex> add(m);
    balance += money;
    std::cout << "Current balance amount after adding" << balance << std::endl;
    cv.notify_one();
}

void withdrowMoney(int money)
{
    std::unique_lock<std::mutex> substr(m);
    cv.wait(substr, [] {return balance != 0 ? true : false; });
    if (balance >= money)
    {
        balance -= money;
        std::cout << "Overall balance after substraction equals " << balance << std::endl;
    }
    else
    {
        std::cout << "Cannot deduce the balance, current balance is less than " << balance << std::endl;
    }
    std::cout << "Current balance equals: " << balance << std::endl;
}


int main()
{
    std::thread t1(AddMoney, 500);
    std::thread t2(withdrowMoney, 400);
    t1.join();
    t2.join();

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
