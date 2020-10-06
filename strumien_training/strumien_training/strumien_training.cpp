// strumien_training.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> v;
    std::istream_iterator<int> EndOfStream;
    std::copy(std::istream_iterator<int>(std::cin),
        EndOfStream,
        std::back_inserter(v)
    );
    std::cout << std::endl;
    std::unique_copy(v.begin(), v.end(),
        std::ostream_iterator<int>(std::cout, "::")
    );
}

