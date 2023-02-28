#pragma once
#include "node.h"

template <typename T>
bool isEven(T x)
{
	if (x % 2 == 0)
	{
		return true;
	}
	return false;
}

template <typename T>
Node<T>* segregate(Node<T>*& first)
{
	if (first == nullptr)
	{
		return nullptr;
	}
	Node<T>* curr = first;
	bool flag = false;
	while (curr != nullptr)
	{
		if (!isEven(curr->data))
		{
			flag = true;
			break;
		}
		curr = curr->next;
	}
	if (!flag)
	{
		return first;
	}
	curr = first;
	Node<T>* result = nullptr;
	Node<T>* temp = nullptr;
	while (curr != nullptr)
	{
		if (isEven(curr->data))
		{
			Node<T>* newNode = new Node<T>{ curr->data,nullptr };
			if (result == nullptr)
			{
				result = newNode;
			}
			else
			{
				temp->next = newNode;
			}
			temp = newNode;
		}
		curr = curr->next;
	}
	curr = first;
	while (curr != nullptr)
	{
		if (!isEven(curr->data))
		{
			Node<T>* newNode = new Node<T>{ curr->data,nullptr };
			if (result == nullptr)
			{
				result = newNode;
			}
			else
			{
				temp->next = newNode;
			}
			temp = newNode;
		}
		curr = curr->next;
	}
	first = result;
	return first;
}
