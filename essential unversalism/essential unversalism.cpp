// essential unversalism.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


template <typename Container>
void write_to_cout(Container& c, const char* delimiter = " ")
{
    std::copy(c.begin(), c.end(), std::ostream_iterator<Container::value_type>(std::cout, delimiter));
    std::cout << '\n';
}

template<typename Container, typename ... Param>
void massInsertion(Container& c, Param ... args)
{
    (c.emplace_back(args), ...);
}

template<typename Container, typename Pred>
void myRemove(Container& c, Pred pred)
{
    const auto new_end = std::remove_if(c.begin(), c.end(), pred);

    c.erase(new_end, c.end());
}


int main()
{
    std::vector<int> v;
    massInsertion(v, 10, 13, 16, 23, 25, 34, 43, 54, 57, 66);
    write_to_cout(v);
    myRemove(v, [](int i) {return i > 40; });
    write_to_cout(v);
}

