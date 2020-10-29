
#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include <algorithm>
class A
{
	int x;
public:
	A(int param) :x{ param } {}
	bool operator < (const A& obj) const 
	{
		return x < obj.x;
	}
	bool operator > (const A& obj) const
	{
		return x > obj.x;
	}
	friend std::ostream& operator << (std::ostream& cout, const A& obj);
	
};
std::ostream& operator << (std::ostream& cout, const A& obj)
{
	cout <<"["<< obj.x <<"] " ;
	return cout;
}



bool sortbyVal(std::pair<A, int>& a, std::pair<A, int>& b)
{
	return a.second < b.second;
}




int main()
{
	std::map<A, int> m;
	A obj = { 9 }, obj1 = { 11 }, obj2 = { 22 }, obj3 = { 33 }, obj4 = { 44 };
	m.insert({ A(10),3 });
	m.insert({ obj,2 });
	m.insert({ obj1,0 });
	m.insert({ obj2,5 });
	m.insert({ obj3,6 });
	m.insert({ obj4,44 });
	if (auto [k, v] = m.insert({ A(10),1 }); v == false) // try insert
	{
		std::cout <<k->first << "This key already exists" << std::endl;
	}
	for (auto& [k, v] : m) // print map
	{
		std::cout << k << " " << v << std::endl;
	}

	//SORT BY VALUE

	std::vector<std::pair<A, int>> vec;

	auto it = m.begin();

	for (it; it != m.end(); ++it)
	{
		vec.push_back({ it->first,it->second });

	}

	sort(vec.begin(), vec.end(), sortbyVal);
	std::cout << "SORTED BY VALUE\n";
	for (auto& element : vec)
	{
		std::cout << element.first << " " << element.second << std::endl;
	}
}

