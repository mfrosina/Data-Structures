#pragma once
#include "node.h"

template <typename T>
Node<T>* removeAll(Node<T>*& first, T element)
{
	if (first == nullptr)
	{
		return nullptr;
	}
	
	while (first && first->data == element)
	{
		first = first->next;
	}
	Node<T>* curr = first;
	Node<T>* temp = nullptr;
	while (curr != nullptr)
	{
		if (curr->data == element)
		{
			temp->next = curr->next;
		}
		else
		{
			temp = curr;
		}
		curr = curr->next;
	}
	return first;
}
