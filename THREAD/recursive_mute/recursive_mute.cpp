// recursive_mute.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


// stosowane do zapobiegania deadlockom(zakleszczeniom watkow) gdy dwa watki czekaja na siebie nawzajem, w rekurencji jak
// critical area lockujemy i wywolujemy przez rekurencje i chcemy dostac się przez ten sam mutex, ale on jest zablokowany
// przez tą wczesniejsza funkcje, wiec ten watek czeka na poprzedni a poprzedni czeka az ten sie skonczy, pojebana akcja
#include <iostream>
#include <thread>
#include <mutex>
// W RECURSIVE MUTEX ten sam watek moze locknac wiele razy uzywajac recursive mutex, recurive mutex sobie liczy
// liczy ile razy zostal lockniety , tyle razy musi być odblokowany
// mozemy lockowac do usranej smierci, znaczy az pamiec na stosie sie skonczy , wtedy jak mamy sam lock to wywali error, a try lock zwroci false

std::recursive_mutex m1;
int buffer = 0;

void recursion(char c, int loopFor)
{
    if (loopFor < 0)
        return;

    m1.lock();
    std::cout << "Locked By ThreadID:" << c << " " << buffer++ << std::endl;
    recursion(c, --loopFor);
    m1.unlock();
    std::cout << "Unlocked By ThreadID " << c << std::endl;
}   



int main()
{
    std::thread t1(recursion, '1', 2);
    std::thread t2(recursion, '2', 2);

    t1.join();
    t2.join();

    return 0;
}
