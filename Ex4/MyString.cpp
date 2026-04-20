#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "MyString.h"
#include <cstring>



MyString::MyString(const char* s) //ctor
{
	if (s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	else
		str = nullptr;
}

MyString::MyString(const MyString& other) //copy ctor
{
	if (other.str)
	{
		str = new char[strlen(other.str) + 1];
		strcpy(str, other.str);
	}
	else
		str = nullptr;

}

MyString& MyString::operator=(const MyString& other)
{
	if (str)
		delete[] str;

	if (other.str)
	{
		str = new char[strlen(other.str) + 1]; //
		strcpy(str, other.str);
	}
	else
		str = nullptr;
	
	return *this;

}

MyString::~MyString()
{
	if (str)
		delete[] str;

}



char* MyString::getString() const
{
	return str;
}

int MyString::length() const
{
	if (!str)
		return strlen(str);
	else
		return 0;
}

void MyString::print() const
{
	if (!str)
		cout << str;
}

bool MyString::operator==(const MyString& other) const
{
	return (strcmp(str, other.str) == 0);

}

bool MyString::operator!=(const MyString& other) const
{
	//return (strcmp(str, other.str) != 0);
	return !(*this == other);
}

MyString MyString::operator+(const MyString& other) const
{
	MyString tmp;
	tmp.str = new char[strlen(str) + strlen(other.str) + 1];
	strcpy(tmp.str, str); //"abc"
	strcat(tmp.str, other.str); //"abcdef"
	return tmp;
}

MyString MyString::operator*(int n) const
{
	MyString tmp;
	tmp.str = new char[strlen(str) * n + 1];
	tmp.str = '\0';
	for (int i = 0; i < n; i++)
	{
		strcat(tmp.str, str);
	}

	return tmp;
}

