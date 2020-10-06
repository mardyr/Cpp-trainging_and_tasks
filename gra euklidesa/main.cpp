#include <iostream>

using namespace std;

int main()
{
    int t,a,b,odbior,suma=0;
    cin >>t;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b;
        if (a,b>0)
        {
            while(a!=b)
            {
                if(a>b)
                {
                    odbior=b;
                    a= a-odbior;

                }
                else
                {
                    odbior=a;
                    b=b-odbior;
                }

            }
        suma=a+b;

        }
    cout << suma <<endl;
    }

    return 0;
}
