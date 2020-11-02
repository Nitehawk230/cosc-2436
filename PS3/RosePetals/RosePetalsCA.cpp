/******************************
   Colton Anderson
   10/26/2020
   RosePetalsCA.cpp
   Program to interpret using a rose to determine which suitor will remain 
   from 'plucking' off petals.
********************************/

// Headers
#include <iostream>
#include <string>
#include <fstream>	
#include <sstream>
#include <list>
#include <iterator>
using namespace std;

int numPetals(int n);

int main()
{
	//	Variables
	string fileName;
	fstream inputFile;
	string temp;
	string name;
	list<string> suitors;
	//list<suitors>::iterator iter = suitors.begin();
	int numOfSuitors = 0;
	int numLosers = 0;		// = (numPetals - 1) % a.size
	int numTestCases = 0;
	int petals = 0;
	int index = 0;
	//auto index = suitors.insert(suitors.end(), name);
		
	// Code
	cout << "Please enter filename: ";
	cin >> fileName;
	inputFile.open(fileName);
	
	// Load file
	if (inputFile)
	{
		// File set up as : num of test cases
		inputFile >> numTestCases;

		for (int i = 0; i < numTestCases; i++)
		{
			// Retrieves entire line of names
			getline(inputFile, temp);
			getline(inputFile, temp);
			istringstream iss(temp);
			while (iss)
			{
				iss >> name;
				suitors.push_back(name);
				numOfSuitors += 1;
			}
			
			// Find the one to die
			while (inputFile >> petals)
			{
				while (petals != 0)
				{
					// Iterate through the list petals times to find who to remove
					if ((index + 1) > numOfSuitors)
					{
						// Reset index
						index = 0;
						petals -= 1;
					}
					else if (index <= numOfSuitors)
					{
						index += 1;
						petals -= 1;
					}
				}
				if (petals == 0)
				{
					// Remove user at index
					//suitors.erase(index);
					for (int i = 0; i < index; i++)
					{
						temp = suitors.front();
						suitors.pop_front();
						suitors.push_back(temp);
					}
					temp = suitors.front();
					suitors.pop_front();
					cout << "\n" << temp << " is a loser!";
				}
			}
			// Found Winner
			temp = suitors.front();
			cout << "\n" << temp << " is a winner!";
		}
	}
	else
		cout << "\nError opening file!";

	inputFile.close();
	//	Make sure we place the end message on a new line
	cout << endl;
	cout << "Press any key to continue";
	cin.get();

	return 0;
}

int numPetals(int n)
{
	if (n == 1)
		return 1;
	else
	return (numPetals(n - 1) + 1) % n + 1;
}
