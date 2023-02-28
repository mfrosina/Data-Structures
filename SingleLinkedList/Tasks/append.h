#pragma once
#include "node.h"

template<typename T>
Node<T>* append(Node<T>*& first, Node<T>* toAppend)
{
	if (toAppend == nullptr)
	{
		return first;
	}
	if (first == nullptr)
	{
		Node<T>* lc = nullptr;
		while (toAppend != nullptr)
		{
			Node<T>* newNode = new Node<T>{ toAppend->data,nullptr };
			if (first == nullptr)
			{
				first = newNode;
			}
			else
			{
				lc->next = newNode;
			}
			lc = newNode;

			toAppend = toAppend->next;
		}
		return first;
	}
	Node<T>* save = first;
	while (save->next != nullptr)
	{
		save = save->next;
	}
	while (toAppend != nullptr)
	{
		Node<T>* newNode = new Node<T>{ toAppend->data,nullptr };
		save->next = newNode;
		save = newNode;
		
		toAppend = toAppend->next;
	}
	return first;
}
