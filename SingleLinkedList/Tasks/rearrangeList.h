#pragma once
#include "node.h"
#include "size.h"
#include "push.h"
#include "reverse.h"

template <typename T>
void rearrangeList(Node<T>*& first)
{
	if (first == nullptr)
	{
		return;
	}
	size_t s = size(first);
	Node<T>* curr = first;
	for (size_t i = 0; i < s / 2 - 1; i++)
	{
		curr = curr->next;
	}
	Node<T>* temp = curr->next;
	curr->next = nullptr;
	reverse(temp);
	while (temp != nullptr)
	{
		push(first, temp->data);
		temp = temp->next;
	}

}