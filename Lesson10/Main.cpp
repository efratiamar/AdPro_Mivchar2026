#include <iostream>
using namespace std;

#include <vector>
#include <list>
#include <queue>
int main()
{ 
	vector<int> v1; //
	vector<char> v2(5); //0 0 0 0 0
	vector<char> v3(5, 'x'); //'x', 'x','x','x','x'

	cout << v1.size();
	cout<< v1.capacity();
	v1.push_back(6); //6
	v1.push_back(7); //6 7 
	
	if (v1.empty())
	{

	}
	cout << v1.at(1); //7
	cout << v1[1]; //7

	cout << v1.front(); //6

	v1.pop_back();
	v1.push_back(67); 
	v1.push_back(71); 
	v1.push_back(77); 
	v1.push_back(72); 
	v1.push_back(16); 
	v1.push_back(97);

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i];
	}

	vector<int>::iterator it1; //int* p;
	it1 = v1.begin();
	cout << *it1; //2
	it1++;
	cout << *it1; //3

	for (it1 = v1.begin(); it1 != v1.end(); it1++)
	{
		cout << *it1;

	}

	v1.erase()



	vector<int> v22;
	v22.push_back(5);
	//...
	for (it1 = v22.begin(); it1 != v22.end(); it1++)
	{
		cout << *it1;

	}




	list<char> ls1;

	ls1.push_front('a'); //a
	ls1.push_front('b'); //b a
	ls1.push_back('c'); //b a c
	cout << ls1.size();

	ls1.pop_back();
	ls1.pop_front();
	
	ls1.reverse();
	
	list<char>::iterator it2; //char* p;

	it2 = ls1.begin();
	cout << *it2;
	it2++;
	cout << *it2;

	for (it2 = ls1.begin(); it2 != ls1.end(); it2++)
	{
		cout << *it2;
	}
	

	queue<int> q;
	//queue<int>::iterator it; //error!!
	q.push(4);
	cout << q.front();
	cout << q.back();
	q.pop();
	if (q.empty())
	{

	}


}
