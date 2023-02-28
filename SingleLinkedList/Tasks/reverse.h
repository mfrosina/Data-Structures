#pragma once
#include "node.h"

template <typename T>
Node<T>* reverse(Node<T>*& first)
{
	Node<T>* curr = first;
	Node<T>* prev = nullptr;
	Node<T>* temp = nullptr;
	while (curr != nullptr)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	first = prev;
	return first;
}
