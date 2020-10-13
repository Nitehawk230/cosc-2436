/******************************
   Colton Anderson
   10/7/2020
   EvalExpressionCA.cpp
   Take a infix expresser from user and create prefix, postfix and final expression value.
   From Infix -> prefix and postfix
********************************/

// Headers
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

// Function declarations
int Priority(char c);
bool isOperator(stringstream s);

int main()
{
	// Variable
	string infix;
	string postfix;
	string prefix;
	double value = 0;
	bool again = true;
	char temp;

	// Get expression
	cout << "Enter Infix Expression: ";
	getline(cin, infix);

	stack<char> operator_stack;
	stack <string> preStack;
	stringstream output;
	
	while (again)
	{
		if (!operator_stack.empty())
			operator_stack.pop();

		for (int i = 0; i < infix.length(); i++)
		{
			// Check for operation
			if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
			{
				// While not empty, check PEMDAS
				while (!operator_stack.empty() && Priority(operator_stack.top()) <= Priority(infix[i]))
				{
					output << operator_stack.top();
					operator_stack.pop();
				}
				operator_stack.push(infix[i]);
			}
			else if (infix[i] == '(')
			{
				operator_stack.push(infix[i]);
			}
			else if (infix[i] == ')')
			{
				while (operator_stack.top() != '(')
				{
					output << operator_stack.top();
					operator_stack.pop();
				}
				operator_stack.pop();
			}
			else
			{
				output << infix[i];
			}
		}

		while (!operator_stack.empty())
		{
			output << operator_stack.top();
			operator_stack.pop();
		}

		for (int o = 0; o < infix.length(); o++)
		{
			if (isOperator(output))
			{
				char op1 = operator_stack.top();
				operator_stack.pop();
				char op2 = operator_stack.top();
				operator_stack.pop();

				string temp = output.str() + op2 + op1;

				preStack.push(temp);
			}
			else
			{
				preStack.push(string(1, output));
			}
		}

		cout << output.str() << endl; // Outputs Postfix
		cout << infix;				  // Outputs Infix
		cout << prefix;				  // Outputs Prefix

		cout << "Enter another expression? Y/N: ";
		cin >> temp;
		if (temp == 'Y' || temp == 'y')
			again = true;
		else if (temp == 'N' || temp == 'n')
			again = false;
		cout << endl;
	}
	//	Make sure we place the end message on a new line;
	cout << endl;

	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();

	return 0;
}

int Priority(char c)
{
	int temp = 0;
	if (c == '^')
		temp = 1;
	else if (c == '*' || c == '/')
		temp = 2;
	else if (c == '+' || c == '-')
		temp = 3;
	return temp;
}

bool isOperator(stringstream s)
{
	char c;
	s >> c;
	switch (c)
	{
	case '+':
		return true;
	case '-':
		return true;
	case '*':
		return true;
	case '/':
		return true;
	case '^':
		return true;
	default:
		return false;
	}
}
