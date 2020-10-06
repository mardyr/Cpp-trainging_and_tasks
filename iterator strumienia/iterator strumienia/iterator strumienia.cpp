// iterator strumienia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <algorithm>

int main()
{
    std::vector<int> v;
    std::istream_iterator<int> EndOfFile;
    std::copy(std::istream_iterator<int>(std::cin),
        EndOfFile,
        std::back_inserter(v)
    );
    std::cout << std::endl;
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<int>(std::cout, "::")
    );
    std::cout << std::endl;
    std::unique_copy(v.begin(), v.end()
        , std::ostream_iterator<int>(std::cout, ",")
    );

    std::ostream_iterator<int> out(std::cout, ":");


}


