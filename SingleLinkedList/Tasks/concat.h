#pragma once
#include "node.h"

template <typename T>
Node<T>* concat(Node<T>* first, Node<T>* other_first)
{
	if (first == nullptr && other_first == nullptr)
	{
		return nullptr;
	}
	if (first == nullptr && other_first != nullptr)
	{
		/*Node<T>* concated = nullptr;
		Node<T>* lc = nullptr;
		while (other_first != nullptr)
		{
			if (concated == nullptr)
			{
				concated = other_first;
			}
			else {
				lc->next = other_first;
			}
			lc = other_first;
			other_first = other_first->next;
		}
		return concated;*/
		return other_first;
	}
	if (first != nullptr && other_first == nullptr)
	{
		return first;
	}
	Node<T>* concated = nullptr;
	while (first != nullptr)
	{
		Node<T>* lc = nullptr;
		while (first != nullptr)
		{
			Node<T>* newNode = new Node<T>{ first->data,nullptr };
			if (concated == nullptr)
			{
				concated = newNode;
			}
			else {
				lc->next = newNode;
			}
			lc = newNode;
			first = first->next;
		}
	}
	Node<T>* save = concated;
	Node<T>* lc = nullptr;
	while (other_first != nullptr)
	{
		Node<T>* newNode = new Node<T>{ other_first->data,nullptr };
		if (lc == nullptr)
		{
			(save->next)->next = newNode;
		}
		else
		{
			lc->next = newNode;
		}
		lc = newNode;
		other_first = other_first->next;
	}
	return concated;
}
