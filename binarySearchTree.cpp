#include <ctime>
#include <iostream>

#include "binarySearchTree.h"

using std::cout;
using std::endl;

BST::BST()
/* Default constructor. */
{
	// While keys matter in BSTs and AVL trees,
	// we're only initializing the root here. Keep it low.

	root->setKey(rand() % 10);
	cout << "Key set for root node." << endl;

	root->setValue(rand() % 10000);
	cout << "Value set for root node." << endl;

	totalTreeDepth = 0;
	totalTreeNodes = 1;

	maxNodes = 100000; // Arbitrary.
}

BST::BST(int nodes)
/* Initializing constructor, given a user input.*/
{
	root->setKey(rand() % 10);
	root->setValue(rand() % 10000);

	totalTreeDepth = 0;
	totalTreeNodes = 1;

	maxNodes = nodes;
}

void BST::insertNode()
/* Overload of BT::insertNode(). */
{
	if (maxNodes > totalTreeNodes)
	{
		int depth = 0;
		BST::insertHelper(root, depth);		// Explicit call to the overload.
		incrementNodes();
	}
}

void BST::insertHelper(Node* root, int& depth)
/* Overload of BT::insertHelper(...). */
{
	depth++; // ????????

	// Algorithm:
	// - Generate a key.
	// - Compare key against root.
	// - Branch a subtree compared against root.
	// - If subtree exists, recursive call.
	// - If subtree does not exist, generate the node.

	// Issues:
	// If a large key is generated early, this causes a 
	// significant bias to one side of the tree, doesn't it?
	// Inherently, no, but it should cause a lot of 
	// left-side bias as the tree develops.
	// 1
	// 73 1000
	// 23 75 12 10045
}

Node* BST::find(int value, Node* node)
/* Attempts to search for a node containing the key value of the query. */
{
	// Implies no value matched at end of search, or value exists.
	if (node == nullptr || value == node->getKey)	
		return node;
	else if (value < node->getKey())			// If subtree exists branch by key value.
		return find(value, node->getLeft());    // Obviously, smaller values on the left...
	else 
		return find(value, node->getRight());   // ...larger ones on the right.
}

Node* BST::findMin(Node* root)
/* Finds the left-most node, which logically has the lowest key value. */
{
	if (root == nullptr || root->getLeft() == nullptr) // End of search, else...
		return root;
	
	return findMin(root->getLeft()); // Recursive call if null not met.
}

Node* BST::findMax(Node* root)
/* Finds the right-most node, which logically has the highest key value. 
   Similar to findMin(). */
{
	if (root == nullptr || root->getRight() == nullptr)
		return root;

	return findMax(root->getRight());
}

BST::~BST()
{
	removeNode(root);
	root = nullptr;
}