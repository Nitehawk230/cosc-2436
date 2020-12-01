#include <string>
#ifndef GENERIC_TREE_H
#define GENERIC_TREE_H

class GenericTree
{
private:
	struct TreeNode
	{
		std::string name;
		TreeNode* right = nullptr;
		TreeNode* left = nullptr;
	};

	TreeNode* root;

	// Private functions
	void insert(TreeNode*&, TreeNode*&);
	
public:
	// Constructor
	GenericTree() { root = nullptr; }
	// Deconstructor
	~GenericTree() { root = nullptr; }

	// Tree operands
	void insertNode(std::string);
};

#endif // !GENERIC_TREE_H