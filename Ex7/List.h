#pragma once

class List
{
	class Link
	{
	public:
		int key;
		Link* next;
		
		Link(int k=0, Link* n=nullptr);
	};

	Link* head;
public:
	List(); //ctor
	List(const List& other); //copy ctor
	~List();
	bool isEmpty() const;
	void add(int value);
	void removeFirst();
	int firstElement() const;
	bool search(const int& value) const;

	void clear();
	friend ostream& operator<<(ostream& os, const List& other);

};
