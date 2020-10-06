// multithreading.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>

void thread1()
{
    std::cout << "thread one\n";
}
void thread2()
{
    std::cout << "thread two\n";
}

int main()
{
    std::thread t1(thread1);

    std::thread t2(thread2);

    t1.join();
    t2.join();
    
    return 0;
}

