#pragma once
#include "node.h"

template <typename T>
Node<T>* push_back(Node<T>*& first, const T& newElData)
{
	if (first == nullptr)
	{
		first = new Node<T>{ newElData, nullptr };
		return first;
	}
	Node<T>* save = first;
	while (save->next != nullptr)
	{
		save = save->next;
	}
	Node<T>* newNode = new Node<T>{ newElData, nullptr };
	save->next = newNode;
	save = newNode;
	return first;
}
template <typename T>
void print(Node<T>* first)
{
	if (first == nullptr)
	{
		throw "Empty list";
	}
	while (first != nullptr)
	{
		std::cout << first->data << " ";
		first = first->next;
	}
}