#include<iostream>
using namespace std;

class Rect
{
	int width;
	int length;
public:
	Rect() {};
	Rect(int wid, int len) : width(wid), length(len) {};

	bool isEq(const Rect& other) const
	{
		return (width == other.width && length == other.length);
	}

	bool operator==(const Rect& other) const
	{
		return (width == other.width && length == other.length);
	}

	bool operator!=(const Rect& other) const
	{
		//return (width != other.width || length != other.length);
		return !(*this == other);
	}

	Rect operator+(const Rect& other) const
	{
		Rect r(width + other.width, length + other.length);

		return r;
	}

	Rect& operator+=(const Rect& other)
	{
		width += other.width;
		length += other.length;
		return *this;
	}
};

int main()
{
	int a = 4, b = 8, c = 9;
	a = b + c;

	a += 4;

	a += b += c += 4;

	Rect r1, r2, r3;


	Rect r5;
	Rect r6 = r5;

	r5 = r6;

	r1 = r3 = r2 = r3;

	if (r1.isEq(r3))
	{

	}

	if (r3 == r2)
	{

	}

	if (r1.operator==(r2))
	{

	}


	r1 = r2 + r3 + r2;

	r1 = r2 = r3;

	//..
	r1 = r2 += r3; //compilation error

	r2 += r3;
}
