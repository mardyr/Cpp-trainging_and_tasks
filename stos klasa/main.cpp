#include <iostream>

using namespace std;
class Element
{
public:
    int data;
    Element*under;
    Element(int d){this->data = d;this->under=NULL;}
};
class Stos
{
    Element* top = NULL;
public:
    void add2Stack(int);
    int removeStk();
    void show();
};
int main()
{
    Stos* one = new Stos;
    one->show();
    one->add2Stack(20);
    one->add2Stack(40);
    one->show();
    one->add2Stack(59);
    one->add2Stack(23);
    one->show();
    one->removeStk();
    one->show();
    return 0;
}
void Stos::add2Stack(int d)
{
    Element* ad = new Element(d); // pobieram wartosc od uzytkownika i odrazu inicjalizuje przez konstruktor
    ad->under = this->top;
    this->top = ad;
}
int Stos::removeStk()
{
    if(this->top!=NULL)
    {
        Element*temp = this->top;
        int *d = new int;
        *d = temp->data;
        this->top = this->top->under;
        delete temp;
        return *d;
        delete d;
    }
    else cout << "NULL"<<endl;
}
void Stos::show()
{
    Element* temp = this->top; // ten obiekt musi tutaj byc, zeby nie wyzerowac topu, tylko sobie pobieram z niego wartosci! i stos moze dalej sie budowac
    while(temp!= NULL)
    {
        cout << temp->data <<endl<<"|"<< endl;
        temp= temp->under;
    }
    delete temp;
    cout <<endl<<"NULL" <<endl<<"--------------"<<endl;
}
