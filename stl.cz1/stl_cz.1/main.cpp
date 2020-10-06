#include "main.h"

#include <stack>  // dodajemy biblioteki stosu
#include <queue>  // dodajemy biblioteki kolejki
#include <deque>  // kolejka z dwoma koncami

class Nothing
{
public:
    int value = 0;
    Nothing(int v)
    {
        value=v;
    }
};


template <typename T> void test(T); /* TWORZE SZABLON(TEMPLATE)- ABSTRAKCYJNA FUNKCJA DZIALA DLA DOWOLNEGO TYPU, T TO TYP ABSTRAKCYJNY
 argument typu T, gdzie nie jest on zadnym konkretnym typem*/
int main()
{
    //STOOS
    stack <int> S; // stos intow

    S.push(10);S.push(20);S.push(30); // na stos rzucamy 10,20 i 30
    cout << S.top()<<"<"<<S.size()<<">"<<endl; // pokaz co ma na topie i ile elementow
    while(!S.empty())
    {
        cout<<S.top()<<"->";
        S.pop();
    }
    cout <<endl<< string(60,'x')<<endl;
//-------------------------------------------------------------------------------
//==================================KOLEJKA
queue <Nothing*> Q; // kolejeczka wskaznikow na klase Nothing, czyli adresow , nazwa kolejki Q

Q.push(new Nothing(10)); // dodaje adres nowego elementu, ja tu dzialam caly czas na adresach
cout << Q.front()->value <<endl; // wez pierwszy z kolejki( czyli wskaznik na obiekt typu Nothing)
Q.push(new Nothing(20)); // myyk na koniec kolejki
cout << Q.back() ->value << "  obiektow =<"<<Q.size()<<">"<<endl; // na koncu kolejki stoi
delete Q.front(); // zwalniam pamiec tego pierwszego  , zwalniam pamiec obiektu, czyszcze to w srodku
Q.pop() ;// wyrzucam adres juz pustego elementu , zwalniam pamiec kolejki

cout << Q.front()->value<<endl<<endl;
//--------------------------------------------------------------------------------
deque <int> deq;
deq.push_front(10);
deq.push_back(20);
deq.push_front(340);
deq.push_back(102);
for(auto i=deq.begin();i!=deq.end();i++) // i to wskaznik, i przesuwa sie na kolejne adresu
{
    cout<<*i<<" ";
}cout <<"\n";
deq.insert(deq.begin()+3,55);// wskakuje za 3 pozycje
deq.pop_front();
deq.pop_back();
for(auto i = deq.begin();i!=deq.end();i++)
{
    cout << *i << " ";
} cout << "\n";


//--------------------------------------------------------------------------------
    cout <<"\n"<<string(60,'x')<<endl;
    short int x=0;
    long double y=2.1;
    auto z = string("Rower to swietny wynalazek."); // wywolanie konstruktora klasy string
    test(x);
    test(y);
    test(z);
    cout << z.size(); // to jest klasa string, bo tryb auto wykryl ta klase
    return 0;
}
//----------------------------------------------------------------------------------
template<typename T>
void test(T a)
{
    cout << sizeof(T)<<" bytes: value="<<a<<endl;
}
//----------------------------------------------------------------------------------
