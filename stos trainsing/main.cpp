#include <iostream>

using namespace std;
class Element
{
public:
    int data;
    Element*under;
    Element(int d){this->data =d;this->under = nullptr;}
};
class Stack
{
public:
    Element*top = NULL;
    void add2Stack(int data);
    int rev();
    void show();

};
int main()
{
    Stack* st = new Stack;
    st->add2Stack(34);
    st->add2Stack(12);
    st->add2Stack(13);
    st->add2Stack(45);
    st->add2Stack(10);
    st->show();
    return 0;
}
void Stack::add2Stack(int data)
{
        Element*n = new Element(data); // rezerwujemy pamiec na obiekt
        n->under = this->top ; // top tego obiektu bedzie underem
        this->top = n;

}
int Stack::rev()
{
    Element*temp = this->top;
    int d = this->top->data;
    this->top = this->top->under;
    delete temp;
    return d;
}
void Stack::show()
{
    Element*temp = this->top;
    while(temp!= nullptr)
    {
        cout<<temp->data<<endl<<"|"<<endl;
        temp = temp->under;

    }
    delete temp;
    cout << "NULL"<<endl<<"---------------------------"<<endl;
}
