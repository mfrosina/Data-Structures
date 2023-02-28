#pragma once
#include <exception>

template <typename T>
class ListIterator;

template <typename T>
class LList
{
public:
	using value_type = T;
	using iterator = ListIterator<T>;

private:
	struct Node
	{
		T data;
		Node* next;
	};
	friend class ListIterator<T>;
	Node* first = nullptr;

	void copy(Node* other_first)
	{
		if (other_first == nullptr)
		{
			return;
		}
		Node* lastCreated = nullptr;
		while (other_first != nullptr)
		{
			Node* newNode = new Node;
			newNode->data = other_first->data;
			newNode->next = nullptr;
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
		}
	}
	void clear()
	{
		Node* toSave = first;
		while (first != nullptr)
		{
			toSave = first->next;
			delete[]first;
			first = toSave;
		}
	}
public:
	LList()
	{
		first = nullptr;
	}
	LList(const LList& other)
	{
		copy(other->first);
	}
	LList(int x, int y)
	{
		if (x > y)
		{
			throw std::invalid_argument("X should be less or equal to Y");
		}
		Node* temp = nullptr;
		while (x <= y)
		{
			Node* newNode = new Node;
			newNode->data = x;
			newNode->next = nullptr;
			if (temp == nullptr)
			{
				first = newNode;
			}
			else
			{
				temp->next = newNode;
			}
			temp = newNode;
			x++;
		}
	}
	LList& operator=(const LList& other)
	{
		if (this != &other)
		{
			clear();
			copy(other.first);
		}
		return *this;
	}
	LList& push(const T& newElement)
	{
		//With initialization
		Node* newNode = new Node;
		newNode->data = newElement;
		newNode->next = first;
		first = newNode;
		return *this;

		//Without initialization
		//first = new Node(newElement, first);

	}
	void pop()
	{
		if (first == nullptr)
		{
			throw std::exception("Empty list");
		}
		Node* toSave = first;
		first = first->next;
		delete[] toSave;
	}
	void print()
	{
		Node* curr = first;
		while (curr != nullptr)
		{
			std::cout << curr->data << std::endl;
			curr = curr->next;
		}
	}
	void insertAt(size_t pos, const T& newElementData)
	{
		if (pos == 1)
		{
			push(newElementData);
			return;
		}
		Node* curr = first;
		for (size_t i = 1; i < pos - 1; i++)
		{
			if (curr->next == nullptr)
			{
				throw std::out_of_range("Invalid position");
			}
			curr = curr->next;
		}

		Node* newNode = new Node;
		newNode->data = newElementData;
		newNode->next = curr->next;
		curr->next = newNode;
	}
	void deleteAt(size_t pos)
	{
		if (pos == 1)
		{
			pop();
			return;
		}
		Node* curr = first;
		for (size_t i = 1; i < pos - 1; i++)
		{
			if (curr == nullptr)
			{
				throw std::out_of_range("Invalid position");
			}
			curr = curr->next;
		}
		Node* toDel = curr->next;
		curr->next = toDel->next;

		delete[]toDel;
	}

	size_t size()
	{
		size_t count = 0;
		Node* curr = first;
		while (curr != nullptr)
		{
			count++;
			curr = curr->next;
		}
		return count;
	}
	int count(int x)
	{
		if (first == nullptr)
		{
			return 0;
		}
		int counter = 0;
		Node* curr = first;
		while (curr != nullptr)
		{
			if (curr->data == x)
			{
				counter++;
			}
			curr = curr->next;
		}
		return counter;
	}
	void push_back(const T& newElementData)
	{
		Node* curr = first;
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		Node* newNode = new Node;
		newNode->data = newElementData;
		newNode->next = nullptr;
		curr->next = newNode;
	}
	T& operator[](size_t ind)
	{
		Node* curr = first;
		for (size_t i = 1; i < ind; i++)
		{
			if (curr->next == nullptr)
			{
				throw std::out_of_range("Invalid index");
			}
			curr = curr->next;
		}
		return curr->data;
	}
	LList& operator+(const T& newElementData)
	{
		Node* result = first;
		while (result->next != nullptr)
		{
			result = result->next;
		}
		Node* newNode = new Node;
		newNode->data = newElementData;
		newNode->next = nullptr;
		result->next = newNode;
		return result;

	}
	void operator+=(const T& newElementData)
	{
		Node* result = first;
		while (result->next != nullptr)
		{
			result = result->next;
		}
		Node* newNode = new Node;
		newNode->data = newElementData;
		newNode->next = nullptr;
		result->next = newNode;
	}
	T get_nth(size_t n)const
	{
		Node* curr = first;
		for (size_t i = 1; i < n; i++)
		{
			if (curr->next == nullptr)
			{
				throw std::out_of_range("Invalid index");
			}
			curr = curr->next;
		}
		return curr->data;
	}
	void append(LList<T>* newList)
	{
		Node* curr = first;
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		Node* curr2 = newList->first;
		while (curr2 != nullptr)
		{
			Node* temp = new Node;
			temp->data = curr2->data;
			temp->next = nullptr;
			curr->next = temp;
			curr = temp;
			curr2 = curr2->next;
		}
	}
	void reverse()
	{
		Node* temp = nullptr;
		Node* prev = nullptr;
		Node* curr = first;
		while (curr != nullptr)
		{
			temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		first = prev;
	}
	ListIterator<T> begin()const
	{
		return ListIterator<T>(first);
	}
	ListIterator<T> end()const
	{
		return ListIterator<T>(nullptr);
	}
	~LList()
		{
			clear();
		}
};

template <typename T>
class ListIterator
{
private:
	typename LList<T>::Node* current;

public:
	ListIterator(typename LList<T>::Node* first)
	{
		current = first;
	}
	ListIterator& operator++()
	{
		if (current == nullptr)
		{
			throw std::out_of_range("Iterator out of bounds");
		}
		current = current->next;

		return *this;
	}
	T operator*()
	{
		if (current == nullptr)
		{
			throw std::out_of_range("Iterator out of bounds");
		}
		return current->data;
	}
	bool operator!=(const ListIterator<T>& other)const
	{
		return current != other.current;
	}
	bool operator==(const ListIterator<T>& other)const
	{
		return current == other.current;
	}

};

