#pragma once
#include "node.h"
#include "size.h"
#include "push_back.h"
#include <iostream>

template <typename T>
void splitList(Node<T>*& first)
{
	if (first == nullptr)
	{
		return;
	}
	Node<T>* curr = first;
	size_t middle = size(first) / 2;
	for (size_t i = 0; i < middle - 1; i++)
	{
		curr = curr->next;
	}
	Node<T>* second = curr->next;
	curr->next = nullptr;

	print(first);
	std::cout << std::endl;
	print(second);
}
template <typename T>
void splitList(Node<T>*& first)
{
	if (first == nullptr)
	{
		return;
	}
	Node<T>* list1 = nullptr;
	Node<T>* list2 = nullptr;
	Node<T>* temp = nullptr;
	Node<T>* temp2 = nullptr;
	Node<T>* curr = first;
	size_t s = size(curr);
	while (curr != nullptr)
	{
		if (list1 == nullptr)
		{
			
			for (size_t i = 0; i < s / 2; i++)
			{ 
				Node<T>* newNode = new Node<T>{ curr->data,nullptr };
				if (list1 == nullptr)
				{
					list1 = newNode;
				}
				else
				{
					temp->next = newNode;
				}
				temp = newNode;
				curr = curr->next;
			}
		}
		else {
			Node<T>* newNode = new Node<T>{ curr->data,nullptr };
			if (list2 == nullptr)
			{
				list2 = newNode;
			}
			else
			{
				temp2->next = newNode;
			}
			temp2 = newNode;
			curr = curr->next;
		}
	}
	print(list1);
	std::cout << std::endl;
	print(list2);
}
