#include <iostream>
using namespace std;

class Rational
{
	int mone;
	int mechane;

public:

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


int main()
{
	int x = 7;
	cout << x << " " << 5;

	//char* c = "sdff";
	//cout << c;

	Rational r1;

	cout << r1;

	cout << "The rational is: " << r1 << " dhd " << 5;

	Rational r2;

	cin >> x >> r2 >> x;   // 3/5


}