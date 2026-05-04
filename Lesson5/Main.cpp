#include <iostream>
using namespace std;

int txt1();
int txt2();
int txt3();


class Rational
{
	int mone;
	int mechane;

public:
	Rational(int mo, int me) 
		: mone(mo), mechane(me) {};
	friend ostream& operator<<(ostream& os, const Rational& other);
	friend istream& operator>>(istream& is, Rational& other);
};

ostream& operator<<(ostream& os, const Rational& other)
{
	os  << other.mone << "/" << other.mechane;
	return os;
}

istream& operator>>(istream& is, Rational& other)
{
	char slash;

	is >> other.mone >> slash >> other.mechane;

	return is;

}


void iostreamSamples()
{
	int x = 7;
	cout << x << " " << 5;

	//char* c = "sdff";
	//cout << c;

	Rational r1 (3,4);

	cout << r1;

	cout << "The rational is: " << r1 << " dhd " << 5;

	Rational r2 (5,7);

	cin >> x >> r2 >> x;   // 3/5
}

int main()
{

	//iostreamSamples();

	//text samples
	//txt1();
	txt2();
	//txt3();

}