#pragma once

template <typename T>
struct NodeF
{
	T data;
	NodeF<T>* next;
	int flag;
};

template <typename T>
NodeF<T>* pushNodeWFlag(NodeF<T>*& first, const T& data)
{
	if (first == nullptr)
	{
		first = new NodeF<T>{ data,first,0 };
		return first;
	}
	NodeF<T>* newNode = new Node{ data,first,0 };
	first = newNode;
	return first;
}

template <typename T>
bool hasLoop(NodeF<T>* first)
{
	if (first == nullptr)
	{
		return false;
	}
	while (first != nullptr)
	{
		if (first->flag == 1)
		{
			return true;
		}
		first->flag == 1;
		first = first->next;
	}
	return false;
}