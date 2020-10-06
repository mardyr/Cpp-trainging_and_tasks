// binary.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <stack>
#include <sstream>
#include <regex>
std::string BinaryConversion(int i);
int MaxZeros(std::string s);
int main()
{
    int c = 1041;
    std::cout << BinaryConversion(c) << std::endl;
    std::string temp = BinaryConversion(c);
    std::cout<<MaxZeros(temp);
}

std::string BinaryConversion(int i)
{
    std::stringstream ss;
    std::stack<int> s;
    while (i>0)
    {   
        s.push(i % 2);
        i = i / 2;
    }
    while (!s.empty())
    {
        ss << s.top();
        s.pop();
    }
    return ss.str();
}
int MaxZeros(std::string s)
{
    std::smatch matches;
    int max=0;
    std::regex pattern("0+");
    while (regex_search(s, matches, pattern))
    {
        for (unsigned i = 0; i < matches.size(); i++)
        {
            if (matches.length(i) > max) { max = matches.length(i); }
        }
        s = matches.suffix().str();

    }
    return max;
}