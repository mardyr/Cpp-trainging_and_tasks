// Point.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>

class Point
{
    float x, y;

public:
    Point(float x = 0, float y = 0) : x{ x }, y{ y }{}
    void setX(float outX) { x = outX; }
    void setY(float outY) { y = outY; }
    float getX() const { return x; }
    float getY() const { return y; }
    int Quarter()const;
    bool perdepdicular(const Point* r)
    {
        if (x == r->x) return true;
        return false;
    }
    bool commonPart(double& r);
    bool crossX(const Point* r)
    {
        if ((x > 0 && r->x < 0) || (x < 0 && r->x >0)) return true;
        else return false;
    }

};
bool isTriangle(Point& p1, Point& p2, Point& p3)
{
    if (p1.x == p2.x || p1.x == p3.x)
}


int main()
{
    srand(time(NULL));
    Point p[100];
    float x, y;
    for (int i = 0; i < 100; i++)
    {
        y = (rand() % 20000 - 10000)/100;
        p[i].setY(y);
        x = (rand() % 20000 - 10000)/100;
        p[i].setX(x);
    }
    std::cout << p[81].getX() << " " << p[81].getY() << std::endl;
    p[81].Quarter();
    std::cout << p[81].perdepdicular(&p[20]) << std::endl;
    double r = 81.2;
    std::cout << p[81].commonPart(r) << std::endl;
    std::cout << "p.32 " << p[32].getX() << " " << p[32].getY() << std::endl;
    std::cout << "p.77 " << p[77].getX() << " " << p[77].getY() << std::endl;
    std::cout << "Cross OX: " << p[32].crossX(&p[77]) << std::endl;
}



int Point::Quarter()const
{
    if (x > 0 && y > 0) { std::cout << "I cwiartka" << std::endl; return 1; }
    else if (x == 0) { std::cout << " os OX"; return 0; }
    else if (y == 0) { std::cout << " os OY"; return 0; }
    else if (x < 0 && y > 0) { std::cout << " II cwiartka" << std::endl; return 2; }
    else if (x < 0 && y < 0) { std::cout << "III cwiartka" << std::endl; return 3; }
    else if (x > 0 && y < 0) { std::cout << "IV cwiartka" << std::endl; return 4; }
    else { std::cout << " WRONG DATA"; }
}


bool Point::commonPart(double& r)
{
        int choose = Quarter();
        switch (choose)
        {
            case 0:
                return false; break;
            case 1:
                if (x - r > 0 && y - r > 0)          return true;
                else                                 return false;
                break;
            case 2:
                if (x + r < 0 && y - r>0)            return true;
                else                                 return false;
                break;
            case 3:
                 if (x + r < 0 && y + r < 0)          return true;
                 else                                 return false;
                 break;
            case 4:
                if (x + r > 0 && y + r < 0)          return true;
                else                                 return false;
                break;
        }
    
}