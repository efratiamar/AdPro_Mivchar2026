#include "Circle.h"

float const PI = 3.14;

Circle::Circle()
	: radius(1), center()
{
	//radius = 1;
	//center.setX(0);
	//center.setY(0);

}

Circle::Circle(float r, float x, float y)
	:radius(r), center(x,y)
{
	//center.setX(x);
	//center.setY(y);
}

Circle::Circle(float r, const Point& other)
	: radius(r), center(other)
{
}

Circle::Circle(float r)
	:radius(r), center()
{
}

Circle::Circle(const Circle& other)
	: radius(other.radius), center(other.center)
{
}

void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::getRadius() const
{
	return radius;
}

void Circle::setCenter(const Point& other)
{
	center = other; //assign op of class Point - shallow copy
	
	//instead of:
	//center.setX(other.getX());
	//center.setY(other.getY());
}

Point Circle::getCenter() const
{
	return center;
}

float Circle::area() const
{
	return PI * radius * radius;
}

float Circle::perimeter() const
{
	return 2 * PI * radius;
}

int Circle::checkPointInOutOn(const Point& other) const
{
	float d = center.distance(other);
	if (d == radius)
		return 0;
	if (d < radius)
		return -1;
	return 1;
}
