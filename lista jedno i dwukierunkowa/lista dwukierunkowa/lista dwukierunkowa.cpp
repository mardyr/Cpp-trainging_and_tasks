// lista dwukierunkowa.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <list>  // lista dwukierunkowa, iterator dwukierunkowy
#include <forward_list> // lista jednokierunkowa , iterator postepujacy idziemy do przodu
void show(std::list<int>& a)
{
    for (auto& i : a) std::cout << i << " ";
    std::cout << std::endl;
}
void show(std::forward_list<std::string>& a)
{
    for (auto& i : a) std::cout << i << " ";
    std::cout << std::endl;
}


int main()
{
    std::list<int> bigL{ 1,2,3,4,5,6,7,8,9,10,1,2,3 };
    bigL.insert(--bigL.end(), 100);
    // w liscie ++ -- , nie +5 , -3
    for (auto it = bigL.begin(); it != bigL.end(); it++) std::cout << *it << " ";
    show(bigL);
    std::cout << std::string(60, 'x') << std::endl;
    std::cout << "[" << bigL.size() << "]" << std::endl;
    auto i = bigL.insert(++bigL.begin(), 3, -2);
    show(bigL);
    std::cout << *i << std::endl;
    bigL.pop_back();
    show(bigL);
    int s = 5;
    bigL.push_back(s);
    show(bigL);
    auto pos = ++++++bigL.begin();
    auto newpos = bigL.insert(pos, 1500);
    *newpos += 1;
    *pos += 1;
    show(bigL);
    std::cout << *newpos << std::endl;

    int move = 5; // przesun sie 5 razy od poczatku , na 6 pozycje
    auto pos2 = bigL.begin();
    while (pos2 != bigL.end() && move) // dopoki nie osiagne konca i move nie jest 0
    {
        ++pos2;// przesuwam sie w prawo
        --move; // i zmniejszam ilosc krokow
    }
    std::cout << *pos2 << "!" << std::endl;
    bigL.remove(5);// wszystkie 5 usuwam
    show(bigL);
    auto found = find(bigL.begin(), bigL.end(), 100);
    std::cout << "FIND DZIALA" << std::endl;
    bigL.erase(found);
    show(bigL);
    bigL.sort([](auto& a, auto& b) {return a < b; }); // sortuje rosnaco , jesli a<b to zwracam 1 czyli git jesli nie to zamieniam
    show(bigL);
    
    bigL.remove_if([](auto& e) {return (e < 4); });
    show(bigL);

    // UWAGA! forward_list jest jednokierunkowa, bo elementy sa powiazane tylko z nastepnym. Zmniejsza sie zuzycie pamieci

    std::forward_list<std::string> stringList{ "Tak","Nie","Nie wiem","chyba" };
    std::cout << *++stringList.begin() << std::endl; // "NIE"
    // NIE COFAMY SIEE
   
    stringList.push_front("nooo");
    show(stringList);

    std::cout << distance(stringList.begin(), stringList.end()) << std::endl;
    auto findex = find(stringList.begin(), stringList.end(), "Nie");
    std::cout << "USUWAM WSZYSTKIE PO NIE" << std::endl;
    stringList.erase_after(findex, stringList.end());
    show(stringList);
}

