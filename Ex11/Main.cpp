#include "Shape.h"
#include <list>

int main()
{
	srand(time(0));

	list<Shape*> lst;
	for (int i = 0; i < 10; i++)
	{
		int n = rand() % 3;
		Shape* ps;
		switch (n)
		{
		//case 0: lst.push_back(new Square(rand() % 10 + 1)); break;
		//case 1: lst.push_back(new Circle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1)); break;
		//case 2: lst.push_back(new Triangle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1)); break;

		case 0: ps = new Square(rand() % 10 + 1); break;
		case 1: ps = new Circle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1); break;
		case 2: ps = new Triangle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1); break;
		}

		lst.push_back(ps);
	}

	//list<Shape*>::iterator it; //Shape* p; 
	//it = lst.begin();
	//cout << *it; //address of the first shape
	//it++;
	//cout << *it; //address of the second shape

	for (list<Shape*>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		(*it)->print();
	}


	for (list<Shape*>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		if (*it)
			delete* it;
	}
	//
}