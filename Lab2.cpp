#pragma once
#include"stdio.h"
template <class T>
class line 
{
	T* _data;
	size_t _size;
public:
<<<<<<< HEAD
	
	line(const T* data, const size_t size)
=======
	line(const T* data, size_t size)
>>>>>>> d1578948102b775d77bed470b5b7b37b9a05a07d
	{
		int count = 0;
		while (data[count])
			count++;
		_size = count;
		_data = new T[_size + 1];
		int i = 0;
		for (; i < _size + 1; i++)
			_data[i] = data[i];
	}

<<<<<<< HEAD
	line(const int size)
	{
		_size = size;
		_data = new char[_size + 1];
	}

	line(const line& data)
	{
		_size = s._size;
		_data = new char[_size + 1];
		for (int i = 0; i < _size + 1; i++)
			_data[i] = s._data[i];
	}

	line::~line()
	{
		delete[]_data;
	}

=======
>>>>>>> d1578948102b775d77bed470b5b7b37b9a05a07d
	line& operator=(const line& s)
	{
		if (this == &s)	return *this;
		if (_size != s._size)
		{
			delete[]_data;
			_data = new T[s._size + 1];
		}
		for (int i = 0; i < s._size + 1; i++)
			_data[i] = s._data[i];
		return *this;
	}

	T& operator[](const int index)const
	{
		if (index < 0 || index >= _size)
			throw"Invalid index\n";
		return _data[index];
	}

	line operator+(const line& s)const
	{
		if (!_size)
			return s;
		if (!s._size)
			return *this;
		line res(_size + s._size);
		for (int i = 0; i < _size; i++)
			res._data[i] = _data[i];
		for (int j = 0; j < s._size + 1; j++)
			res._data[j + _size] = s._data[j];
		return res;
	}

	line operator*(const int pow)
	{
		if (!_size)
			return *this;
		if (pow <= 0)
			throw"Invalid ratio\n";
		line res(_size * pow);
		for (int i = 0; i < pow; i++)
			for (int j = 0; j < (i == pow - 1 ? _size + 1 : _size); j++)
				res._data[j + i * _size] = _data[j];
		return res;
	}
};
