// lock_guard.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>
#include <mutex>
// lock tworzy sie automatycznie po stworzeniu obiektu lock_guard, po wyjsciu ze scope'a automatyczny unlock
// nie mozesz zrobic reczne unlocka i nie mozesz kopiowac lock_guarda


// jest tez unique_guard, ktory jest ulepszona wersja lock_guarda, nie musi wywolywac sie w miejscu utworzenia obiektu
// ma rozne strategie , reffered, adopt , try_to lock, moze przenosic ownership , mozemy czasowo okreslac dostep, i tez uzywac rekursywnosci


std::mutex m1;
int buffer = 0;

void task(const char* threadNumber, int loopFor)
{
    std::lock_guard<std::mutex> lock(m1);
    for (int i = 0; i < loopFor; ++i)
    {
        buffer++;
        std::cout << threadNumber << buffer << std::endl;
    }
}

int main()
{
    std::thread t1(task, "T0 ", 10);
    std::thread t2(task, "T1 ", 10);
    t1.join();
    t2.join();

    return 0;
}

