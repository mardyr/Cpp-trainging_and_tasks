#include <iostream>

using namespace std;
uint8_t c;
char napis[200];
int i;
int licznik=0;
int main()
{
    cin >> c;
    if(1<=c<=10)
    {
        for( i=0;i<200;i++)
        {
            cin>>napis[i];

            if((napis[i+1]=napis[i])&& (napis[i+2]=napis[i+1]))
            {

                {
                    licznik++;
                }

            }
            else
            {
                cout << napis[i];
            }
            if(licznik<3)
            {
                cout<<napis[i];
            }
            else
            {

                cout<< napis[licznik-1]<< licznik;
            }
        }

        /*if(licznik<3)
        {
            cout<<napis[i];
        }
        else
        {
            cout<< napis[licznik-1]<< licznik;
        }

         //cout << napis[i]<<licznik;;*/
    }
    //}
    return 0;
}
