#pragma once
#include "node.h"
#include "swapnodes.h"

template <typename T>
Node<T>* lastToFirst(Node<T>*& first)
{
	if (first == nullptr || first->next == nullptr)
	{
		return first;
	}
	if (first->next->next == nullptr)
	{
		swapNodes(first, first->data, first->next->data);
		return first;
	}
	Node<T>* save = first;
	Node<T>* curr = first;
	while (curr->next != nullptr)
	{
		curr = curr->next;
	}
	swapNodes(first, save->data, curr->data);
	return first;
}
