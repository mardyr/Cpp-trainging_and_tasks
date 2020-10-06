// ordered_map.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
int main()
{
    std::vector<std::string> wordlist{ "now", "is","the","time",
                                        "for","all","good","people","to"
                                            ,"the","aid","of","their","party" };
    typedef std::map<std::string, int> WORD_MAP;
    WORD_MAP map;
    for (const auto& word : wordlist)
    {
        ++map[word];
    }
    for (auto const& i : map)
    {
        std::cout << i.first << " " << i.second << std::endl;
    }

    struct total_it
    {
        explicit total_it(int i) : _i(i) {}

        void operator()(const WORD_MAP::value_type& p)
        {
            _i += p.second;
        }

        int _i;
    };

    auto total = 0;

    total_it it  = std::for_each(map.begin(), map.end(), total_it(total));

    total = it._i;

    std::cout << "Total number of words = " << total << std::endl;

    total = 0;

    std::for_each(map.begin(), map.end(), [&total](const WORD_MAP::value_type& p)
        {
            total += p.second;
        });
    std::cout << "Total number of words = " << total << std::endl;



}

