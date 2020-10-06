// unary operator.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

class Point
{
    int x, y;
    int arr[2];
public:
    Point(int _x = 0, int _y = 0)
    {
        arr[0] = _x;
        arr[1] = _y;
    }
    void print() { std::cout << "x: " << arr[0] << " y: " << arr[1] << std::endl; }
    Point operator -() { return Point(-x, -y); }
    int& operator [](int pos)
    {
        if (pos == 0) return arr[0];
        else if (pos == 1) return arr[1];
        else { std::cout << "Out of bound case.\n"; exit(0); }
    }
};

int main()
{
    Point p1(2, 4),p2;
    p1.print();
    //p2.print();
    p1[0] = 42;
    p1[1] = 21;
    p1.print();
    //Point p3 = -p1;
    //p3.print();
    return 0;
}
