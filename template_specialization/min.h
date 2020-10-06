#pragma once


template<typename T>
T min(T a, T b)
{
	return a < b ? a : b;
}

template<typename T>
T min(T a, T b, T c)
{
	if (min(a, b) < c) return min(a, b);
	else return c;
}