#include "Student.h"
#include <iostream>
using namespace std;

const int SIZE = 2;
int main()
{
	//Student s1;

	////char n[10] = { 'D', 'a', 'n', '\0' };

	////s1.setName(n); //char*

	//s1.setName("David Cohen"); //const char*

	//cout << s1.getName() << endl;

	//s1.setGrade(-55); 

	//cout << s1.getGrade() << endl;

	//s1.inputMarks();
	//s1.print();

	Student arr[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		char n[21];
		cout << "Enter Name for student " << i+1 << ": ";
		//cin >> n; //David
		cin.getline(n, 20); //David Cohen
		arr[i].setName(n);

		int g;
		cout << "Enter Grade for student " << i+1 << ": ";
		cin >> g;
		arr[i].setGrade(g);

		arr[i].inputMarks();

		// This clears the newline character so the next getline works!
		cin.ignore(1000, '\n');
	}

	for (int i = 0; i < SIZE; i++)
	{
		arr[i].print();
	}





}