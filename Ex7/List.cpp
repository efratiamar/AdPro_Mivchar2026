#include <iostream>
using namespace std;
#include "List.h"

List::Link::Link(int k, Link* n) : key(k), next(n)
{}

//List ls1;
List::List() : head(nullptr)
{
}

//List ls2(ls1);
List::List(const List& other)
{
	if (other.isEmpty())
	{
		head = nullptr;
		return;
	}
	
	//othre is not empty
	Link* p = other.head;
	head  = new Link(p->key, nullptr);
	Link* newL = head;

	while (p->next)
	{
		p = p->next;
		newL->next = new Link(p->key,nullptr );
		newL = newL->next;
	}

}

List::~List()
{
	clear();
}

bool List::isEmpty() const
{
	return head == nullptr;
}

void List::add(int value)
{
	head = new Link(value, head);
}

void List::removeFirst()
{
	if (isEmpty())
		throw "Error! cannot remove from an empty list!";

	Link* tmp = head;
	head = head->next;
	delete tmp;
}

int List::firstElement() const
{
	if (isEmpty())
		throw "Error! cannot return value from an empty list!";

	return head->key;
}

bool List::search(const int& value) const
{
	Link* p = head;
	while (p)
	{
		if (p->key == value)
			return true;
		p = p->next;
	}
	return false;
}

void List::clear()
{
	while (head)
	{
		removeFirst();
	}

	//Link* p = head;

	//while (p)
	//{
	//	Link* tmp = p;
	//	p = p->next;
	//	delete tmp;
	//}
}

ostream& operator<<(ostream& os, const List& other)
{
	List::Link* p = other.head;
	while (p)
	{
		os << p->key << " ";
		p = p->next;
	}
	os << endl;
	return os;
}


