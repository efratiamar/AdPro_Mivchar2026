#include "Point.h"
#include "math.h"

Point::Point()
	: x(0), y(0)
{
	//x = 0;
	//y = 0;
}

Point::Point(float _x, float _y)
	: x(_x), y(_y)
{
}

Point::Point(const Point& other)
	:x (other.x), y (other.y)
{
	//x = other.x;
	//y = other.y;
}

void Point::setX(float _x)
{
	x = _x;
}

float Point::getX() const
{
	return x;
}

void Point::setY(float _y)
{
	y = _y;
}

float Point::getY() const
{
	return y;
}

float Point::distance(const Point& other) const
{
	float dx = x - other.x;
	float dy = y - other.y;
	return sqrt(dx * dx + dy * dy);
}
