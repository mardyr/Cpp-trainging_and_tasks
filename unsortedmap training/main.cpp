#include "main.h"
#include <unordered_map>

template<typename T> void show(T &K)
{
    cout<<"["<<K.size()<<"]\n";
    for(auto x:K)
    {
        cout <<setfill(' ')<<setw(20)<<x.first<<setfill('.')<<setw(20)<<x.second<<endl;
    }
    cout << endl;
}
int main()
{
    unordered_map <string,double> stats ={{"sila",50.4},{"masa",54.2}};
    stats.emplace("wdziek",30.1);
    stats.emplace("rozum",20);
    stats["magia"] = 30;
    show(stats);
    stats["rozum"] = 10;
    show(stats);
    stats.erase("rozum");
    show(stats);
    stats.erase(stats.begin());
    show(stats);
    stats.clear();
     show(stats);
    return 0;
}
