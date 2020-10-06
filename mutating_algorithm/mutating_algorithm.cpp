// mutating_algorithm.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <ctime>
#include <iterator>
#include <numeric>
#include <random>
int main()
{
    /*srand(time(nullptr));

    std::vector<int> v;

    std::string str = "my title";
    std::transform(str.cbegin(), str.cend(), str.begin(),
        [](auto c) {return islower(c) ? toupper(c) : c; });

    std::cout << str << std::endl;

    std::generate_n(back_inserter(v), 10, rand);

    std::vector<int> v2(10, 20);

    std::copy(v.begin(), v.end(),
        std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;*/


    std::vector<int> v(10), v2(20);

    std::fill(v.begin(), v.end(), 1);
    std::partial_sum(v.begin(), v.end(), v.begin());

    fill(v2.begin(), v2.begin() + 15, 2);
    std::partial_sum(v2.begin(), v2.end(), v2.begin());
    std::shuffle(v2.begin(), v2.end(),
        std::default_random_engine(time(nullptr)));
   
    std::shuffle(v.begin(), v.end(),
        std::mt19937(std::random_device()()));

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));

}

