#include <iostream>

using namespace std;
class EStack
{
    int data;
    EStack*under;
public:
    EStack(int=0,EStack* = NULL); // wskaznik na nic nie wskazuje ,
    void add2Stack(int d ,EStack* &top);
    int removeElement(EStack* &top);
    void showElement(EStack*top);

};
int main()
{
    EStack*Stos = new EStack;
    //Stos -> showE
    return 0;
}

EStack::EStack(int d,EStack*top)
{
    this->data =d; this->under = top;
}
void EStack::add2Stack(int d, EStack* &top)
{
    this->data = d;
    this->under = top;  // to co wskazywalo na top wskazuje na under
    top = this;
}
int EStack::removeElement(EStack* &top)
{
    if(top==NULL) return 0;
    int*d =  new int;
    EStack* first = top;
    this->data = *d;
    top = this->under; // to co wskazywalo na under jest teraz na topie
    delete first;
    return *d;
    delete d;
}
void EStack::showElement(EStack*top)
 {
     while(top!=NULL)
     {
         cout << this->data <<endl<< "|"<<endl;
         top = this->under;
     }
     cout << "NULL"<<endl<<endl<<endl;
 }
