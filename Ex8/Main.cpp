#include "TailList.h"

int main()
{
	try
	{
		TailList tl1;
		tl1.addFirst(4);
		tl1.addLast(6);
		tl1.addFirst(2);
		tl1.addLast(1);
		tl1.removeFirst(); 
		cout << tl1.firstElement() << endl; // 4
		cout << tl1;//4 6 1
		tl1.clear();
		cout << tl1;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	catch (...)
	{
		cout << "Unknown error!" << endl;
	}

	cout << "Bye Bye!" << endl;

}