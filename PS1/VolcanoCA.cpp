/******************************
   Colton Anderson
   8/28/2020
   VolcanoCA.cpp
   Description: Determine if location of house is safe from volcano,
				if not find if cave is safe from volcano when erruptions,
				occures in up, down, left, right directions and blocked,
				by water.
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
	int numChars = 0, numArrays =0, numCases = 0, caseNum = 0;
	int homey = 0, homex = 0, watery = 0, waterx = 0, cavey = 0, cavex = 0, volcanoy = 0, volcanox = 0;		// Y->numArray | X->numChar
	bool water = false;
    
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
		for (caseNum; caseNum < numCases; caseNum++)
		{
			// Load first array size
			inputFile >> numArrays;		// Y
			inputFile >> numChars;		// X

			// Create 2D Array
			char** array = new char* [numArrays];		// Create an array of pointers for num colums
			for (int i = 0; i < numArrays; i++)
			{
				array[i] = new char[numChars];			// Creates an array of num of Chars for each arrary of pointers
			}

			for (int o = 0; o < numArrays; o++)
			{
				for (int p = 0; p < numChars; p++)
				{
					inputFile >> array[o][p];
				}
			}

			// Find Volcano (V) location
			// Cycle thru array looking for volcano
			for (int i = 0; i < numArrays; i++)
			{
				for (int j = 0; j < numChars; j++)
				{
					if (array[i][j] == 'V')
					{
						volcanoy = i;
						volcanox = j;
					}					
				}
			}

			// Find Home (S) location
			// Cycle thru array looking for home
			for (int i = 0; i < numArrays; i++)
			{
				for (int j = 0; j < numChars; j++)					
				{
					if (array[i][j] == 'S')
					{
						homey = i;
						homex = j;					
					}
				}
			}

			// Find Cave (C) location
			// Cycle thru array looking for cave
			for (int i = 0; i < numArrays; i++)
			{
				for (int j = 0; j < numChars; j++)
				{
					if (array[i][j] == 'C')
					{
						cavey = i;
						cavex = j;
					}
				}
			}

			// Check and see if V is inline with S
			if (volcanoy == homey)
			{
				// Check if water is between volcano and home
				for (int i = 0; i < numChars; i++)
				{
					if (array[volcanoy][i] == 'W')
					{
						waterx = i;
					}
				}

				if (waterx > volcanox && waterx < homex)
				{
					cout << "\nCase " << caseNum + 1 << ": Safe, Don't Move.\n";
					water = true;
				}

				if (water == false)
				{
					// If water is not found
					// Look for cave
					if (volcanoy == cavey)
					{
						cout << "\nCase " << caseNum + 1 << ": Danger, Move!\n";
					}
					else if (volcanox == cavex)
					{
						for (int j = 0; j < numArrays; j++)
						{
							if (array[j][cavex] == 'W')
							{
								watery = j;
								if (watery > cavex && watery < volcanox || watery < cavex && watery > volcanox)
								{
									cout << "\n"
								}
							}
						}
					}
					else if (volcanox != cavex)
					{
						if (volcanoy != cavey)
						{
							cout << "\nDanger, Move To Cave!\n";
						}
					}
				}
			}
			else
			{
				cout << "\nCase " << caseNum + 1 << ": Safe, Don't Move.\n";
			}

			// Close array order

			for (int i = 0; i < numArrays; ++i)
			{
				delete[] array[i];
				array[i] = NULL;
			}
			delete[] array;
			array = NULL;
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
