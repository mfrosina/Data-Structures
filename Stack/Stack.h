#pragma once
#include <exception>
#include <vector>

template <typename T>
class Stack
{
private:
	std::vector<T> data;
	size_t size;
	size_t capacity;

public:
	Stack()
	{
		capacity = 8;
		size = 0;
	}
	Stack(const size_t& _capacity)
	{
		capacity = _capacity;
	}
	Stack(const Stack& other)
	{
		for (size_t i = 0; i < other.size; i++)
		{
			data[i] = other.data[i];
		}
		capacity = other.capacity;
		size = other.size;
	}
	Stack& operator=(const Stack& other)
	{
		if (this != &other)
		{
			for (size_t i = 0; i < other.size; i++)
			{
				data[i] = other.data[i];
			}
		}
		capacity = other.capacity;
		size = other.size;
		return *this;
	}
	
	void push(const T& elementData)
	{
		if (size >= capacity)
		{
			throw std::exception("Can not add element");
		}
		data.push_back(elementData);
		size++;
	}
	T& top()
	{
		if (isEmpty())
		{
			throw std::exception("Empty stack");
		}
		return data[size - 1];
	}
	void pop()
	{
		if (isEmpty())
		{
			throw std::exception("Empty stack");
		}
		data.pop_back();
		size--;
	}

	bool isEmpty()
	{
		return data.size() == 0;
	}
	size_t getSize()const
	{
		return data.size();
	}
};
