/******************************
   Colton Anderson
   10/26/2020
   SchoolRankSupport.cpp
   Write program that reads in users data (students name, school name & class, students answer and answer key to compare to)
   Print report that groups students baised on schools classification and ranks based on test score. 
   Scoring Method: 6 points per correct, 2 points lost per incorrect, and ignore any skipped questons. 
   Ties depend on student with greater precentage correct.
   ********************************/

// Headers
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// Global Constants
const int NUMOFTESTANSWERS = 40;

// THOUGHTS
// process file, load students answers into queue and compare to key queue and calculate score, store score and school rank

struct Students
{
	string firstName;
	string lastName;
	string schoolName;
	string schoolClass;
	double testScore = 0;
	int numCorr = 0;
	int numIncorr = 0;
	int UILScore = 0;
};

int main()
{
	//	Variables
	string fileName;
	ifstream inputFile;
	string studentFName;
	string schoolName;
	string schoolClassification;
	string temp;
	int numOfQ = 40;
	int StuIndex = 0;
	vector<string> KEY;
	vector<string> stuAnswers;

	// Codes
	cout << "Enter Filename: ";	
	cin >> fileName;

	inputFile.open(fileName);

	// Verify file
	if (inputFile)
	{
		// Process the file
		while (inputFile >> temp) // Loads through KEY word
		{
			for (int i = 0; i < numOfQ; i++)
			{
				inputFile >> temp;
				KEY.push_back(temp);
			}
			
			while (inputFile)
			{
				// Load student into
				Students StuStruct[StuIndex];
				inputFile >> StuStruct.firstName;
				inputFile >> StuStruct.lastName;
				inputFile >> StuStruct.schoolName;
				inputFile >> StuStruct.schoolClass;				

				// Load Students' answers
				for (int i = 0; i < numOfQ; i++)
				{
					inputFile >> temp;
					stuAnswers.push_back(temp);
				}

				// Compare students' answers to key and store score to struct
				for (int i = 0; i < numOfQ; i++)
				{
					if (stuAnswers[i] == "S")
					{
						// skip
					}					
					else if (stuAnswers[i] == KEY[i])
					{
						// Correct
						StuStruct.numCorr += 1;
					}
					else
					{
						// Incorrect
						StuStruct.numIncorr += 1;
					}
						
				}

				// Calculate students' score
				StuIndex.testScore = (StuIndex.numCorr / StuIndex.numIncorr);
				StuIndex.UILScore = ((StuIndex.numCorr * 6) - (StuIndex.numIncorr * 2));
			}

			// Display info
			for (int i = 0; i < StuIndex; i++)
			{
				// Sort by School Rank then by Score
				// 1A
				if ()
				// 2A

				// 3A

				// 4A
				
				// 5A

				// 6A
			}
		}

	}
	else
		cout << "\nError Opening File!";

	inputFile.close();

	cout << endl;
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	return 0;
}
