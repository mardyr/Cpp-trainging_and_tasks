#include <iostream>

using namespace std;

struct EStack
{
    int data=0;
    EStack* under = NULL; // wskaznik na element nizej
};

void add2Stack(int d,EStack* &top);
int removeFromStack(EStack* &top);
void showStack(EStack* top);
int main()
{
    EStack* myStack = NULL;
    showStack(myStack);

    add2Stack(10,myStack);
    add2Stack(20,myStack);
    add2Stack(30,myStack);

    showStack(myStack);

    cout << "Zdejmuje " << removeFromStack(myStack)<<endl;
    cout << "Zdejmuje " << removeFromStack(myStack)<<endl;
    showStack(myStack);
    return 0;
}


void add2Stack(int d,EStack* &top) // typem jest wskaznik na element stosu i pobieram orginal obiektu typu wskaznik na cos
{
    EStack*newElement = new EStack;

    newElement ->data =d;
    newElement ->under = top; // pole under staje sie top,czyli ten co byl top, bedzie under
    top = newElement; //przypisanie utworzonego wierzcholka na top, czyli to miejsce w pamiêci, gdzie jest newElement to jest tera top
    delete newElement;

}
int removeFromStack(EStack* &top)
{
    if(top==NULL) return 0;
    EStack* temp = top; // kopia adresu
    int d = top->data; // data variable
    top = top->under; // top bedzie elementem nizej
    delete temp;
    return d;
}

void showStack(EStack* top)
{
    while(top!=NULL)
    {
        cout << top->data<<endl<<"|"<<endl;
        top=top->under; // czyli lecimy w dol do NULLA
    }
    cout << "NULL" << endl<<endl<<endl;
}
