#pragma once
#include "node.h"
#include "swapnodes.h"

template <typename T>
Node<T>* pairwiseSwap(Node<T>*& first)
{
	if (first == nullptr || first->next == nullptr)
	{
		return first;
	}
	Node<T>* curr = first;
	while (curr != nullptr && curr->next != nullptr)
	{
		swapNodes(first, curr->data, curr->next->data);
		curr = curr->next;
	}
	return first;
}
