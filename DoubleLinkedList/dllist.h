#pragma once
#include <stdexcept>

template <typename T>
class DLListIterator;

template <typename T>
class DLList
{
public:
	using value_type = T;
	using iterator = DLListIterator<T>;
private:
	struct Node
	{
		T data;
		Node* prev;
		Node* next;
		
		Node(const T& _data, Node* _prev = nullptr,Node* _next = nullptr)
		{
			data = _data;
			prev = _prev;
			next = _next;
		}
	};
	Node* first;
	Node* last;

	friend class DLListIterator<T>;

	void copy(const Node* other_first)
	{
		/*if (other_first == nullptr)
		{
			return;
		}
		Node* lastCreated = nullptr;
		while (other_first != nullptr)
		{
			Node* newNode = new Node(other_first->data, nullptr, nullptr);
			if (lastCreated == nullptr)
			{
				first = newNode;
			}
			else
			{
				lastCreated->next = newNode;
			}
			lastCreated = newNode;
			other_first = other_first->next;

		}*/ 
		//TO DO
	}
	void clear()
	{
		if (first == nullptr)
		{
			return;
		}
		Node* save = first;
		while (first != last)
		{
			first = first->next;
			delete[]save;
			save = first;
		}
		last = nullptr;
	}
public:
	DLList()
	{
		first = nullptr;
		last = nullptr;
	}
	DLList(const DLList<T>& other)
	{
		copy(other.first);
	}
	DLList<T>& operator=(const DLList<T>& other)
	{
		if (this != &other)
		{
			clear();
			copy(other.first);
		}
		return *this;
	}
	~DLList()
	{
		clear();
	}
	void print()const
	{
		Node* curr = first;
		while (curr != nullptr)
		{
			std::cout << curr->data << " ";
			curr = curr->next;
		}
	}
	DLList<T>& push(const T& newElementData)
	{
		if (first == nullptr)
		{
			first = new Node(newElementData, first, nullptr);
			last = first;
			return *this;
		}
		Node* newNode = new Node(newElementData, nullptr, first);
		first = newNode;
		return *this;
	}
	DLList<T>& push_back(const T& newElementData)
	{
		if (first == nullptr)
		{
			first = new Node(newElementData, first, nullptr);
			last = first;
			return *this;
		}
		Node* newNode = new Node(newElementData, last, nullptr);
		last->next = newNode;
		last = last->next;
		return *this;
	}
	DLList<T>& pop()
	{
		if (first == nullptr)
		{
			throw std::out_of_range("Empty list");
		}
		if (first->next == nullptr)
		{
			delete[]first;
			first = nullptr;
			last = nullptr;
			return *this;
		}
		Node* toDel = first;
		first = first->next;
		delete[]toDel;
		return *this;
	}
	DLList<T>& pop_back()
	{
		if (first == nullptr)
		{
			throw std::out_of_range("Empty list");
		}
		if (first->next == nullptr)
		{
			delete[]first;
			first = nullptr;
			last = nullptr;
			return *this;
		}
		Node* toDel = last;
		last = last->prev;
		last->next = nullptr;
		delete[]toDel;
		return *this;
	}
	DLList<T>& insertAfter(const T& newElementData, size_t pos)
	{
		if (pos == 0)
		{
			push(newElementData);
			return *this;
		}
		Node* curr = first;
		for (size_t i = 1; i < pos; i++)
		{
			if (curr->next == nullptr)
			{
				throw std::out_of_range("Position out of bounds");
			}
			curr = curr->next;
		}
		Node* newNode = new Node(newElementData, nullptr, nullptr);
		newNode->prev = curr;
//		(curr->next)->prev = newNode;
		newNode->next = curr->next;
		curr->next = newNode;
		return *this;
	}
	DLList<T>& deleteAt(size_t pos)
	{
		if (pos == 0)
		{
			pop();
			return *this;
		}
		Node* curr = first;
		for (size_t i = 1; i < pos; i++)
		{
			if (curr->next == nullptr)
			{
				throw std::out_of_range("Pos out of bounds");
			}
			curr = curr->next;
		}
		Node* toDel = curr->next;
		(curr->next)->prev = toDel->prev;
		curr->next = toDel->next;
		curr = toDel->next;
		delete[]toDel;
		return *this;
	}
	size_t size()
	{
		Node* curr = first;
		size_t count = 0;
		while (curr != nullptr)
		{
			count++;
			curr = curr->next;
		}
		return count;
	}
};

