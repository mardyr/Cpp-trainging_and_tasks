// thready.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>
#include <chrono>

void sleep(const int seconds)
{
    std::cout <<"WATEK 1 " << std::this_thread::get_id() << std::endl;
    std::cout << "SPANKO\n";
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    std::cout << "KONIEC SPANIA\n";
}

void sleep2(const int seconds)
{
    std::cout <<"WATEK 2 " << std::this_thread::get_id() << std::endl;
    std::cout << "SPANKO2\n";
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    std::cout << "KONIEC SPANIA2\n";
}

struct Functor
{
    void noStaticFun(int i)
    {
        std::cout << "Nostatic podalismy liczbe: " << i << std::endl;
    }
};



int main()
{

    std::cout << "main id " << std::this_thread::get_id() << std::endl;
    Functor Fun;
    std::thread t1(&Functor::noStaticFun,Fun,3);
    if (t1.joinable()) t1.join();
    /*
    std::thread t1(sleep, 10);
    std::thread t2(sleep2, 4);
    std::thread t3([](int b)
        {
            std::cout << "ID WATKU: " << std::this_thread::get_id() << std::endl;
            std::cout << b << " sekund mija i nic" << std::endl;
        }, 4);

    if (t3.joinable()) t3.detach();
    //if (t1.joinable()) t1.join();
    std::cout << "raz\n";
    if (t2.joinable()) t2.detach();
    */
    std::cout << "mamam\n";
    return 0;
}

