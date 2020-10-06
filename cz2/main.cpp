#include "main.h"
#include <queue>
#include <functional>
#include <vector>


template<typename T> void print_queue(T &q)
{
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();//q.pop() - kolejki pozwalaja odrzucic pierwszego w kolejce
    }
    cout<<endl;
}
int main()
{
    // uzycie nr 1 - w kolejce mamy int, ktory od razu ustala priorytet wg wartosci
    priority_queue<int> pq1;
    pq1.push(10);pq1.push(30.4);pq1.push(50);pq1.push(20);pq1.push(40);pq1.push(30.1);pq1.push(0); // w takiej konwencji te o najwyzszym priorytecie
    print_queue(pq1);

    // uzycie nr 2 - teraz uzyje double, ale zmieniê porz¹dek priorytetów(jakby sortowanie)
    priority_queue<double,vector<double>,greater<double>> pq2;// kontener wektor , funkcja greater - predefinicja porzadkowania obiektow , jest ona wbudowana i zmienia priorytetowanie o 180 stp
    pq2.push(10);pq2.push(30.4);pq2.push(50);pq2.push(20);pq2.push(40);pq2.push(30.1);pq2.push(0);
    print_queue(pq2);

    // uzycie nr 3 - jawne wywolanie vectora i less , ogolnie to one sa defaultowo i bez tego jak w 1 przykladzie sie robi

    priority_queue<int,vector<int>,less<int>> pq3;
    for( int n:{10,30,50,20,40,30,0}) pq3.push(n); // piekno STL , dla kolejno n=10, n=30 itd , dodaje do konca kolejki
    print_queue(pq3); // show me what you got;
    //ogolnie otrzymamy to samo jak w 1 przykladzie

    // uzycie nr.4 -FUNKCJE ANONIMOWE - LAMBDY , NIE MAJO SWOJEJ NAZWY , taka nie nazwana zmienna
    // zazwyczaj jest ona argumentem do innej funkcji lub mozna ja przypisac do innej zmiennej(jak np 5, czy jakiœ napis , sam bez sensu ale a=5 lub (void int a)
      auto compare = [](int left,int right) {return right<=left;};  // lambda [] , compare to adres funkcji anonimowej , jak wywolam zmienna to wywolam te funkcje
      priority_queue<int,vector<int>,decltype(compare)> pq4(compare); // int , typ ptzechowywany w kolejce, wywoluj¹c zmienna compare , moge wywolac takiego konstruktora , decltype - pobiera typ zmiennej z auto
       for(int n:{2,1,1,3,4,3,5,3,3})pq4.push(n) ;
       print_queue(pq4);
    return 0;
}
