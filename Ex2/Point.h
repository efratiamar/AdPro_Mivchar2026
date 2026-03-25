#pragma once

class Point
{
	float x = 0;
	float y = 0;
public:
	Point(); //ctor
	Point(float _x, float _y); //param ctor
	Point(const Point& other); //copy ctor
	void setX(float _x);
	float getX() const;

	void setY(float _y);
	float getY() const;

	float distance(const Point& other) const;

};
