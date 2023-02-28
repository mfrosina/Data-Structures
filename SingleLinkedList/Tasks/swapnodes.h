#pragma once
#include "node.h"

template <typename T>
Node<T>* swapNodes(Node<T>*& first, T x, T y)
{
	if (first == nullptr)
	{
		return nullptr;
	}
	if (x == y)
	{
		return first;
	}
	Node<T>* curr = first;
	bool flag1 = false, flag2 = false;
	while (curr != nullptr)
	{
		if (curr->data == x)
		{
			flag1 = true;
		}
		if (curr->data == y)
		{
			flag2 = true;
		}
		curr = curr->next;
	}
	if (!flag1 || !flag2)
	{
		throw "X or Y not present in the list";
	}
	Node<T>* prevX = nullptr; 
	Node<T>* currX = first;
	while (currX && currX->data != x)
	{
		prevX = currX;
		currX = currX->next;
	}

	Node<T>* prevY = nullptr;
	Node<T>* currY = first;
	while (currY && currY->data != y)
	{
		prevY = currY;
		currY = currY->next;
	}
	//if x is not head of the list
	if (prevX != nullptr)
	{
		prevX->next = currY;
	}
	else
	{
		first = currY;
	}
	//if y is not head of the list
	if (prevY != nullptr)
	{
		prevY->next = currX;
	}
	else
	{
		first = currX;
	}
	Node<T>* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
	return first;
}
