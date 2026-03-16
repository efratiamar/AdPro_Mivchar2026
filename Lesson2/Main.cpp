#include <iostream>
using namespace std;


class Rational
{
private:
    int numerator = 1;
    int denominator = 1;
public:

    Rational(int n, int d)
        : numerator(n), denominator(d)
    {
        numerator = 6;
        denominator = 7;
    }

    void print() const
    {
        cout << numerator << '/' << denominator << '\n';
    }
};


//Rect.h
class Rect
{
    int length;
    int width;
public:
    //Rect(int a);   //ctor1
    Rect(int a=6, int b=9);   //ctor2

    void printArea()
    {
        cout << length * width << endl;
    };
};

////Rect.cpp
//Rect::Rect() 
//    : width(5), length(5)
//{
//    //width = 5;
//    //length = 5;
//}

Rect::Rect(int a, int b) 
    : width(a), length(b)
{
    //width = a;
    //length = b;
}

int main()
{
    Rect recta(3, 4);
    Rect rectc(5);
    Rect rectb;
    cout << "Rect a area : ";
    recta.printArea();
    cout << "Rect b area : ";
    rectb.printArea();

    rectb = recta;



    Rect* pR;
    pR = new Rect;
    pR->printArea();

    Rect* pR2;
    pR2 = new Rect(3,6);
    pR2->printArea();

    


}

