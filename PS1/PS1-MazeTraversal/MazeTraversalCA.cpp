/******************************
   Colton Anderson
   9/10/2020
   MazeTraveralCA.cpp
   Make a way through a maze using Right hand and Left handed technique 
   loading maze from file to populate Number of Cases, Maze Size, L or R tech and start/ending locations.
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	// Variables
	ifstream inputFile;
	string fileName;
	int numCases = 0, caseNum = 0, numArrays = 0, numLocations = 0;		// Y=numArray | X=numLocation
	int startX = 0, startY = 0, endX = 0, endY = 0;
	char method;

	// Retrieve filename
	cout << "\nEnter filename: ";
	cin >> fileName;

	// Load and verify file
	inputFile.open(fileName);
	if (inputFile)
	{
		// Load case number from file
		inputFile >> numCases;
		
		for (caseNum; caseNum < numCases; caseNum++)
		{
			// Load starting values
			inputFile >> numArrays;			// Y
			inputFile >> numLocations;		// X
			inputFile >> method;
			inputFile >> startY;			// 1 value higher than array
			inputFile >> startX;			// 1 value higher than array
			inputFile >> endY;				// 1 value higher than array
			inputFile >> endX;				// 1 value higher than array

			// Create 2D array
			char** array = new char* [numArrays];
			for (int i = 0; i < numArrays; i++)
				array[i] = new char[numLocations];

			// Populate Array with Maze
			for (int i = 0; i < numArrays; i++)
			{
				for (int j = 0; j < numArrays; j++)
				{
					inputFile >> array[i][j];
				}
			}

			if (method == 'R')			// R hand method
			{
				cout << "\nCase Number " << caseNum + 1 << ": " << "Right\n";
			}
			else if (method == 'L')		// L hand method
			{
				cout << "\nCase Number " << caseNum + 1 << ": " << "Left\n";
			}

			// Delete 2D Array
			for (int i = 0; i < numArrays; ++i)
			{
				delete[] array[i];
				array[i] = NULL;
			}
			delete[] array;
			array = NULL;
		}
	}
	else
		cout << "\nError Opening File.\n";
    
	//	Make sure we place the end message on a new line
    cout << endl;

	//	The following is system dependent.  It will only work on Windows
    // system("PAUSE");


	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();

	return 0;
}
