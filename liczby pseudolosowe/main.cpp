#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
using namespace std;
int liczba,strzal,ile_prob=0;
int main()
{
    cout << "Witaj ! Pomyslalem sobie liczbe 1...100" << endl;
    srand(time(NULL));
    liczba = rand()%100+1;

    while(strzal!=liczba)
    {
        ile_prob++;
        cout << "Zgadnij jaka (to Twoja " << ile_prob<<" proba)"<<endl;
        cin >> strzal;
        if (liczba==strzal)
            cout<<"Wygrales w:" << ile_prob<<"probie"<<endl;
        else if (liczba<strzal)
            cout<<"Za duzooo " <<endl;
        else if (liczba > strzal)
            cout <<"Za maloo"<<endl;
    }
    getchar();getchar(); // 2 razy dla pewnosci
    return 0;
}
