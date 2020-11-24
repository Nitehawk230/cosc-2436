#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree
{
private:
	struct TreeNode
	{
		char letter;
		TreeNode* right = nullptr;	// Pointer to right node
		TreeNode* left = nullptr;	// Pointer to left node
	};

	TreeNode* root;					// Pointer to root node

	// Private functions
	void insert(TreeNode*&, TreeNode*&);
	void destorySubTree(TreeNode*);
	void displayInOrder(TreeNode*) const;
	void displayPreOrder(TreeNode*) const;
	void displayPostOrder(TreeNode*) const;
	void displayLevelOrder(TreeNode*) const;
	void displayReverseOrder(TreeNode*) const;

public:
	// Constructor
	BinaryTree() { root = nullptr; }

	// Destructor
	~BinaryTree() { destorySubTree(root); }

	// Tree operations
	void insertNode(char);
	void displayInOrder() const { displayInOrder(root); }
	void displayPreOrder() const { displayPreOrder(root); }
	void displayPostOrder() const { displayPostOrder(root); }
	void displayLevelOrder() const { displayLevelOrder(root); }
	void displayReverseOrder() const { displayReverseOrder(root); }
};
#endif // !BINARYTREE_H