#include "MyString.h"
#include <iostream>
#include <string>
using namespace std;

string crypto(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		char ch = str.at(i);
		if (ch >= 'a' && ch <= 'z')
			str[i] = 'z' - (ch - 'a');
	}
	return str;
}

string reverseWords(string str)
{
	string str2;
	int wordBegin = 0;
	int wordEnd;
	while ((wordEnd = str.find(" ", wordBegin)) != -1)
	{
		string word;
		for (int i = wordEnd; i >= wordBegin; i--)
			word.push_back(str[i]);
		str2 += word;
		wordBegin = wordEnd + 1;
	}
	string word = " ";
	for (int i = str.length() - 1; i >= wordBegin; i--)
		word.push_back(str[i]);
	str2 += word;

	return str2;

}


int main()
{
	//char* a "sfdf";
	MyString ms1("efarafbfds fdsg7q64q3@@"); //ctor
	MyString ms2; //ctor
	
	MyString ms3(ms1); //copy ctor
	MyString ms4 = ms3; //copy ctor

	ms3 = ms1 = ms4;

	if (ms3 == ms2)
	{

	}

	ms3 = ms1 + ms2;

	ms3 = ms1 * 4;

	//ms3 = 4 * ms1;


}