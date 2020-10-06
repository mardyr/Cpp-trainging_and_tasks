// mutual exclusion.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>
#include <mutex>

// wystepuje gdy dwa watki jednoczesnie chca modyfikowac dane

int myAmount = 0;
std::mutex m;
void addMoney()
{
    m.lock();
    ++myAmount;  // critical region
    m.unlock();
}

// race condition*wyścig) , gdy kilka watkow chce modyfikowac dane w tym samym czasie

int main()
{
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    std::cout << myAmount;

}