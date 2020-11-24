/******************************
   Colton Anderson
   11/12/2020
   TreeTraversalCA.cpp
   Create binary tree from user designated word.
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	//	Variables
	string word;
	char letter;
	BinaryTree tree;

	// Enter a name
	cout << "Enter a word: ";
	cin >> word;
	istringstream iss(word);

	// Extract letters from given word
	while (iss >> letter)
	{
		tree.insertNode(letter);
	}

	// Display order in an order
	cout << "\nPreorder traversal: ";
	tree.displayPreOrder();

	cout << "\nPostorder traversal: ";
	tree.displayPostOrder();

	cout << "\nInorder traversal: ";
	tree.displayInOrder();

	cout << "\nLevel order traversal: ";
	tree.displayLevelOrder();

	cout << "\nReverse order traversal: ";
	tree.displayReverseOrder();

	//	Make sure we place the end message on a new line
	cout << endl << endl;
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	
    return 0;
}
