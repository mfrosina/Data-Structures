#pragma once
#include "node.h"
#include "size.h"
#include "push.h"

template <typename T>
Node<T>* constructList(Node<T>*& first, T n)
{
	if (first == nullptr)
	{
		return nullptr;
	}
	size_t s = size(first);
	size_t lastN = s - n + 1;
	Node<T>* curr = first;
	Node<T>* res = nullptr;
	for (size_t i = 1; i <= s; i++)
	{
		if (i > n && i < lastN)
		{
			push_back(res, curr->data);
		}
		curr = curr->next;
	}
	return res;
}