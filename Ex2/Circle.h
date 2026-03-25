#pragma once
#include "Point.h"

class Circle
{
	float radius;
	Point center;
public:
	Circle(); //ctor
	Circle(float r, float x, float y);
	Circle(float r, const Point& other);
	Circle(float r);
	Circle(const Circle& other); //copy ctor

	void setRadius(float r);
	float getRadius() const;
	
	void setCenter(const Point& other);
	Point getCenter() const;

	float area() const;
	float perimeter() const;

	int checkPointInOutOn(const Point& other) const;

};