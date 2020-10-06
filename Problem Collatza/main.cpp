#include <iostream>

using namespace std;
/************************************/
int collatz(int x)
{
    int n=0;
    if(x==1) return 0;
    else
    {
        {
            while(x!=1)
            {
                if(x%2==0)
                {
                x=x/2;
                }
                else
                {
                    x=3*x+1;
                }
            n++;
            }
        }
    }


return n;



}

/************************************/
int main()
{   int t,s;
    cin>>t;
    while(t)
    {
        cin>> s;
        if (1<=s<=10000)
        {


              cout <<collatz(s)<<endl;


        }


        t--;
    }

}
