/******************************
   Colton Anderson
   8/28/2020
   VolcanoCA.cpp
   Description: Pain
********************************/

// Headers
#include <iostream>
#include <array>
#include <fstream>
#include <string>
using namespace std;

// Global variables

// Function declarations

int main()
{    
	// Variables
	ifstream inputFile;
	string fileName;
	char temp;
	bool home = false;
	bool volcano = false;
	bool cave = false;
	bool water = false;
	int homex, homey, volcanox, volcanoy, waterx, watery, cavex, cavey = 0;
	int numRows = 0, numCols = 0, numCases = 0;
    
	// Retrieve filename
	cout << "\nEnter filename:";
	cin >> fileName;

	// Load File
	inputFile.open(fileName);

	// Load number of cases
	inputFile >> numCases;

	// Verify File
	if (inputFile)	// If opened; process
	{
		// Load array from file
		for (int i = 0; i < numCases; i++)
		{
			// Load first array size
			inputFile >> numCols;
			inputFile >> numRows;

			// Create 2D Array
			char** array;
			array = new char* [numCols];
			for (int i = 0; i < numRows; i++)
			{
				array[i] = new char[numRows];
			}

			for (int o = 0; o < numCols; o++)
			{
				for (int p = 0; p < numRows; p++)
				{
					inputFile >> temp;
					array[o][p] = temp;
					cout << "Test Spot A";
				}
			}

			// Look through array for locatons
			while (water)
			{
				for (int i = 0; i < numCols; i++)
				{
					for (int p = 0; p < numRows; p++)
					{
						array[i][p] = temp;

						if ('W' == "temp"[0])
						{
							waterx = i;
							watery = p;
							water = true;
							cout << "Water found\n";
						}
					}
				}
			}
			while (home)
			{
				for (int i = 0; i < numCols; i++)
				{
					for (int p = 0; p < numRows; p++)
					{
						array[i][p] = temp;

						if ('S' == "temp"[0])
						{
							homex = i;
							homey = p;
							home = true;
							cout << "Home found\n";
						}
					}
				}
			}
			while (cave)
			{
				for (int i = 0; i < numCols; i++)
				{
					for (int p = 0; p < numRows; p++)
					{
						array[i][p] = temp;

						if ('C' == "temp"[0])
						{
							cavex = i;
							cavey = p;
							cave = true;
							cout << "Cave found\n";
						}
					}
				}
			}
			while (volcano)
			{
				for (int i = 0; i < numCols; i++)
				{
					for (int p = 0; p < numRows; p++)
					{
						array[i][p] = temp;

						if ('V' == "temp"[0])
						{
							volcanox = i;
							volcanoy = p;
							volcanoy = true;
							cout << "Volcano found\n";
						}
					}
				}
			}

			// Output display
			cout << "\nTesting Case Number " << i+1 << ".\n";
			cout << "Array Size " << numCols << " " << numRows << endl;
			for (int o = 0; o < numCols; o++)
			{
				for (int p = 0; p < numRows; p++)
				{
					cout << array[o][p] << " ";
				}
				cout << endl;
			}
			cout << "Test Spot B";
			// Close array order
			for (int i = 0; i < numRows; i++)
			{
				cout << "Test Spot D";
				delete[] array[i];
			}
			delete[] array;
			cout << "Test Spot C";
		}
	}
		else	// Display Error
	{
	cout << "\nError opening the file.\n";
	}
		// Close File
		inputFile.close();


	//	Make sure we place the end message on a new line
    cout << endl;

	//	The following is system dependent.  It will only work on Windows
    system("PAUSE");

	/* 
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
    return 0;
}
