/******************************
   Colton Anderson
   9/20/2020
   ERDoctorsCA.cpp
   Description: Program will simulate the a throughput of patients
				and how many doctors are needed to maintain a expected wait time
********************************/

// Headers
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	// Variables
	int numScenarios = 0;	
	int numPatients = 0;		
	int maxWaitTime = 0;	// Wait time in min
	int minWait = 0;
	int hourWait = 0;
	int severity = 0;
	int patientWaitTime = 8; // pwt * serverity
	char temp;
	string fileName;
	ifstream inputFile;
	queue<int> PatientsQ;

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
			inputFile >> numPatients;
			inputFile >> maxWaitTime;

			while (i < numPatients)
			{
				// Read in hour : min wait time
				inputFile >> hourWait >> temp >> minWait >> severity;
				PatientsQ.push(severity);
				i++;
			}
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

	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();

	return 0;
}
