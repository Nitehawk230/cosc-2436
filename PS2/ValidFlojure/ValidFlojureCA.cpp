/******************************
   Colton Anderson
   9/19/2020
   ValidFlojureCA.cpp
   Write a program to validate code from a test file to ensure
   every (,{,[,],},) has its correlating partner.
   References: GeeksForGeeks and mycodeschool Github
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <fstream>
#include <sstream>
using namespace std;

// Function declarations

// Check for pairs between opening and closing brackets
bool arePair(char open, char close)
{
	if (open == '(' && close == ')')
		return true;
	else if (open == '{' && close == '}')
		return true;
	else if (open == '[' && close == '}')
		return true;

	// If no pairs found
	return false;
}

// Check for balanced brackets 
bool areParsBalanced(string expr)
{
	stack<char> S;
	
	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
			S.push(expr[i]);
		else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
		{
			if (S.empty() || !arePair(S.top(), expr[i]))
				return false;
			else
				S.pop();
		}
	}
	// Return true if stack is empty else return false
	return S.empty() ? true : false;
}

int main()
{
	// Variables
	int testCases = 0;
	int numCase = 1;
	int numCodeLines = 0;
	int numPars = 0;
	int numSquar = 0;
	int numCurly = 0;
	int numItems = 0;
	int count = 0;
	string fileName;
	ifstream inputFile;
	string expression;
	string temp;

	//	Create Stack to hold ({[]}) only chars
	stack <string> flowjureStack; 
    
	// Retrieve filename
	cout << "\nEnter Filename: ";
	cin >> fileName;

	// Load and verify file
	inputFile.open(fileName);
	
	if (inputFile)
	{
		// Load number of test cases
		inputFile >> testCases;

		for (numCase; numCase < testCases; numCase++)
		{
			// Load number of lines of code
			inputFile >> numCodeLines;

			for (int i = 0; i < numCase; i++)
			{
				// Read line from file
				for (int j = 0; j < numCodeLines; j++)
				{
					getline(inputFile, temp);
					expression += temp;
				}

				// Call functions to test for balance
				if (areParsBalanced(expression))
				{
					// True
					cout << "Case " << i + 1 << ": Is balanced." << endl;
				}
				else
				{
					// False
					cout << "Case " << i + 1 << ": Is not balacned." << endl;
				}
			}
		}
	}
	else
	{
		cout << "\nError Opening File!\n";
	}
    
	//	Make sure we place the end message on a new line
    cout << endl;

	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();

    return 0;
}
