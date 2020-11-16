/******************************
   Colton Anderson
   11/12/2020
   TreeTraversalCA.cpp
   Description
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

struct Node
{
	char letter;
	Node* left = nullptr;
	Node* right = nullptr;
};

Node* createNode(char letter)
{
	Node* node = new Node();

	node->letter = letter;
	node->left = nullptr;
	node->right = nullptr;

	return node;
}

int main()
{
	//	Variables
	string name;
	istringstream iss(name);
	char letter;

	// Enter a name
	cout << "Enter a word: ";
	cin >> name;

	// Extract letters from given word
	while (iss)
	{
		iss >> letter;

		// Create tree
		Node* root = createNode(letter);		
	}


	//	Make sure we place the end message on a new line
    cout << endl;
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	
    return 0;
}
