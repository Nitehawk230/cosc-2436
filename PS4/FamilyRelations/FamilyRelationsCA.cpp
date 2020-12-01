/******************************
   Colton Anderson
   11/30/2020
   FamilyRelationsCA.cpp
   Create family tree from user provided data file
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "GenericTree.h"
using namespace std;

int main()
{
	//	Variables
	int numRelationships = 0;
	string firstName;
	string lastName;
	string relationship;
	string fileName;
	ifstream inputFile;

	// Retreive filename
	cout << "Enter filename: ";
	cin >> fileName;

	// Open/Verify file
	inputFile.open(fileName);
	if (inputFile)
	{
		// Load number of relationships
		inputFile >> numRelationships;
		// Load people
		for (int i = 0; i < numRelationships; i++)
		{
			inputFile >> firstName;
			inputFile >> lastName;
			inputFile >> relationship;
		}
	}
	else
		cout << "\nError opening file.";
    
	//	Make sure we place the end message on a new line
    cout << endl;

	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
    return 0;
}