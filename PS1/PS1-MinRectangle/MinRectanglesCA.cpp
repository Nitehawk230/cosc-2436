/******************************
   Colton Anderson
   9/9/2020
   MinRectanglesCA.cpp
   Create user defined 2D array that will be filled randomly with 0's and 1s
   and then calculate the number of possible rectangles that can be built
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <array>
#include <time.h>
using namespace std;

int main()
{
	// Variables
	int numArray = 0;	// y-cols
	int numInt = 0;		// x-rows
	int randNum = 0;
	char decision;
	bool finished = false;
	int numRectangles = 0;

	// Seed rng
	srand(time(NULL));

	while (!finished)
	{
		// Ask user to input array size, 2-5
		cout << "\nEnter number of rows between 2 and 5: ";
		cin >> numInt;
			while (numInt < 2 || numInt > 5)
		{
				// Validate input
			cout << "\n\tError: Please enter a number between 2 and 5: ";
			cin >> numInt;
		}

		cout << "\nEnter number of columns between 2 and 5: ";
		cin >> numArray;
			while (numArray < 2 || numArray > 5)
		{
				// Validate input
			cout << "\n\tError: Please enter a number between 2 and 5: ";
			cin >> numArray;
		}

		// Create 2D array using users' date
		int** array = new int* [numArray];
		for (int i = 0; i < numArray; i++)
			array[i] = new int[numInt];

		// Randomly fill array with either a 0 or 1
		for (int i = 0; i < numArray; i++)
		{
			for (int j = 0; j < numInt; j++)
			{
				array[i][j] = (rand() % 2);
			}
		}

		// Print Generate 2D Array
		cout << "\nArray Generated\n";
		for (int i = 0; i < numArray; i++)
		{
			for (int j = 0; j < numInt; j++)
			{
				cout << array[i][j] << " ";
			}
			cout << endl;
		}

		// Count number of possible rectangles
		for (int i = 0; i < numArray; i++)
		{
			for (int j = 0; j < numInt; j++)
			{
				// Correct rectangles are multiples of 2, endings CAN wrap.
			}
		}

		// Close 2D Array
		for (int i = 0; i < numArray; ++i)
		{
			delete[] array[i];
			array[i] = NULL;
		}
		delete[] array;
		array = NULL;

		// Ask user to restart
		cout << "\nRun again? Y/N: ";
		cin >> decision;
		if (decision == 'Y')
			finished = false;
		else if (decision == 'N')
			finished = true;
		if (decision == 'y')
			finished = false;
		else if (decision == 'n')
			finished = true;
	}

	//	Make sure we place the end message on a new line
    cout << endl;

	//	The following is system dependent.  It will only work on Windows
    // system("PAUSE");

	 
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();

    return 0;
}
