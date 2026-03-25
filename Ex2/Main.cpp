#include <iostream>
using namespace std;

#include "Point.h"
#include "Circle.h"


int main()
{
    Point point;
    Circle A;
    Circle B(5);
    Circle C(3, point);
    Circle D(4, 2, 2);
    Circle E(D);


    Point p2;
    p2.setX(3);
    p2.setY(4);
    cout << "testing point" << endl;
    cout << "(" << p2.getX() << "," << p2.getY() << ")" << endl;

    A.setRadius(2);
    A.setCenter(p2);
    cout << A.area() << endl;
    cout << A.perimeter() << endl;

    int count = 0;


    char lParen, comma, rParen;	/*	(x,y)	*/
    int x, y;
    int inA = 0, outA = 0, onA = 0;
    cout << "enter points until(0, 0) :\n";
    Point p; //(0,0)
    cin >> lParen >> x >> comma >> y >> rParen;
    while (x || y)
    {
        p.setX(x);
        p.setY(y);
        if (A.checkPointInOutOn(p) < 0)
            inA++;
        if (A.checkPointInOutOn(p) > 0)
            outA++;
        if (A.checkPointInOutOn(p) == 0)
            onA++;
        cin >> lParen >> x >> comma >> y >> rParen;
    }
    cout << "num of points in/out/on circle :" << endl;
    cout << "A:" << inA << '\t' <<outA << '\t' << onA << '\t';


    cout << count << endl;
    return 0;
}


//int main()
//{
//	Point p1; //0,0 => Point()
//
//	p1.setX(6);
//	p1.setY(-8);
//
//	cout << "(" << p1.getX() << "," << p1.getY() << ")" << endl; //(6,-8)
//
//	Point p2(p1);
//
//	Point p3;
//	p3.setX(-86);
//	p3.setY(9);
//
//	cout << p3.distance(p2) << endl;
//
//
//	Circle c1; //1, (0,0)
//
//	Circle c2(3.4, 6, -9.5); //3.4, (6, -9.5)
//
//	Circle c3(4, p3); //4, (-86, 9)
//
//	cout << c3.checkPointInOutOn(p2) << endl;
//}