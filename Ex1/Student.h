#pragma once

int const CNT = 10;
class Student
{
//private:
	char name[21];
	int grade;
	float marks[CNT];

	float computeAvg();

public:
	void setName(const char* n);
	char* getName();
	void setGrade(float g);
	float getGrade();

	void inputMarks(); //loop cin

	void print();



};
