#pragma once
#include "dlnode.h"

template <typename T>
size_t count(DLNode<T>* l, T x)
{
	if (l == nullptr)
	{
		return 0;
	}
	size_t c = 0;
	while (l != nullptr)
	{
		if (l->data == x)
		{
			c++;
		}
		l = l->next;
	}
	return c;
}
