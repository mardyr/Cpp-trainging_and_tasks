#include <iostream>
#include <cmath>

#define M_PI       3.14159265358979323846

using namespace std;
/* Stworz klase reprezentujaca punkt na osi wspolrzednych oraz metode, ktora pozwala obracac go wzgledem punktu[0,0] o podany kat*/
class rotatePoint
{
    float x,y; // coordinates
    float angle; // in degrees
    string name;
public:
    rotatePoint(string name = "Punkt",float a=1,float b=1,float c=30);
    float equationx();
    float equationy();
    void setPoint(float,float);
    void setAngle(float);
    void show();


};

using namespace std;

int main()
{
    rotatePoint*p = new rotatePoint("Punkcik",4);
    p->equationx();p->equationy();
    p->show();
    delete p;
    return 0;
}
/***********************FUNCTION*****************************/

rotatePoint::rotatePoint(string name,float a,float b,float c)
{
    this->name = name;
    this->x =a; // do obiektu na ktory wskazuje this przypisujemy wartosc a
    this->y =b;
    this->angle =c;
}
float rotatePoint::equationx()
{
    return this->x = this->x*cos((this->angle)*(180/M_PI))- this->y*sin((this->angle)*(180/M_PI)); // 1 radian to 180/pi

}
float rotatePoint::equationy()
{
    return this->y = this->x*sin((this->angle)*(180/M_PI))+ this->y*cos((this->angle)*(180/M_PI));
}
void rotatePoint::show()
{
    cout <<"Punkt " << this->name << " po obrocie o "<<this->angle <<
    " stopni, ma wspolrzedne [" <<this->x<<","<<this->y<<"]"<<endl;
}
void rotatePoint::setPoint(float x,float y) {this->x=x;this->y=y;}
void rotatePoint::setAngle(float angle) {this->angle=angle;}
