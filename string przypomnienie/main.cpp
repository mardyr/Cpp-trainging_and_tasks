#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file;
    string temp;
    file.open("test.txt");
    if(!file.good())
    {
        cerr<<"ERROR"<<endl;
    }
    while(getline(cin,temp)&& temp!="");
    {
        file<<temp<<endl;
    }
    file.close();
    return 0;
}
