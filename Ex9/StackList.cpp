#include "StackList.h"

StackList::StackList() : Stack(), data()
{
}

void StackList::push(int value)
{
	data.addFirst(value);
}

int StackList::pop()
{
	int x = data.firstElement();
	data.removeFirst();
	return x;
}

int StackList::top()
{ 
	return data.firstElement();
}

bool StackList::isEmpty() const
{
	return data.isEmpty();
}

void StackList::clear()
{
	data.clear();
}