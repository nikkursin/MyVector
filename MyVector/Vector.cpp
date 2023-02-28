#include "Vector.h"

using namespace MyVector;

template Vector<char>;
template Vector<int>;
template Vector<short>;
template Vector<long>;
template Vector<long long>;
template Vector<double>;
template Vector<float>;
template Vector<long double>;
template Vector<size_t>;
//template Vector<std::string>;



//Constructors and destructor 
template<typename T>
Vector<T>::Vector()
{
	m_capacity = 1;
	m_size = 0;
	m_data = nullptr;
}

template<typename T>
Vector<T>::Vector(size_t size)
{
	m_size = size;
	m_capacity = 2 * m_size;
	m_data = new T[m_capacity];
	for (size_t i = 0; i < m_size; i++) {
		m_data[i] = 0;
	}
}

template<typename T>
Vector<T>::Vector(size_t size, const T value)
{
	m_size = size;
	m_capacity = 2 * m_size;
	m_data = new T[m_capacity];
	for (size_t i = 0; i < m_size; i++) {
		m_data[i] = value;
	}
}

template<typename T>
Vector<T>::Vector(const Vector& vector) :
	Vector(vector.size())
{
	if (vector.m_size)
	{
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = vector.m_data[i];
		}
	}
	else
		m_data = 0;
}

template<typename T>
Vector<T>::Vector(Vector&& vector) noexcept:
	Vector(vector.size())
{
	vector.m_capacity = 0;
	vector.m_size = 0;
}

template<typename T>
Vector<T>::Vector(const std::initializer_list<T>& list) :
	Vector(list.size())
{
	int count = 0;
	for (auto& element : list)
	{
		m_data[count] = element;
		++count;
	}
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] m_data;
	m_data = nullptr;
}




//Assigment operator overloading 
template<typename T>
Vector<T>& Vector<T>:: operator= (const Vector& vector)
{
	if (&vector == this)
		return *this;

	delete[] m_data;

	if (vector.m_data)
	{
		m_data = new T[m_capacity];
		for (int i = 0; i < m_size; ++i)
			m_data[i] = vector.m_data[i];
	}
	else
		m_data = 0;

	return *this;

}

template<typename T>
Vector<T>& Vector<T>:: operator= (Vector&& vector) noexcept
{
	if (&vector == this)
		return *this;

	delete[] m_data;

	m_size = vector.m_size;
	m_data = vector.m_data;
	vector.m_capacity = 0;
	vector.m_size = 0;
	vector.m_data = nullptr;


	return *this;
}

template<typename T>
Vector<T>& Vector<T>:: operator= (const std::initializer_list<T>& list)
{
	delete[] m_data;

	int count = 0;
	for (auto& element : list)
	{
		m_data[count] = element;
		++count;
	}

	return*this;
}

//Iterators
template<typename T>
T* Vector<T>::begin()
{
	if (m_size != 0)
		return &m_data[0];
}

template<typename T>
T* Vector<T>::end()
{
	if (m_size != 0)
		return &m_data[m_size - 1];
}

template<typename T>
const T* Vector<T>::cbegin() const
{
	if (m_size != 0)
		return &m_data[0];
}

template<typename T>
const T* Vector<T>::cend() const
{
	if (m_size != 0)
		return &m_data[m_size - 1];
}


//Size, capacity
template<typename T>
bool Vector<T>::empty() const
{
	return m_size == 0;
}

template<typename T>
size_t Vector<T>::size() const
{
	return m_size;
}

template<typename T>
size_t Vector<T>::capacity() const
{
	return m_capacity;
}

template<typename T>
void Vector<T>::resize(size_t newsize)
{
	if (newsize > m_size)
	{
		size_t capacity = newsize * 2;
		T* result = new T[capacity];

		for (int i = 0; i < m_size; ++i)
			result[i] = m_data[i];

		for (int i = m_size; i < newsize; ++i)
			result[i] = 0;

		delete[] m_data;
		m_capacity = capacity;
		m_size = newsize;
		m_data = result;
	}

	if (newsize < m_size)
	{
		m_size = newsize;
	}

}

template<typename T>
void Vector<T>::reverse()
{
	T* tmp = new T[m_capacity];

	for (size_t i = 0; i < m_size; i++)
		tmp[i] = m_data[m_size - 1 - i];

	for (size_t i = 0; i < m_size; i++)
		m_data[i] = tmp[i];

	delete[] tmp;
}


//Element access 
template<typename T>
T& Vector<T>:: operator[] (const size_t index)
{
	return m_data[index];
}

template<typename T>
T& Vector<T>::at(const size_t index)
{
	assert(index >= 0 && index < m_size);
	return m_data[index];
}


//Methoad of adding and subtracting elements 
template<typename T>
void Vector<T>::push_back(const T& value)
{
	if (m_size == m_capacity || m_size == 0)
	{
		size_t capacity = m_capacity * 2;
		T* result = new T[capacity];

		for (size_t i = 0; i < m_size; ++i)
			result[i] = m_data[i];

		delete[] m_data;
		m_capacity = capacity;
		m_data = result;
	}

	m_data[m_size] = value;
	m_size++;
}

template<typename T>
void Vector<T>::pop_back()
{
	if (m_size != 0)
		m_size--;
}

template<typename T>
void Vector<T>::clear()
{
	delete[] m_data;
	m_data = nullptr;
	m_size = 0;
}

template<typename T>
void Vector<T>::insert(const size_t index, const T value)
{

	if (m_size != 0)
	{
		m_size++;
		m_capacity = m_size * 2;
		T* tmp = new T[m_capacity];

		for (size_t i = index; i < m_size - 1; i++)
			tmp[i] = m_data[i];

		m_data[index] = value;

		for (size_t i = index; i < m_size; i++)
			m_data[i + 1] = tmp[i];

		delete[]  tmp;
	}

	/*if (m_size == 0 && index == 0)
	{
		m_size++;
		m_capacity = m_size * 2;
		m_data = new T[m_capacity];
		m_data[0] = value;
	}*/
}

template<typename T>
T* Vector<T>::insert(const T* iter, const T value)
{
	size_t position = iter - m_data;

	if (m_size != 0)
	{
		m_size++;
		m_capacity = m_size * 2;
		T* tmp = new T[m_capacity];

		for (size_t i = position; i < m_size - 1; i++)
			tmp[i] = m_data[i];


		m_data[position] = value;

		for (size_t i = position; i < m_size; i++)
			m_data[i + 1] = tmp[i];

		delete[]  tmp;
	}

	if (m_size == 0 && position == 0)
	{
		m_size++;
		m_capacity = m_size * 2;
		m_data = new T[m_capacity];
		m_data[0] = value;
	}

	return &m_data[position];
}

template<typename T>
void Vector<T>::erase(const size_t index)
{
	if (m_size != 0)
	{
		T* tmp = new T[m_capacity];

		for (size_t i = index; i < m_size + 1; i++)
			tmp[i] = m_data[i + 1];

		for (size_t i = index; i < m_size - 1; i++)
			m_data[i] = tmp[i];

		m_size--;
		delete[] tmp;
	}
}

template<typename T>
T* Vector<T>::erase(const T* iter)
{
	size_t position = iter - m_data;

	if (m_size != 0)
	{
		T* tmp = new T[m_capacity];

		for (size_t i = position; i < m_size + 1; i++)
			tmp[i] = m_data[i + 1];

		for (size_t i = position; i < m_size - 1; i++)
			m_data[i] = tmp[i];

		m_size--;
		delete[] tmp;
	}

	return &m_data[position];
}

/*template<typename T>
void Vector<T>::swap(Vector& vector)
{
	size_t stmp = m_size;
	size_t ctmp = m_capacity;
	T* tmp = new T[m_capacity];
	tmp = m_data;

	m_size = vector.m_size;
	m_capacity = vector.m_capacity;
	m_data = vector.m_data;

	vector.m_size = stmp;
	vector.m_capacity = ctmp;
	vector.m_data = tmp;

	delete[] tmp;
}*/