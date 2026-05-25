#include <iostream>
#include<string>
using namespace std;

#include "List.h"

int main()
{
	try
	{

		List ls1;
		ls1.add(5);
		for (int i = 0; i < 4; i++)
		{
			ls1.add(i);
		}

		cout << ls1.firstElement() << endl; //4
		cout << ls1; //3 2 1 0 5

		ls1.removeFirst();
		ls1.removeFirst();
		cout << ls1; //1 0 5
		cout << ls1.search(5) << endl; //1


		List ls2(ls1);
		cout << ls2;
		ls2.clear();
		cout << ls2;
		cout << ls2.search(7) << endl; //0
		cout << ls2.firstElement();

	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	catch (...)
	{
		cout << "Unknown erro!" << endl;
	}

	cout << "Bye Bye!" << endl;
}