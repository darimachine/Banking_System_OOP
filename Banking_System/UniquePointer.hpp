#pragma once

template <class T>
class UniquePointer {

	T* data=nullptr;
	void free();
	void moveFrom(UniquePointer&& other);
public:
	UniquePointer() = default;
	UniquePointer(T* obj);
	UniquePointer(const UniquePointer& other) = delete;
	UniquePointer(UniquePointer&& other) noexcept;

	UniquePointer<T>& operator=(const UniquePointer& other) = delete;
	UniquePointer<T>& operator=(UniquePointer&& other) noexcept;


	T& operator*();
	const T& operator*() const;

	T* operator->();
	const T* operator->() const;
	operator bool();


	~UniquePointer();

};

template<class T>
void UniquePointer<T>::free()
{
	delete data;
}

template<class T>
void UniquePointer<T>::moveFrom(UniquePointer&& other)
{
	data = other.data;
	other.data = nullptr;
}

template<class T>
UniquePointer<T>::UniquePointer(T* obj): data(obj)
{
}

template<class T>
inline UniquePointer<T>::UniquePointer(UniquePointer&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
UniquePointer<T>& UniquePointer<T>::operator=(UniquePointer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
	
}

template<class T>
T& UniquePointer<T>::operator*()
{
	return *data;
	
}

template<class T>
const T& UniquePointer<T>::operator*() const
{
	return *data;
	
}

template<class T>
T* UniquePointer<T>::operator->()
{
	return data;
}

template<class T>
const T* UniquePointer<T>::operator->() const
{
	return data;
}

template<class T>
UniquePointer<T>::operator bool()
{
	return data != nullptr;
}

template<class T>
UniquePointer<T>::~UniquePointer()
{
	free();
}
