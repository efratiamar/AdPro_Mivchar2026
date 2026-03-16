#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Student.h"
#include <iostream>
using namespace std;


void Student::setName(const char* n)
{
	strcpy(name, n);
}


char* Student::getName()
{
	return name;
}

void Student::setGrade(float g)
{
	if (g >= 1 && g <= 12)
		grade = g;
	else
		grade = -1;
}

float Student::getGrade()
{
	return grade;
}

void Student::inputMarks()
{
	cout << "Enter " << CNT << " marks: " << endl;
	for (int i = 0; i < CNT; i++)
	{
		cin >> marks[i];
		if (marks[i] < 0 || marks[i] > 100)
			marks[i] = 0;
	}
}

void  Student::print()
{
	cout << "Name: " << name << " Grade: " << grade
		<< " Avg: " << computeAvg() << endl;
}

float Student::computeAvg()
{
	float avg = 0;
	for (int i = 0; i < CNT; i++)
	{
		avg += marks[i];
	}
	return avg / CNT;
}