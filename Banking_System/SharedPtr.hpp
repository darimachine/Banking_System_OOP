#pragma once
#include "iostream"

struct Counter {
	int useCount = 0;
	int weakCount = 0;

public:
	void addSharedPtr()
	{
		useCount++;
		if (useCount == 1)
		{
			weakCount++;
		}
	}
	void addWeakPtr()
	{
		weakCount++;
	}
	void removeSharedPtr()
	{
		useCount--;
		if (useCount == 0)
		{
			weakCount--;
		}
	}
	void removeWeakPtr()
	{
		weakCount--;
	}
};
template <class T>
class SharedPtr {
	T* data=nullptr;
	Counter* counter=nullptr;
	void free();
	void copyFrom(const SharedPtr<T>& other);
	void moveFrom(SharedPtr<T>&& other);
public:
	SharedPtr() = default;
	SharedPtr(T* obj);
	SharedPtr(const SharedPtr<T>& other);
	SharedPtr(SharedPtr<T>&& other) noexcept;

	SharedPtr<T>& operator=(const SharedPtr<T>& other);
	SharedPtr<T>& operator=(SharedPtr<T>&& other) noexcept;

	T& operator*();
	const T& operator*() const;

	T* operator->();
	const T* operator->() const;

	~SharedPtr();
};

template<class T>
void SharedPtr<T>::free()
{
	if (data == nullptr || counter == nullptr) {
		return nullptr;
	}
	counter->removeSharedPtr();
	if (counter->useCount==0)
	{
		delete data;
	}
	if (counter->weakCount == 0)
	{
		delete counter;
	}
}

template<class T>
void SharedPtr<T>::copyFrom(const SharedPtr<T>& other)
{
	data = other.data;
	counter = other.counter;
	if (counter)
	{
		counter->addSharedPtr();
	}
}

template<class T>
void SharedPtr<T>::moveFrom(SharedPtr<T>&& other)
{
	data = other.data;
	other.data = nullptr;

	counter = other.counter;
	other.counter = nullptr;
}

template<class T>
SharedPtr<T>::SharedPtr(T* obj) : data(obj)
{
	if (data)
	{
		counter = new Counter();
		counter->addSharedPtr();
	}
}

template<class T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& other)
{
	copyFrom();
}

template<class T>
SharedPtr<T>::SharedPtr(SharedPtr&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
	// TODO: insert return statement here
}

template<class T>
T& SharedPtr<T>::operator*()
{
	return *data;
	
}

template<class T>
const T& SharedPtr<T>::operator*() const
{
	return *data;
	// TODO: insert return statement here
}

template<class T>
T* SharedPtr<T>::operator->()
{
	return data;
}

template<class T>
const T* SharedPtr<T>::operator->() const
{
	return data;
}

template<class T>
inline SharedPtr<T>::~SharedPtr()
{
	free();
}
