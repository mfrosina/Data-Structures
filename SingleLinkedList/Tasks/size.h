#pragma once

template<typename T>
size_t size(Node<T>* first)
{
	if (first == nullptr)
	{
		return 0;
	}
	size_t count = 0;
	while (first != nullptr)
	{
		count++;
		first = first->next;
	}
	return count;
}
