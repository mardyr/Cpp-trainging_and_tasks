#include <iostream>

using namespace std;
class Element
{
public:
    int data;
    Element*after;
    Element(int d) {this->data =d;this->after = NULL;}

};
class Queue
{
public:
    Element* first = NULL;
    Element* last = NULL;
    void add2Queue(int );
    int remov();
    void show();
    void clearAll();
};
int main()
{
    Queue*q = new Queue;
    q->add2Queue(10);
    q->add2Queue(30);
    q->add2Queue(20);
    q->add2Queue(11);
    q->show();
    cout <<endl<<"USUWAM "<<q->remov()<<endl<<endl<<endl;
    q->show();
    q->clearAll();
    q->show();
    return 0;
}
void Queue::add2Queue(int d)
{
    Element*e = new Element(d);
    if(this->first==nullptr || this->last==nullptr) // jesli pusta kolejka
    {
        this->first = this->last = e;
    }
    else
    {
        this->last->after = e;
        this->last =e;
        e->after = nullptr;
    }
}
int Queue::remov()
{
    if(this->first!=nullptr)
    {
        Element*temp = this->first;
        int d = this->first->data;
        this->first = this->first->after;
        delete temp;
        return d;
    }

}
void Queue::show()
{
    unsigned long long int i=1;
    Element*temp = this->first;
    while(temp!=nullptr)
    {
        cout<<i<<". "<< temp->data <<endl<<"|"<<endl;
        temp =  temp->after;
        i++;
    }
    cout << "NULL"<<"--------------------"<<endl<<endl<<endl;

}
void Queue::clearAll()
{
    while(this->first!=NULL)
    {
        this->first =  this->first->after;
    }

}

