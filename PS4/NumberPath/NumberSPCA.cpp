/******************************
   Colton Anderson
   11/16/2020
   NumberSPCA.cpp
   Read a 20*20 field of numbers raging from [0-4] taking 1hr + ((n+1)-n) * 2
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	//	Variables
	const int numX = 20, const int numY = 20;
	vector<vector<int>> Field(numX);
	int numFields = 0;
	int numHours = 0;
	string fileName;
	ifstream inputFile;

	// Create 2d matrix
	for (int y = 0; y < numY; y++)
	{
		Field[y] = vector<int>(numX);
		for (int x = 0; x < numX; x++)
		{
			Field[y][x] = j + 1;
		}
	}

	// Retrieve filename;
	cout << "Enter filename: ";
	cin >> fileName;

	// Open and verify file
	inputFile.open(fileName);
	if (inputFile)
	{
		// Load matrix
		for (int y = 0; y < numY; y++)
		{
			for (int x = 0; x < numX; x++)
			{
				
			}
		}
	}
	else
		cout << "\nError opening file!";

	//	Make sure we place the end message on a new line
    cout << endl;

	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();

    return 0;
}
