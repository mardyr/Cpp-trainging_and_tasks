#include <iostream>

using namespace std;

int main()

{   int *tablica,*tablica2;
    int t,n,pom,i;
    cin >> t;

    while(t)
    {
       cin>>n;
      tablica=new int [n];
       for (i=0;i<n;i++)
       {
            cin>>tablica[i];

       }

       for (int j=0;j<n;j++)
        {
            pom=tablica[j];
            if (j==n-1)
            {
                tablica[j]=pom;
            }
            else
            {
                tablica[j]= tablica [j+1];
                tablica[j+1]=pom;
            }

            cout << tablica[j]<<" ";
        }

        t--;
    }
    delete [] tablica;

}
