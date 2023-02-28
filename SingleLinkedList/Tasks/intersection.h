#pragma once
#include "node.h"

template <typename T>
Node<T>* intersection(Node<T>* first, Node<T>* other)
{
	if (first == nullptr || other == nullptr)
	{
		return nullptr;
	}
	Node<T>* intersected = nullptr;
	Node<T>* temp = nullptr;
	while (first != nullptr)
	{
		Node<T>* saveOther = other;
		while (saveOther != nullptr)
		{
			if (first->data == saveOther->data)
			{
				Node<T>* newNode = new Node<T>{ first->data,nullptr };
				if (intersected == nullptr)
				{
					intersected = newNode;
				}
				else
				{
					temp->next = newNode;
				}
				temp = newNode;
			}
			saveOther = saveOther->next;

		}
		first = first->next;
	}
	return intersected;
}
