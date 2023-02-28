#pragma once
#include <initializer_list>
#include <assert.h>
#include <utility>
//#include <string>

namespace MyVector
{
	template <class T>
	class Vector
		{
		private:
			size_t m_size;
			size_t m_capacity;
			T* m_data;
		public:
			//Constructors 
			Vector();
			explicit Vector(size_t size);
			explicit Vector(size_t size, const T value);
			Vector(const Vector& vector);
			Vector(Vector&& vector) noexcept;
			Vector(const std::initializer_list<T>& list);

			//Destructor
			~Vector();

			//Assigment operator overloading 
			Vector& operator= (const Vector& vector);
			Vector& operator= (Vector&& vector) noexcept;
			Vector& operator= (const std::initializer_list<T>& list);

			//Iterators
			T* begin();
			T* end();
			const T* cbegin() const;
			const T* cend() const;

			//Size, capacity
			bool empty() const;
			size_t size() const;
			size_t capacity() const;
			void resize(size_t newsize);
			void reverse();

			//Access to array elements
			T& operator[] (const size_t index);
			T& at(const size_t index);

			//Methods of adding and subtracting elements
			void push_back(const T& value);
			void pop_back();
			void clear();
			void insert(const size_t index, const T value);
			T* insert(const T* iter, const T value);
			void erase(const size_t index);
			T* erase(const T* iter);
			//void swap(Vector& vector);
		};
	}