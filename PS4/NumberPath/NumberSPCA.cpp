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
#include <fstream>
#include <vector>
#include <Bits.h>

using namespace std;

// Functions
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; ++v)
	{
		cout << "\nAdj list of vertest " << v << "\nhead ";
		for (auto x : adj[v])
			cout << "-> " << x;
		printf("\n");
	}
}
int main()
{
	//	Variables
	const int numX = 20;
	const int numY = 20;
	const int V = 400;
	int numFields = 0;
	int numHours = 0;
	char temp;
	string fileName;
	ifstream inputFile;

	// Retrieve filename;
	cout << "Enter filename: ";
	cin >> fileName;

	// Open and verify file
	inputFile.open(fileName);
	if (inputFile)
	{
		// Load number of fields
		inputFile >> numFields;

		vector<int> adj[V];
		for (int y = 0; y < numY; y++)
		{
			for (int x = 0; x < numX; x++)
			{
				inputFile >> temp;
				addEdge(adj, y, temp);
			}
		}

		// Compute the dayta
		printGraph(adj, V);
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
