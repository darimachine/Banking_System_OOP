#pragma once
#include <iostream>

template <class T, class D>
class Pair {
	T first;
	D second;

public:
	Pair() = default;
	Pair(const T& _first, const D& _second);
	Pair(T&& _first, D&& second);

	//get
	T& getFirst();
	D& getSecond();

	const T& getFirst() const;
	const D& getSecond() const;
	//set
	void setFirst(const T& first);
	void setFirst(T&& first);

	void setSecond(const D&);
	void setSecond(D&&);
};

template<class T, class D>
Pair<T, D>::Pair(const T& _first, const D& _second) :first(_first), second(_second)
{
}

template<class T, class D>
Pair<T, D>::Pair(T&& _first, D&& _second)
	: first(std::move(_first)), second(std::move(_second))
{

}
template<class T, class D>
T& Pair<T, D>::getFirst()
{
	return first;

}
template<class T, class D>
D& Pair<T, D>::getSecond()
{
	return second;

}
template<class T, class D>
const T& Pair<T, D>::getFirst() const {
	return first;
}
template<class T, class D>
const D& Pair<T, D>::getSecond() const {
	return second;
}

template<class T, class D>
void Pair<T, D>::setFirst(const T& _first)
{
	first = _first;
}

template<class T, class D>
void Pair<T, D>::setFirst(T&& _first)
{
	first = std::move(_first);
}

template<class T, class D>
void Pair<T, D>::setSecond(const D& _second)
{
	second = _second;
}

template<class T, class D>
void Pair<T, D>::setSecond(D&& _second)
{
	second = std::move(_second);
}
