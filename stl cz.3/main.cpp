#include "main.h"

#include <list>
#include <vector>

template<typename T> void show(T &K) //  K bo zakladamy, ze jest to kontener STLa
{
    cout << "["<<K.size()<<"]= ";
    for(auto x:K) // dla x przypisujemy kolejne elementy z Kontenera , elementy z K beda stawa³y siê iksem
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
int main()
{


    list<double> L1; // KONTENER O NAZWIE L1 PRZECHOWUJE DOUBLE
    L1.emplace(L1.begin(),2.5);
    L1.emplace(L1.begin(),8.5); // wstawienie wartosci na danej pozycji
    L1.emplace_front(1.1);
    L1.emplace_back(100.5);
    list<double>::iterator i = L1.end(); // iterator uchwyty na element kontenera, iterator ktory wskazuje na elemnty double  i przypisuje mu wartoœæ ostani z L1
    for(int n=1;n<=2;n++) i--; // i to taki adres przesuwam siê z konca o jedna w jednym wykonaniu petli
    L1.emplace(i,0);

    cout<<L1.front()<<"< >"<<L1.back()<<endl;

    show(L1);

    L1.sort();

    show(L1);

    L1.remove(2.5); // po wartosci usuwam

    show(L1);

    L1.erase(L1.begin()); // usuwam element na ktory wskazuje iterator begin

    show(L1);
    i=L1.begin();i++;i++; // przesuwam 2x w prawo od pierwszego , W LISCIE PRZESUWAMY SIE PRZEZ ITERATORY
    L1.erase(L1.begin(),i); // usuwam od do po iteratorach, od poczatku 2 elementy(do 2, ale bez niego , i=0 . i=1 sie usuwa)
    show(L1);
    L1.clear(); // usuwam reszte
    show(L1);

    cout << string(60,'x')<<endl;

    vector<double> V1={1.0,2.5,-1,75,3,45.1,99.9}; // vector jest jak tablica, rozumie przesuniecia algebraiczne
    show(V1);
    cout<<V1.front()<<" "<<V1.back()<<endl;
    cout<<V1[0]<<" "<<V1.at(3)<<endl;

    V1.erase(V1.begin(),V1.begin()+3);// usuwam ale bez 3 elementu , czyli 0 , 1, 2
    show(V1);
    V1.clear();
    show(V1);
    return 0;
}
