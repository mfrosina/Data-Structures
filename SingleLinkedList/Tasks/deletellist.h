#pragma once
#include "node.h"
template <typename T>
void pop(Node<T>*& first)
{
	if (first == nullptr)
	{
		return;
	}
	Node<T>* save = first;
	first = first->next;
	delete[]save;
}
template <typename T>
void deletellist(Node<T>*& first)
{
	if (first == nullptr)
	{
		return;
	}
	while (first != nullptr)
	{
		pop(first);
	}
}