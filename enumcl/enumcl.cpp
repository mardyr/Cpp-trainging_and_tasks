// enumcl.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
enum class Color {red,green,blue};
void printEnum(Color c)
{
	switch (c)
	{
	case Color::red :
		std::cout << "red\n";
		break;
	case Color::blue :
		std::cout << "blue\n";
		break;
	case Color::green :
		std::cout << "green\n";
		break;
	}
}


int main()
{

	int tab[] = { 1,2,4,5,6,3 };
	int n = sizeof(tab) / sizeof(tab[0]);
	std::vector<int> v(tab,tab+n);
	for (auto& i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::vector<int> v1(v.begin(), v.end() - 2);

	for (auto& i : v1)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;

    Color c = Color::red;
	printEnum(c);




	return 0;
}

