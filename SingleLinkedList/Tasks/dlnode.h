#pragma once

template <typename T>
struct DLNode
{
	T data;
	DLNode<T>* prev;
	DLNode<T>* next;
};

template <typename T>
DLNode<T>* pushDL(DLNode<T>*& first,DLNode<T>*& last,const T& newElementData)
{
	if (first == nullptr)
	{
		first = new DLNode<T>{ newElementData, first,nullptr };
		last = first;
		return first;
	}
	DLNode<T>* newNode = new DLNode<T>{ newElementData,nullptr,first };
	first = newNode;
	return first;
}

