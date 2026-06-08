#include "Shape.h"

/////// Shape /////
Shape::Shape(string n) : name(n)
{
}

void Shape::print()
{
	cout << name << ":\t";
	details();
	cout << "area:\t" << area() << endl;
}


/////// Square /////

Square::Square(int s)
	: Shape("Square"), side(s)
{
}

float Square::area()
{
	return side * side;
}

void Square::details()
{
	cout << side << "\t";
}

///////// Circle ////////////////
Circle::Circle(int r, int x, int y)
	:Shape("Circle")
{
	radius = r; 	center_x = x;	center_y = y;
}

float Circle::area()
{
	return 3.14 * radius * radius;
}

void Circle::details()
{
	cout << radius << "\t(" << center_x
		<< ',' << center_y << ")\t";
}
 
/////////  Triangle //////////////////
Triangle::Triangle(int x, int y, int z)
	: Shape("Triangle")
{
	a = x;	b = y;	c = z;
}

float Triangle::area()
{
	int s = (a + b + c) / 2.0;
	return
		sqrt(s * (s - a) * (s - b) * (s - c));
}

void Triangle::details()
{
	cout << a << '\t' << b
		<< '\t' << c << '\t';
}
