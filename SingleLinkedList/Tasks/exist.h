#pragma once
#include "node.h"

template <typename T>
bool exists(Node<T>* first, T x)
{
	if (first == nullptr)
	{
		return false;
	}
	Node<T>* save = first;
	while (save != nullptr)
	{
		if (save->data == x)
		{
			return true;
		}
		save = save->next;
	}
	return false;
}