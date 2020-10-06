// async_thread.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int fun(int a)
{
    return a + 1;
}

void sleeep(const int& sec)
{
    std::cout << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(sec));
    std::cout << "Koniec czekania\n";
}
void sleeep2(const int& sec)
{
    std::this_thread::sleep_for(std::chrono::seconds(sec));
    std::cout << "Koniec czekania222\n";
}

int main()
{

 
    /* mozemyw thread zwrocic wartosc , a tak
        
        std::packaged_task<int(int)> task{fun};
        future<int> result = task.get_future();
        thread t1(move(task),2) // 2 to agrument funkcji 
        t1.join();
        std::cout<<result.get()<std::endl;
  
    */
    
    std::cout << "Hello World!\n" << std::this_thread::get_id() << std::endl;
    std::async(std::launch::async, fun, 3);
    std::future<void> result = std::async(std::launch::deferred, sleeep, 1);
    sleeep2(2);
    result.get(); // w deferred tutaj dopiero watek sie wykonuje, w async moze odrazu i w gecie lub waitcie na pewno sie konczy
    
    return 0;
}

