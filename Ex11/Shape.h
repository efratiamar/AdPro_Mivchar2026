#pragma once
#include<iostream>
using namespace std;

class Shape
{
protected:
	string name;
public:
	Shape(string n);
	virtual float area() = 0;
	virtual void details() = 0;
	void print();
};

class Square : public Shape
{
private:
	int side;
public:
	Square(int s);
	float area();
	void details();
};

class Circle :public Shape
{
private:
	int radius;
	int center_x, center_y;
public:
	Circle(int r, int x, int y);
	float area();
	void details();
};

class Triangle :public Shape
{
private:
	int a, b, c;
public:
	Triangle(int a, int b, int c);
	float area();
	void details();
};
