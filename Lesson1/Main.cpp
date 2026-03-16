#include <iostream>
using namespace std;

#include "Rect.h"

int main()
{
    Rect rect1;
    //rect1.length = -4; //compilation error. Length is private!!!

    rect1.setLength(4);
    cout << rect1.getLength();

    Rect rect2;

    rect2.setLength(7);
    int x = rect2.getLength();

    Rect r2;
    r2 = rect1;

    int x = 7;
    x = 6;
    x = 8;

    x++;
    x = x + 1 




}

