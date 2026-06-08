#include <iostream>
#include <string>
#include <stack>
using namespace std;

string infixToPostfix(string infix)
{
	string postfix;
	stack<char> st;
	for (int i = 0; i < infix.length(); i++)
	{
		char ch = infix[i];
		switch (ch)
		{
		case '/':
		case '*':
		case '(':	st.push(ch);
			break;
		case ')':	while (st.top() != '(')
		{
			postfix += st.top(); st.pop();
		}
				st.pop(); // '('
				break;
		case '+':
		case '-':	while (!st.empty() && (st.top() == '*' || st.top() == '/'))
		{
			postfix += st.top(); st.pop();
		}
				st.push(ch);
				break;
		default:
			do
			{
				postfix += ch;
				ch = infix[++i];
			} while (ch >= '0' && ch <= '9');
			i--;
			postfix += ' ';
		}
	}
	while (!st.empty())
	{
		postfix += st.top();
		st.pop();
	}
	return postfix;
}

float calcPostfix(string postfix) //5 3 + 20 10 / 8 6 - +*
{
	stack<float> st;

	for (int i = 0; i < postfix.length(); i++)
	{
		char curChar = postfix[i];
		if (curChar >= '0' && curChar >= '9')
		{
			int num = 0;
			do
			{
				int digit = curChar - '0';  //'0' '1' '2' ....
				num = num * 10 + digit;
				i++;
				curChar = postfix[i];

			} while (curChar != ' ');

			st.push(num);
		}
		else //operation + - * /
		{
			float y = st.top();
			st.pop();
			float x = st.top();
			st.pop();

			float z;
			switch (curChar)
			{
			case '+':  z = x + y; break;
			case '-':  z = x - y; break;
			case '/':  z = x / y; break;
			case '*':  z = x * y; break;

			}
			st.push(z);

		}
	}

	return st.top();

}

int main()
{
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp; //(5+3)*((20/10)+(8-6))
	string postfix = infixToPostfix(exp);
	cout << "in postfix form: " << postfix << endl; //5 3 + 20 10 / 8 6 - +*
	cout << "calculated value: " << calcPostfix(postfix) << endl; //32
	return 0;
}
