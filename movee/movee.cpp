// movee.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct Foo
{
    Foo() = default;
    Foo(int&& _i) : i{move(new int(_i))} {}
    Foo(Foo const& obj)
    {
        i = new int(*obj.i);
        
    }
    Foo& operator = (Foo const & rhs)
    {
        i = new int(*(rhs.i));
        return *this;
    }
    Foo& operator = (Foo&& rhs)  // rvalue ref
    {
        i = rhs.i;
        rhs.i = nullptr;
        return *this;
    }
    // Foo(Foo&& obj) = default;
    ~Foo() { delete i; }
    int* i = nullptr;
    friend std::ostream& operator << (std::ostream& cout, Foo& obj);
};
std::ostream& operator << (std::ostream& cout, Foo& obj)
{
    cout << *(obj.i);
    return cout;
}
//-------------------------------------------------------------------------------

struct Foo2
{
    Foo2() = default;
    Foo2(vector<int>&& v)
        : v(move(v)) {}

    std::vector<int> v;

};

void FillVector(vector<int>& v) {}

int main()
{
    vector<int> v;
    FillVector(v);
    if (!v.empty())
    {
        Foo2 f(move(v)); // here move is rvalue , don't work on that
    }



    Foo f;
    {
        Foo f2;
        f2.i = new int(42);
        f = move(f2); // expiring value 
    }

    Foo f3(33);
}

