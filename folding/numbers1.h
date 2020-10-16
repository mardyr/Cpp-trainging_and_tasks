#pragma once

void _007(); // folding


#include <iostream>
#include <string>
using namespace std;

template <typename T1>
void printSTL(const T1& stl, const std::string& separator, bool size) {	
	auto elems = stl.size();			
	for (const auto& elem : stl) {
		std::cout << elem;
		if (--elems > 0) std::cout << separator;
	}	
	if (size) std::cout << "\t[count: " << stl.size() << " elements]" << std::endl;
	std::cout << std::endl;
}
template <typename T1, size_t N>
void printSTL(T1(&stl)[N], const std::string& separator, bool size) {	
	auto elems = N;	
	for (const auto& elem : stl) {
		std::cout << elem;
		if (--elems > 0) std::cout << separator;
	}	
	if (size) std::cout << "\t[count: " << N << " elements]" << std::endl;
	std::cout << std::endl;
}
template <typename T1, typename T2>
void printSTL(const pair<T1, T2>& stl, const std::string& separator) {
	std::cout << stl.first << separator << stl.second << std::endl;
}

template <size_t I = 0, typename ... Telems>
void printSTL(std::tuple<Telems...>& tup, const std::string& separator, bool size=false) {
	if constexpr (I == sizeof...(Telems)) {
		if (size) std::cout << "\t[" << sizeof...(Telems) << "]";
		std::cout << std::endl;
		
		return; // stop rekurencja
	}
	else {
		std::cout << get<I>(tup);
		if (I+1 < sizeof...(Telems)) cout << separator;
		printSTL<I + 1>(tup, separator, size);
	}
}
// ck:96
// c++11: 357
// c++17 rec: 66