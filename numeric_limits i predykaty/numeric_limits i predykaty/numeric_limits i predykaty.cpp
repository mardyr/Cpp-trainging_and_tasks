// numeric_limits i predykaty.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <algorithm>
bool predykat1(int& n)
{
    n = abs(n); // jej znak nie ma znaczenia
    return (n % 2 == 0 && n % 7 == 0); // sprawdzam czy liczba jest parzysta i podzielna przez 7
}
int main()
{
    std::cout << std::numeric_limits<int>::max() << std::endl;
    std::cout << std::numeric_limits<short>::max() << std::endl;
    std::cout << std::numeric_limits<long long>::min() << std::endl;
    std::cout << std::numeric_limits<float>::min() << std::endl;
    std::cout << std::numeric_limits<int>::min() << std::endl;
    std::cout << std::numeric_limits<int>::is_signed << std::endl; // sprawdzic znak typu
    std::cout << std::numeric_limits<int>::is_exact << std::endl; // sprawdza bledy zaokraglen
    std::cout << std::numeric_limits<float>::epsilon() << std::endl; // roznica miedzy 1, a najmniejsza liczba wieksza niz 1
    std::cout << std::numeric_limits<long double>::infinity() << std::endl; // roznica dodatniej nieskonczonosc

    /* predykaty
     to funkcje pomocniczne dla algorytmów, które zwracają bool. Określają sposoby wyszukiwania, sortowania poprzez np. porownanie
     */
    std::vector<int> v;
    for (int i = 0; i <= 100; i++) v.push_back(i);
    auto pos = v.begin();
    do
    {
        pos = find_if(pos, v.end(), predykat1);
        if (pos != v.end())
        {
            std::cout << *pos << " ";
            pos++;
        }
    } while (pos != v.end()); // szuka, wszystkie predykaty spełniające watunek podzielnosc przez 2 i 7,


        // predykaty dwuargumentowe zazwyczaj zajmują się jakimiś porówaniami bardziej złożonych elementów
        /* dla wyimagowanego złożonego obiektu, predykat 2-arg mógłby np. sprawdzać kilka pól
            bool kryteriumSortowania(const class& obj1,const class& obj2)
            {
                return (obj.p1 < obj2.p1) || (obj1.p2<=obj2.p2) || (obj1.p3 > obj2.p3); 
            }
            sort(collection.begin(),collection.end(),kryteriumSortowania); // predyk

        */
    long long C(0);
    std::sort(v.begin(), v.end(),
        [&](int& i, int& j)
        {
            C++;
            return((i & 2 == 0) && (j % 2 == 0) || // parzyste na lewo
                (i % 2 == 0 && j % 2 == 0 && i < j)|| // mniejsze parzyste na lewo
                (i % 2 != 0 && j % 2 != 0 && i < j)); // mniejsze nieparzyste na lewo
        });
    std::cout << std::endl;
    for (auto& a : v) std::cout << a << " ";

}

