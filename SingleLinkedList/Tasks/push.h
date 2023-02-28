#pragma once
#include "node.h"

template <typename T>
Node<T>* push(Node<T>*& first, const T& newElementData)
{
	if (first == nullptr)
	{
		first = new Node<T>{ newElementData, nullptr };
		return first;
	}
	Node<T>* newNode = new Node<T>{ newElementData, first };
	first = newNode;
	return first;
}
