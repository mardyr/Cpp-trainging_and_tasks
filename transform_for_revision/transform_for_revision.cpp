
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>
#include <cctype>
#include <type_traits>
template<typename T>
void show(T a)
{
    for (auto iterator  : a)
    {
        std::cout << iterator << ",";
    }
    std::cout << "\n";
}
int main()
{
    std::string a = "text";
    std::string b;
    std::vector<int>v, v1{ 1,4,5,6,7,8,3 }, v2;

    std::transform(v1.begin(), v1.end(), std::back_inserter(v),
        std::bind(std::multiplies<int>(), std::placeholders::_1, 10)
    );
    std::copy(v1.begin(), v1.end(),
        std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;

    std::transform(v.begin(), v.end(), v1.begin(), std::back_inserter(v2),
        [](decltype(v)::value_type a, decltype(v1)::value_type b)
        {return a + b * b; }
    );
    show(v2);

    std::for_each(v2.begin(), v2.begin() + 5,
        [](int& v) {v *= -1; });
    show(v2);

    std::transform(a.begin(), a.end(), std::back_inserter(b), std::toupper);
    show(a);
    show(b);
 
    return 0;
}

