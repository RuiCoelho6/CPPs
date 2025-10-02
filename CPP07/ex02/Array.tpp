#include <stdexcept>

template<typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _elements(n ? new T[n]() : NULL), _size(n) {}

template<typename T>
Array<T>::Array(const Array<T>& other) : _elements(other._size ? new T[other._size] : NULL), _size(other._size)
{
	for (unsigned int i = 0; i < _size; ++i)
		_elements[i] = other._elements[i];
}

template<typename T>
Array<T>::~Array()
{
	delete [] _elements;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array<T>& other)
{
	if (this == &other)
		return *this;

	T	*new_elems = other._size ? new T[other._size]() : NULL;
	for (unsigned int i = 0; i < other._size; ++i)
		new_elems[i] = other._elements[i];

	delete[] _elements;
	_elements = new_elems;
	_size = other._size;
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Array index out of range");
	return (_elements[index]);
}

template<typename T>
const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Array index out of range");
	return (_elements[index]);
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}
