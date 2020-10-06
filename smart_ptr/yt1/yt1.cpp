// yt1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <utility>
#include <memory>
struct MyInt
{
    int i_;
    MyInt(int i) : i_{ i } {}
    ~MyInt() { std::cout << "Good bye from " << i_ << std::endl; }
};

int main()
{
    std::unique_ptr<MyInt> uniquePtr = std::make_unique<MyInt>(1997);

    std::cout << uniquePtr.get() << std::endl;

    std::unique_ptr<MyInt> uniquePtr2{ std::move(uniquePtr) };

    std::cout << uniquePtr.get() << std::endl;
    std::cout << uniquePtr2.get() << std::endl;

    {
        std::unique_ptr<MyInt> myptr = std::make_unique<MyInt>(-2);
    }

    uniquePtr.reset(new MyInt(9));  // niszczymy obiekt i przypisujemy wladze nad nowym

    MyInt* myInt = uniquePtr2.release(); // zwalniam zasoby i zabieramy innym

    delete myInt;




}

