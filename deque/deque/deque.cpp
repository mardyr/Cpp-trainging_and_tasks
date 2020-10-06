// deque.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <deque>
#include <vector>
void show(std::deque<int>& a)
{
    std::cout << "WJEZDZA SHOW NA PELNEJ" << std::endl;
    for (auto x : a) std::cout << x << " ";
    std::cout << std::endl;

}
int main()
{
    std::deque<int> years;
    for (int i = 1; i <= 7; i++) 
    {
        years.push_front(2019 + i);
        std::cout <<years.front() << " ";
    }
    std::cout << std::endl;
    std::cout << years.size() << " " << years.max_size() << std::endl;
    years.pop_front();
    show(years);
    std::cout << std::string(60, '=') << std::endl;

    std::cout << "USUWAM Z TYLU" << std::endl;
    years.pop_back();
    show(years);
    std::cout << std::string(60, '=') << std::endl;

    years.push_back(3991);
    std::cout << "PUSHH Back" << std::endl;
    show(years);
    std::cout << std::string(60, '=') << std::endl;

    years.push_front(4);
    std::cout << "PUSHH FRONT" << std::endl;
    show(years);
    std::cout << std::string(60, '=') << std::endl;

    for (int i = 0; i < years.size(); i++)
    {
        std::cout << ((i % 2) ? years[i] : years.at(i)) << " ";
    }
    std::cout << std::endl;

    std::cout << std::string(60, '=') << std::endl;
    years.pop_back();
    std::cout << "POP BAACK";
    show(years);
    
    std::cout << std::string(60, '=')<<std::endl;
    std::cout << &years[0] << std::endl;
    show(years);
    /*auto txt = R"(Baza zglasza sie kapitan Bubbles wlaczam ostrzegawcze swiatlo MPS podsystemu
prosze o zgode na realokacje pamieci w pizdu nie wiem gdzie)";
    auto julian = R"(Odbior prosze realokowac kapitanie)";
        auto ricky = R"(Tester Ricky, uwaga kosmici mi cos zjebali w 8 silniku, 
jak ich opierdole to wyladuje na Sraniuszu,
chyba tam choduja kosmiczny hasz, i jak? )";
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::string(27,' ') << "BUBBLES" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << txt << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::string(27,' ') << "JULIAN" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << julian << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::string(25, ' ') << "REALOKACJA" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    years.resize(years.size() + 5);
    std::cout << &years[0] << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::string(27, ' ') << "RICKY" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << ricky << std::endl;
    std::cout << std::string(60, '=') << std::endl;*/
    years.resize(years.size() + 5);
    std::cout << "ROBIMY RESIZE" << std::endl; 
    std::cout << &years[0] << std::endl; // i nie ma realokacji
    std::cout << std::string(60, '=') << std::endl;
    years.insert(years.begin() + 3, 2); // wstawiam za trzecim elementem 2-ke
    show(years);
    std::cout << &years[0] << std::endl; // akuku realokacja
    years.insert(years.end() - 3, 5, -1); // 3 pozycje od ostatniego  wstawiam 5 razy -1
    show(years);
    std::cout << &years[0] << std::endl; // a tu nie dziala, realokacja zmienna jest

    std::vector<int> v{ 999,998,997 };
    auto in = years.insert(years.begin() + 1, v.begin(), v.end()); // za pierwszym elementem wstawiam wektor v , in iterator na miejsce 1 wektora
    show(years);
    std::cout << *in << std::endl;

    std::cout << std::string(60, '=') << std::endl;
    std::cout << "USUWAM DRUGI ELEMENT" << std::endl;
    auto next = years.erase(years.begin() + 1); // kasuje drugi element
    show(years);
    std::cout << "NEXT" << std::endl;
    std::cout << *next << std::endl;

    next = years.erase(years.begin() + 3, years.end() - 5); // usuwamy obszar miedzy iteratorami
    show(years);
    std::cout << "NEXT" << std::endl;
    std::cout << *next << std::endl; // next to iterator na nastepny element za skasowanym

    auto& ref = years.emplace_front(100); //wstawia kopie , zwraca referencje do wlozonego obiektu
    std::cout << ref << std::endl;
    ref = 200;
    show(years);

}


