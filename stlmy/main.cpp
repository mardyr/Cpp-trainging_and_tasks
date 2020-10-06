#include <iostream>
#include <vector>
using namespace std;
template<typename T> void show(T &K)
{
    cout<<"["<<K.size()<<"]";
    for(auto x:K) cout <<x<<" ";
    cout << endl;
}
int main()
{
    vector<int> V1 ={0,34,4,2,5,2};
    show(V1);
    V1.pop_back();
    V1.insert(V1.begin()+1,5);
    V1.emplace(V1.begin()+3,2222);
     show(V1);
    V1.erase(V1.end()-2,V1.end());
    show(V1);
    return 0;
}
