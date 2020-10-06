#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void smart_note(string napis)
{
    int dlugosc= napis.length();
    int licznik=1;
    for(int i=0;i<dlugosc;i++)
    {
        if((napis[i+1]== napis[i]))
        {
            licznik++;
        }
        else
        {
            if (licznik>2)
            {
                cout << napis[i]<<licznik;
            }
            else if (licznik==2)
            {
                cout<< napis[i]<<napis[i];
            }
            else
            {
                cout<< napis[i];

            }
            licznik=1;
        }

    }

}
int main()
{
    string napis;
    int c;//liczba zestawow danych
    cin>>c;
    if (1<=c<=10)
        for ( int i=0;i<c;i++)
        {
            cin >> napis;
            transform(napis.begin(), napis.end(),napis.begin(),:: toupper);
           smart_note(napis);
           cout <<endl;
        }
    return 0;
}
