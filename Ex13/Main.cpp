#include <iostream>
#include <list>
using namespace std;

void my_for_each_int(list<int>::iterator itB, list<int>::iterator itE,	void (*func)(int) )
{
	for (list<int>::iterator it = itB; it != itE; it++)
	{
		func(*it); // (*func)(*it);
	}

}

template <class T>
void my_for_each(class list<T>::iterator itB, class list<T>::iterator itE, void (*func)(T))
{
	for (list<T>::iterator it = itB; it != itE; it++)
	{
		func(*it); // (*func)(*it);
	}

}

template <class T>
bool my_all_of(class list<T>::iterator itB, class list<T>::iterator itE, bool (*func)(T))
{
	for (list<T>::iterator it = itB; it != itE; it++)
	{
		if (!func(*it))
			return false;
	}

	return true;

}

int main()
{
	list<int> ls;
	ls.push_back(22);
	//...
	my_for_each_int(ls.begin(), ls.end(), [](int x) { if (x % 2 == 0) cout << x; });

	my_for_each<int>(ls.begin(), ls.end(), [](int x) { if (x % 2 == 0) cout << x; });

	if (my_all_of<int>(ls.begin(), ls.end(), [](int x) { return x > 10; }))
		cout << "all is greater than 10" << endl;
	else
		cout << " not all of is greater than 10" << endl;




}