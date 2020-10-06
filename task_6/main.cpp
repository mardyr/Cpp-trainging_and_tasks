#include <iostream>

using namespace std;
class Calc
{
    float a,b;

public:
    Calc(float=1,float=2);
    float plus(float,float);
    float minus(float,float);
    float asterisk(float,float);
    float division(float,float);

};
int main()
{
    Calc*number = new Calc;

    cout<<"Dodawanie "<<number->plus(2.4,3.5)<<endl;
    cout <<"Odejmowanie "<<number->minus(32.2,1)<<endl;
    cout<<"Dzielenie "<<number->division(3,0)<<endl;

    delete number;
    return 0;
}
Calc::Calc(float x,float y)
{
    this->a =x;this->b =x;
}
float Calc::plus(float x,float y)
{
    this->a = x; this->b =y;

    return x+y;
}
float Calc::minus(float x,float y)
{
    this->a = x; this->b =y;

    return x-y;
}
float Calc::division(float x,float y)
{
    this->a =x; this->b=y;
    if(y!=0) return x/y;
    else return -99999999;
}
float Calc::asterisk(float x,float y)
{
    this->a =x; this->b=y;

    return x*y;
}
