#include "BinaryTree.h"
#include <iostream>

void BinaryTree::insert(TreeNode*&nodePtr, TreeNode*&newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode;						// Inserts node
	else if (newNode->letter < nodePtr->letter)
		insert(nodePtr->left, newNode);			// Left branch
	else
		insert(nodePtr->right, newNode);		// Right branch
}

void BinaryTree::destorySubTree(TreeNode*)
{
}

void BinaryTree::displayInOrder(TreeNode*nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		std::cout << nodePtr->letter << " ";
		displayInOrder(nodePtr->right);
	}
}

void BinaryTree::displayPreOrder(TreeNode*nodePtr) const
{
	if (nodePtr)
	{
		std::cout << nodePtr->letter << " ";
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

void BinaryTree::displayPostOrder(TreeNode*nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		std::cout << nodePtr->letter << " ";
	}
}

void BinaryTree::displayLevelOrder(TreeNode*nodePtr) const
{
}

void BinaryTree::displayReverseOrder(TreeNode*nodePtr) const
{
}

void BinaryTree::insertNode(char letter)
{
	TreeNode* newNode = nullptr;

	// Create new node and store value to it
	newNode = new TreeNode;
	newNode->letter = letter;
	newNode->left = newNode->right = nullptr;

	// Insert node
	insert(root, newNode);
}
