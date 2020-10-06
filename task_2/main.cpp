#include <iostream>

using namespace std;

class Square
{
    float x,y;
    int len ;

public:
    Square(float=1,float=2);
    Square operator+ (float a);
    Square operator- (float a);
    void writeSquare(Square*,int);
    void MirrorX(Square*,int);
    void MirrorY(Square*,int);
};


int main()
{
    Square*P = new Square;
    Square kw;
    kw.writeSquare(P,5);
    kw.MirrorY(P,5);
    kw.MirrorX(P,5);
    delete P;
    return 0 ;
}


// FUNCTION
Square::Square(float a,float b)
{
    this->x =a; this->y =b;
}
Square Square::operator+(float a)
{
    Square obj;
    obj.x = this->x;
    obj.y = this->y+a;
    return obj;
}
Square Square::operator-(float a)
{
    Square obj;
    obj.x = this->x-a;
    obj.y = this->y;
    return obj;
}
void Square::writeSquare(Square*a,int len)
 {
     Square*pkt = new Square[3];
     pkt[0] = *a + len; // start from right down corner and clockwise to left down
     pkt[1] = pkt[0] - len;
     pkt[2] = *a - len;
     cout << endl<<"Wspolrzedne: ["<<a->x<<","<<a->y<<"] ["<<pkt->x<<","<<pkt->y<<"] ["
     <<(pkt+1)->x<<","<<(pkt+1)->y<<"] ["<<(pkt+2)->x<<","<<(pkt+2)->y<<"]"<<endl;
     delete [] pkt;
 }
 void Square::MirrorY(Square*a,int len)
 {
     a->x = -a->x;
     Square*pkt = new Square[3];
     pkt[0] = *a + len; // start from left up corner and clockwise to left down // y up
     (pkt+1)->x = pkt->x + len; // x to right
     (pkt+1)->y = pkt->y; // have to write y
     pkt[2] = a->x + len;// y down
     cout <<endl<< "Wspolrzedne odbicie Y: ["<<a->x<<","<<a->y<<"] ["<<pkt->x<<","<<pkt->y<<"] ["
     <<(pkt+1)->x<<","<<(pkt+1)->y<<"] ["<<(pkt+2)->x<<","<<(pkt+2)->y<<"]"<<endl;
     delete [] pkt;
 }
 void Square::MirrorX(Square*a,int len)
{
     a->y = -a->y;
     Square*pkt = new Square[3];
     pkt->y = a->y - len; // start from right down corner and clockwise to left down ,y down
     pkt->x = a->x; // we have to write x
     (pkt+1)->x = pkt->x + len; // x to leeft
     (pkt+1)->y = pkt->y;
     pkt[2] = pkt[1] + len; // y up
     cout <<endl<<"Wspolrzedne odbicie X: ["<<a->x<<","<<a->y<<"] ["<<pkt->x<<","<<pkt->y<<"] ["
     <<(pkt+1)->x<<","<<(pkt+1)->y<<"] ["<<(pkt+2)->x<<","<<(pkt+2)->y<<"]"<<endl;
     delete [] pkt;

}
