// is_sort.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <algorithm>


class Point
{
private:
    int x, y;
public:
    Point(int _x, int _y) : x{ _x }, y{ _y }{}
    bool operator < (const Point&rhs)
    {
        return (x + y) > (rhs.x + rhs.y);
    }
    int getX()const { return x; }
    int getY()const { return y; }
};



int main()
{
    std::vector<Point> p{ {1, 2}, { 2,4 }, { 13,1 }, { -1,4 }};
    std::sort(p.begin(), p.end());
    for (auto& a : p) { std::cout << a.getX() << " " << a.getY() << std::endl; }
    std::cout << is_sorted(p.begin(), p.end());
}

