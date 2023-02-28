#pragma once
#include "node.h"

template <typename T>
Node<T>* intersectionPoint(Node<T>* first, Node<T>* other)
{
	while (other != nullptr)
	{
		Node<T>* temp = first;
		while (temp != nullptr)
		{
			if (first == temp)
			{
				return first;
			}
			temp = temp->next;
		}
		other = other->next;
	}
	return nullptr;
}