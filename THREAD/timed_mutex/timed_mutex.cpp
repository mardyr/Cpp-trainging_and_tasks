// timed_mutex.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int myAmount = 0;
std::timed_mutex m;
// try_lock na sterydach, czyli probujemy dostac sie do critical section i czekamy tam chwile
// nikt nie odpowiada w tym czasie, to idziemy do innej instrukcji , ROZNICA TAKA ZE CZEKAMY CHWILE
void increment(int i)
{
    if (m.try_lock_for(std::chrono::seconds(1))) // watek bedzie czekal sekunde, jesli implementacja bedzie trwala duzej to sie nie dostanie
    {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(2)); // jeden watek wchodzi i czekam 2 sekundy 
        std::cout << "Thread" << i << "Entered" << std::endl; // a drugi watek w ifie mowi ze max moze czekac 1 sekunde, pozniej zmyka
    }
    else
    {
        std::cout << "Thread " << i << " Couldn't Enter" << std::endl; // wiec po sekundzie sobie poszedl
    }
}



int main()
{
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);

    t1.join();
    t2.join();

    std::cout << myAmount << std::endl;

    return 0;
}

