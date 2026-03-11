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


}

