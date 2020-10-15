/******************************
   Colton Anderson
   10/14/2020
   CheckPaliCA.cpp
   Check for palindromes from inputed text
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool checkForPali(string input);

int main()
{
	//	Variables
	string input;
	char decision = 'Y';

	while (decision == 'Y' || decision == 'y')
	{
		// Ask to enter a palindrome
		cout << "Enter a palindrome: ";
		getline(cin, input);

		// Check if palindrome
		if (checkForPali(input))
			cout << "Input is palindrome.\n";
		else
			cout << "Input is not palindrome.\n";

		// Ask to repeat
		cout << "\nEnter another palindrome? (Y/N): ";
		cin >> decision;
		cout << endl;
	}
	
	//	Make sure we place the end message on a new line
	cout << endl;
	cout << "Press any key to continue";
	cin.get();
	return 0;
}

bool checkForPali(string input)
{
	int l = 0;	// Left index 
	int r = 0;	// Right index
	r = input.length();

	for (int i = 0; i < r; i++)
		input[i] = tolower(input[i]);	// converts upper to lowercase

	while (l <= r)
	{
		// Checks for symbols
		if (!(input[l] >= 'a' && input[l] <= 'z'))
			l++;
		else if (!(input[r] >= 'a' && input[r] <= 'z'))
			r--;

		// Check if equal
		else if (input[l] == input[r])
			l++, r--;
		// Sent is not equal
		else
			return false;
	}
	// Sent is equal
	return true;
}
