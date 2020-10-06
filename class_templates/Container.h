#pragma once

template<typename T>
class Container
{
public:
	explicit Container(const T& arg);
	T increase();

private:
	T element;
};

template<typename T>
Container<T>::Container(const T& arg)
	: element{ arg } {}

template<typename T>
T Container<T>::increase()
{
	return ++element;
}

