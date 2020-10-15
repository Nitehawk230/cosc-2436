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
int precedence(char c);
string InfixToPostfix(string infix);

int main()
{
	// Variable
	string infix;
	string postfix;
	string prefix;
	string input;
	stack<char> operator_stack;
	stack<char> prefix_stack;
	stringstream postfixoutput;
	stringstream prefixoutput;
	double value = 0;
	char decision = 'Y';

	while (decision == 'Y' || decision == 'y')
	{
		// Get expression
		cout << "\nEnter Infix Expression: ";
		getline(cin, infix);

		// Process infix to postfix
		for (int i = 0; i < infix.length(); i++) 
		{
			// Check if scanned character is a operator
			if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') 
			{
				while (!operator_stack.empty() && precedence(operator_stack.top()) <= precedence(infix[i])) 
				{
					postfixoutput << operator_stack.top();
					operator_stack.pop();
				}
				operator_stack.push(infix[i]);
			}
			// Push opening parenthesis if found
			else if (infix[i] == '(')
				operator_stack.push(infix[i]);

			// If closing parenthesis is found 
			else if (infix[i] == ')') 
			{
				while (operator_stack.top() != '(') 
				{
					postfixoutput << operator_stack.top();
					operator_stack.pop();
				}
				operator_stack.pop();
			}
			else 
				postfixoutput << infix[i];
		}

		while (!operator_stack.empty()) 
		{
			postfixoutput << operator_stack.top();
			operator_stack.pop();
		}

		// Process postfix to prefix
		for (int i = 0; i < infix.length(); i++)
		{
			// Check if scanned character is a operator
			if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
			{
				prefix_stack.push(infix[i]);
			}
			else
			{
				while (!prefix_stack.empty())
				{
					prefixoutput << prefix_stack.top();
					prefix_stack.pop();
				}
			}
		}

		// Output prefix
		cout << "\nPrefix: " << prefixoutput.str();

		// Output postfix
		cout << "\nPostfix:	" << postfixoutput.str();

		// Output infix
		cout << "\nInfix: " << infix;

		// Repeat?
		cout << "\nWould you like to enter another expression? (Y/N): ";
		cin >> decision;
		cout << endl;
	}

	//	Make sure we place the end message on a new line;
	cout << endl;

	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();

	return 0;
}

// Determines the precedence of operators within expression
int precedence(char c)
{
	if (c == '^')
		return 1;
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 3;
	else
		return -1;
}

// Converts entered infix to postfix expression
string InfixToPostfix(string infix)
{
	// Variables
	stack<char>infixStack;
	infixStack.push(' ');		// Pushes temp value to stack 
	int length = infix.length();
	string postfix;

	// Scan characters looking for operators or operands
	for (int i = 0; i < length; i++)
	{
		if (infix[i] == ' ' || infix[i] == ',')
			continue;

		// If operation is found push it back
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
		{
			while (!infixStack.empty() && infixStack.top() != '(' && precedence(infixStack.top()) > precedence(infix[i]))
			{
				postfix += infixStack.top();
				infixStack.pop();
			}
			infixStack.push(infix[i]);
		}

		// If operand is found 
		else if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
			postfix += infix[i];

		// If opening parenthesis is found
		else if (infix[i] == '(')
			infixStack.push(infix[i]);

		// If closing parenthesis is found
		else if (infix[i] == ')')
		{
			while (!infixStack.empty() && infixStack.top() != '(')
			{
				postfix += infixStack.top();
				infixStack.pop();
			}
			infixStack.pop();
		}
	}

	while (!infixStack.empty())
	{
		postfix += infixStack.top();
		infixStack.pop();
	}
	return postfix;
}
