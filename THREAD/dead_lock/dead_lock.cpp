// dead_lock.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <mutex>
#include <thread>

std::mutex m1;
std::mutex m2;
// dead lock dwa watki czekaja na siebie wzajemnie
void thread1()
{
    m1.lock();
    m2.lock();
    std::cout << "Critical Section of thread one\n";
    m1.unlock();
    m2.unlock();
}

void thread2()
{
    m2.lock();
    m1.lock();
    std::cout << "Critical Section of thread two\n";
    m2.unlock();
    m1.unlock();
}



int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();
}

