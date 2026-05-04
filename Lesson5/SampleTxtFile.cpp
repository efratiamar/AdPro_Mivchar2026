#include <iostream >
#include <fstream>
using namespace std;

//text file samples

int txt1()
{
	//option 1
	ofstream myFile;
	myFile.open("grades.txt");

	//option 2
	//ofstream myFile("grades.txt");

	//option 3
	//fstream myFile;
	//myFile.open("grades.txt", ios::out);

	if (!myFile)
	{
		cout << "File could not be opened.\n";
		return -1;
	}

	int tz;
	float grade;
	for (int i = 0; i < 3; i++)
	{
		cout << "enter a tz and grade";
		cin >> tz >> grade;
		myFile << tz << '\t' << grade << endl;
	}
	myFile.close();
	return 0;
}

int txt2()
{
	ifstream file;
	file.open("grades.txt");
	if (!file) {
		cout << "File could not be opened.\n";
		return -1;
	}

	int tz; float grade; float sum = 0; int cnt = 0;

	file >> tz >> grade; //input from file	
	while (!file.eof())
	{
		sum += grade; cnt++;
		cout << tz << '\t' << grade << endl;
		file >> tz >> grade;
	}

	cout << "avg= " << sum / cnt;

	file.close();
	return 0;

}

int txt3()
{
	ifstream file;
	file.open("grades.txt");
	if (!file) {
		cout << "File could not be opened.\n";
		return -1;
	}

	int tz; float grade; float sum = 0; int cnt = 0;

	while (file >> tz >> grade) //input from file
	{
		sum += grade; cnt++;
		cout << tz << '\t' << grade << endl;
	}

	if (cnt)
		cout << "avg= " << sum / cnt;

	file.close();
	return 0;

}
