#pragma once
#include "node.h"
#include <stdexcept>
#include "reverse.h"

template <typename T>
T get_ith(Node<T>* first,size_t n)
{
	reverse(first);
	for (size_t i = 0; i < n; i++)
	{
		if (first == nullptr || first->next==nullptr)
		{
			throw std::out_of_range("Pos out of bounds");
		}
		first = first->next;
	}
	return first->data;
}
