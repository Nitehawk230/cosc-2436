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

struct Student
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

// Function to compare students based off score
bool compareStudents(Student a, Student b)
{
	// If student A has higher score; return true
	if (a.UILScore > b.UILScore)
		return true;
}

int main()
{
	//	Variables
	string fileName;
	ifstream inputFile;
	string temp;
	int numOfQ = 40;
	int StuIndex = 0;
	int numOfStudents = 0;
	vector<string> KEY;
	vector<string> stuAnswers;
	vector<string> studentNames;
	Student studentsStruct;

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
				// Creates a new user in struct off data from file
				inputFile >> studentsStruct.firstName;
				inputFile >> studentsStruct.lastName;
				inputFile >> studentsStruct.schoolName;
				inputFile >> studentsStruct.schoolClass;
				studentNames.push_back(studentsStruct.firstName);

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
						studentsStruct.numCorr += 1;
					}
					else
					{
						// Incorrect
						studentsStruct.numIncorr += 1;
					}
						
				}

				// Calculate students' score
				studentsStruct.testScore = (studentsStruct.numCorr / studentsStruct.numIncorr);
				studentsStruct.UILScore = ((studentsStruct.numCorr * 6) - (studentsStruct.numIncorr * 2));
			}

			// Display info
			for (int i = 0; i < StuIndex; i++)
			{
				// Sort by School Rank then by Score
				// 1A
				for (int j = 0; j < numOfStudents; j++)
				{
					temp = studentNames[j];
					if (studentsStruct.firstName == temp && studentsStruct.schoolClass == "1A")
					{
						// Display 1A from highest score to lowest

					}
					
				}
				// 2A
				for (int j = 0; j < numOfStudents; j++)
				{
					temp = studentNames[j];
					if (studentsStruct.firstName == temp && studentsStruct.schoolClass == "2A")
					{
						// Display 2A from highest score to lowest
					}

				}
				// 3A
				for (int j = 0; j < numOfStudents; j++)
				{
					temp = studentNames[j];
					if (studentsStruct.firstName == temp && studentsStruct.schoolClass == "3A")
					{
						// Display 3A from highest score to lowest
					}

				}
				// 4A
				for (int j = 0; j < numOfStudents; j++)
				{
					temp = studentNames[j];
					if (studentsStruct.firstName == temp && studentsStruct.schoolClass == "4A")
					{
						// Display 4A from highest score to lowest
					}

				}
				// 5A
				for (int j = 0; j < numOfStudents; j++)
				{
					temp = studentNames[j];
					if (studentsStruct.firstName == temp && studentsStruct.schoolClass == "5A")
					{
						// Display 5A from highest score to lowest
					}

				}
				// 6A
				for (int j = 0; j < numOfStudents; j++)
				{
					temp = studentNames[j];
					if (studentsStruct.firstName == temp && studentsStruct.schoolClass == "6A")
					{
						// Display 6A from highest score to lowest
					}

				}
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
