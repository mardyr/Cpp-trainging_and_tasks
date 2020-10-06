// m_try_lock.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void increaseTheCounter()
{
    for (int i = 0; i < 100000; ++i)
    {
        if (mtx.try_lock())
        {
            ++counter;
            mtx.unlock();
        }
    }
}


int main()
{
    std::thread t1(increaseTheCounter);
    std::thread t2(increaseTheCounter);

    t1.join();
    t2.join();

    std::cout << "counter could increases up to: " << counter << std::endl;
}

