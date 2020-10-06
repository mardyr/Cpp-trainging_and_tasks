#include <iostream>

using namespace std;

class Point
{
    public:
    float x,y;

    Point(){}
    Point(float a,float b)
    {
        this->x = a;
        this->y = b;
    }
    Point operator-(Point &X)
    {
        Point*result = new Point;
        result->x = this->x - X.x;
        result->y = this->y - X.y;

        return *result;
        delete result;
    }
};

int main()
{
    Point X(2,4);
    Point Y(5,2);
    Point Z;
    Z = X - Y;
    cout << Z.x <<" "<<Z.y <<endl;

    return 0;
}
