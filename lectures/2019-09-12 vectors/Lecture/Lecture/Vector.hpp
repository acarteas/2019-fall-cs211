#pragma once
#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <exception>
using namespace std;

template <typename T>
class Vector
{
private:
	T* _data = nullptr;
	int _physical_size = 0;
	int _logical_size = 0;

	void checkResize()
	{
		//resize if out of space
		if (_physical_size == _logical_size)
		{
			//create new array
			_physical_size *= 2;
			T* new_data = new T[_physical_size];

			//copy over existing data
			for (int i = 0; i < _logical_size; i++)
			{
				new_data[i] = _data[i];
			}

			//delete old array
			delete[] _data;

			//assume control over new data
			_data = new_data;
		}
	}

public:

	Vector(int initial_physical_size = 11)
		: _physical_size(initial_physical_size)
	{
		//: code takes the place of this
		//_physical_size = initial_physical_size;
		_data = new T[_physical_size];
	}

	//copy constructor
	Vector(const Vector<T>& other) : Vector()
	{
		for (int i = 0; i < other.size(); i++)
		{
			push_back(other.at(i));
		}
	}

	//copy operator
	Vector<T>& operator=(const Vector<T>& other)
	{
		for (int i = 0; i < other.size(); i++)
		{
			push_back(other.at(i));
		}
		return *this;
	}

	~Vector()
	{
		delete[] _data;
	}

	int size() const
	{
		return _logical_size;
	}

	void push_back(const T& item)
	{
		checkResize();
		_data[_logical_size] = item;
		_logical_size++;
	}

	T& at(const int& index)
	{
		//bounds checking
		if (index < 0 || index > _logical_size)
		{
			throw out_of_range{ "Index is out of range" };
		}
		return _data[index];
	}

	const T& at(const int& index) const
	{
		//bounds checking
		if (index < 0 || index > _logical_size)
		{
			throw out_of_range{ "Index is out of range" };
		}
		return _data[index];
	}

	T& operator[](const int& index)
	{
		return at(index);
	}

	void operator>>(const T& item)
	{
		push_back(item);
	}

};

#endif