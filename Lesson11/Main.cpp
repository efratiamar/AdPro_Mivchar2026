#include <iostream>
using namespace std;

int add(int a, int b) { return (a + b); }
int sub(int a, int b) { return (a - b); }
int mult(int a, int b) { return (a * b); }

int calculator(int x, int y, int (*func) (int, int))
{
	int g;
	g = (*func)(x, y); //<==> g = func(x,y);
	return g;
}


int main()
{
	int (*my_func) (int, int);  //define a pointer to func of type int (int, int)

	my_func = sub;
	int x = sub(22, 23); //x = -1
	int y = my_func(22, 23); //y = -1
	int z = (*my_func)(22, 23); //z = -1

	my_func = add;
	int r = my_func(4, 5); //r = 9
	int s = (*my_func)(4, 5); //s = 9

	int x, y;
	char op;
	cout << "enter an expression\n";
	cin >> x >> op >> y; // 4+6
	int (*func) (int, int) = nullptr;
	switch (op)
	{
	case '+': func = add; break;
	case '-': func = sub; break;
	case '*': func = mult; break;
	}
	cout << calculator(x, y, func) << endl;
}

