/******************************
   Colton Anderson
   9/20/2020
   ERDoctorsCA.cpp
   Description: Program will simulate the a throughput of patients
				and how many doctors are needed to maintain a expected wait time
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
	int numScenarios = 0;	
	int numEntries = 0;		
	int maxWaitTime = 0;	// Wait time in min
	string patientWaitTime;
	string fileName;
	ifstream inputFile;

	// Retrieve filename
	cout << "\nPlease enter the filename: ";
	cin >> fileName;
	inputFile.open(fileName);	// Load file
	
	// Verify Filename Is True
	if (inputFile)
	{
		// Load number of scenarios
		inputFile >> numScenarios;
		for (int i = 0; i < numScenarios; i++)
		{
			inputFile >> numEntries;
			inputFile >> maxWaitTime;
		}
	}
	else
	{
		cout << "\nError Opening File\n";
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
