#include <iostream>
#include <windows.h>

using namespace std;
int tabela [11];
int rozmiar;
/**************************************************/
void push()
{
    cin >> tabela[rozmiar];
    if(rozmiar>=10)
    {
        cout << ":("<<endl;
        Sleep(1000);
    }
    else
    {
        rozmiar+=1;
        cout << ":)" << endl;

    }




}
/************************************************/
void pop()
{
    if(rozmiar>=1)
    {

        rozmiar-=1;
        cout << tabela[rozmiar]<<endl;
    }
    else
    {
        cout << ":(" <<endl;

    }

}
/***********************************************/
int main()
{
    int tab[1000];
    int n=0;
    char wybor[1000];
    rozmiar = 0 ;
    while( cin >> wybor[n])
    {
        switch (wybor[n])
        {
            case '+' :
                push();

                break;
            case '-' :
                pop();
                break;
            default:
            cout << "B³edna komenda" ;
        }
        n++;
    }
    return 0;
}
