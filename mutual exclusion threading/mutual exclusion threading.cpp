// mutual exclusion threading.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>
#include <mutex>

int myAmount = 0;
std::mutex m;
void addMoney()
{
    m.lock();
    ++myAmount;
    m.unlock();

}

int main()
{
    std::thread thread1(addMoney);
    std::thread thread2(addMoney);

    thread1.join();
    thread2.join();

    std::cout << myAmount << std::endl;

    return 0;
}

