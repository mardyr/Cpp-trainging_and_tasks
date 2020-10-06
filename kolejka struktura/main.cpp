#include <iostream>

using namespace std;

/*struct Queue
{
    int data=0;
    Queue*after=NULL;

};
void addElement(int data,Queue* &first,Queue* &last)
{
    Queue*Element = new Queue; // tworze nowy element na stosie
    Element->data = data;
     if(first= NULL || last = NULL)
     {
         first = Element->data;
     }
     else
     {
         Element->after =
     }

}*/


class Element
{
public:

int data;
Element*after;  // wskazuje na elementy za nim
Element(int d){this->data =d; this->after = nullptr;} // tworze konstruktor ktory bedzie inicjalizowal defaultowe wartosci

};

class Queue
{
public:
    Element*first = nullptr; // w kolejce poruszam sie pierwszym i ostatnim elementem
    Element*last = nullptr;

    void add2Queue(int d);
    void rmv();
    void show();
};


int main()
{
    Queue*kol = new Queue;

    kol->add2Queue(20);
    kol->add2Queue(30);
    kol->add2Queue(40);
    kol->add2Queue(50);
    kol->add2Queue(60);
    kol->rmv();
    kol->show();

    return 0;
}


void Queue::add2Queue(int d)
{
    Element *newE = new Element(d); // tworze pamiec dla nowego elementu
    if(this->first ==  nullptr || this->last == nullptr)
    {

        this->first = this->last = newE; // pierwszy element kolejki to ten co utworzylismy
    }
    else
    {
        this->last->after = newE; // to na co wskazywal wczesniej after to teraz newE
        this->last = newE; // od teraz ostatnim jest newE
    }

}
void Queue::rmv()
{
    if(this->first!=nullptr)
    {
        Element*temp = this->first;
        this->first=this->first->after ;
        delete temp;

    }
}
void Queue::show()
{
    Element*tem = this->first; // przekazuje wartosc to elementu, bo zaraz bede zerowal ,wiec nie chce stracic
    while(tem!=nullptr)
    {
        cout << tem->data << endl;
        tem = tem->after;
    }
    cout << "NULL" << "------------------------------"<<endl;

}
