#include <iostream>

using namespace std;

// ELEMENTY POSZCZEGOLNEJ KOLEJKI
class Element
{
public:
    int data =0;
    Element*after = NULL; // ten ktory stoi za obecnym elementem
    Element(int d ){this->data = d;this->after = NULL;} //konstruktor

};
class Queue
{
public:
    Element*first = NULL; // wskaznik pierwszego
    Element*last = NULL; // wskaznik ostatniego , w kolejce chcemy miec podglad do pierwszego i ostatniego

    void add(int d);
    void show();
    int size();
    void rmv();

};

/******************************************************/
int main()
{
    Queue*myQ = new Queue();
    myQ->add(10);
    myQ->add(20);
    myQ->add(30);
    myQ->add(40);
    myQ->add(50);

    myQ->show();

    myQ->rmv(); //usuwam 10
    myQ->rmv(); // usuwam 20
    myQ->rmv(); // usuwam 30
    myQ->show();


    char z;
    for(long long int i=1;i<=5000001;i++) myQ->add(i);
    cout<<"\n?";cin>>z;
    for(long long int i=1;i<=3000000;i++) myQ->rmv();
    cin>>z;
    return 0;
}


void Queue::add(int d)
{
    static int i=0;
    if(i==5000000) cerr<<" NOT ENOUGH SPACE, GET THE FUCK GET OUT OF HERE!"; // wkladamy tyle elementow do max 5 mln elementow

    Element* n = new Element(d); // wywolanie konstruktora element, przekazujemy nowa wartosci do konstruktora wyzej w hierarchii

    if(this->first == NULL || this->last == NULL)
    {
        this->first = this->last = n; // wiec jesli nie ma zadnego elementu w kolejce, to dodaje pierwszy , wiec adres pierwszego a zarazem ostatniego jest rowny adresowi n
    }
    else
    {
        this->last->after = n; // jesli jest juz jakis element nawet 1 , to on jest last i wskazuje na tego za nim czyli n
        this->last = n; // no i ten n jest teraz last
    }
    i++;
}
void Queue::show()
{

    int i=0;
    Element*temp = this->first;
    while(temp!=NULL&& i<3) // wyswietlam tylko do 3 elementow w kolejce
    {
        cout<<temp->data<<"-";
        temp = temp->after;
        i++;
    }

        cout << "NULL"<<"["<<this->size()<<"]\n\n"<<endl;
}
void Queue::rmv()
    {
        if(this->first!=NULL) // jesli jest co usuwac
        {
            Element *temp = this->first;
            this->first = this->first->after;
            delete temp; // usun pamiec mordo

        }
    }
int Queue::size()
{
    int i=0;
    Element*temp = this->first;
    while(temp!=NULL)
    {
        i++;
        temp = temp->after;
    }

return i;
}
