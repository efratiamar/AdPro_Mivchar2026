#include "TailList.h"

TailList::TailList() : List(), tail(nullptr)
{
}

TailList::~TailList()
{
	tail = nullptr;
}

void TailList::addFirst(int value)
{
	if (isEmpty())
	{
		List::addFirst(value);
		tail = head;
		return;
	}

	List::addFirst(value);
}

void TailList::removeFirst()
{ 
	List::removeFirst();
	if (isEmpty())
	{
		tail = nullptr;
	}
}

void TailList::clear()
{
	List::clear();
	tail = nullptr;
}

void TailList::addLast(int value)
{
	if (isEmpty())
	{
		addFirst(value);
		return;
	}

	Link* newL = new Link(value, nullptr);
	tail->next = newL;
	tail = newL;
}
