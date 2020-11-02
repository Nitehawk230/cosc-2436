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

bool compareStu(Student lhs, Student rhs)
{
	return lhs.UILScore < rhs.UILScore;
}

bool sortStu(Student lhs, Student rhs)
{
	return lhs.schoolClass < rhs.schoolClass;
}

int main()
{
	//	Variables
	string fileName;
	ifstream inputFile;
	string temp;
	string stuName;
	int numOfQ = 40;
	int numOfStudents = 0;
	int stuIndex = 0;
	vector<string> KEY;
	vector<string> stuAnswers;
	vector<Student> students;
	vector<string> firstNames;
	Student studentName;

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

			// Load Students information
			//inputFile >> stuName;
			//firstNames.push_back(stuName);			
			inputFile >> studentName.firstName;
			inputFile >> studentName.lastName;
			inputFile >> studentName.schoolName;
			inputFile >> studentName.schoolClass;
			students.push_back(studentName);
			numOfStudents += 1;

				// Load students' answers
				for (int i = 0; i < numOfQ; i++)
				{
					inputFile >> temp;
					stuAnswers.push_back(temp);
				}

				// Calculate student score
				for (int i = 0; i < numOfQ; i++)
				{
					if (stuAnswers[i] == KEY[i])
						studentName.numCorr += 1;
					else if (stuAnswers[i] != KEY[i])
						studentName.numIncorr += 1;
				}
				studentName.testScore = (studentName.numCorr / numOfQ);
				studentName.UILScore = ((studentName.numCorr * 6) - (studentName.numIncorr * 2));

		}

		// sort and output
		//sort(students.begin(), students.end(), compareStu);
		//sort(students.begin(), students.end(), sortStu);

		for (int i = 0; i < numOfStudents; i++)
		{
			stuName = firstNames[i];
			cout << "\nTesting for: " << studentName.firstName;
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
