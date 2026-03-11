#include <iostream>
using namespace std; 

#include "Rect.h"

void Rect::setLength(int l)
{
	(l < 0) ? length = 5 : length = l;
};

int Rect::getLength()
{
	return length;
};

void Rect::setWidth(int l) { (l < 0) ? width = 5 : width = l; };

int Rect::getWidth()
{
	return width;
};

void Rect::printArea() { cout << "Area: " << length * width << endl; };