// SmartPointer.h 
#include<iostream>
using namespace std;

class SmartPointer
{
private:
    int* ptr;
public:
    SmartPointer(int* p = nullptr);
    ~SmartPointer();
};

// SmartPointer.cpp
SmartPointer::SmartPointer(int* p) :ptr(p)
{
    cout << "assignment and default ctor\n";
}
SmartPointer::~SmartPointer()
{
    cout << "dtor" << endl;
    if (ptr)
        delete[] ptr;
}

// main.cpp
int main()
{
    srand(time(nullptr));
    int num1, num2;
    num1 = rand() % 100;
    num2 = rand() % 10;
    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl;
    
    SmartPointer p(new int(num1));
    
    if (num2 % 2)
        return 1;
    
    cout << num1 << endl;
    return 0;
}
