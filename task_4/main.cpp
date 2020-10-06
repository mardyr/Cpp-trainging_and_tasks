#include <iostream>

using namespace std;
class Cube
{
    float a;
public:
    Cube(float=1);
    void setA(float);
    float getA();
    float getSurfaceArea();
    float getCapacity();

};
int main()
{
    Cube *p = new Cube;

    p->setA(2.5);
    cout << "Wszystkie krawedzie maja dlugosc: "<< p->getA()<<endl;
    cout << "Pole powierzchni szescianu to: "<< p->getSurfaceArea()<<endl;
    cout << "Objetosc szesciany wynosi: "<< p->getCapacity()<<endl;

    delete p;
    return 0;
}
Cube::Cube(float x)
{
    this->a = x;
}
void Cube::setA(float x)
{
    this->a = x;
}
float Cube::getA()
{
    return this->a;
}
float Cube::getSurfaceArea()
{
    return (this->a)*(this->a);
}
float Cube::getCapacity()
{
    return (this->a)*(this->a)*(this->a);
}
