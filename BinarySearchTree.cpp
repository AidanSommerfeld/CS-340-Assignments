#include <ctime>
#include <iostream>

#include "BinarySearchTree.h"

using std::cout;
using std::endl;

BST::BST()
/*Default constructor. */
{
	// While keys matter in BSTs and AVL trees,
	// we're only initializing the root here. Keep it low.

	root->setKey(rand() % 10);
	root->setValue(rand() % 10000);

	totalTreeDepth = 0;
	totalTreeNodes = 1;

	maxNodes = 100000; // Arbitrary.
}

BST::BST(int nodes)
/*Initializing constructor, given a user input.*/
{
	root->setKey(rand() % 10);
	root->setValue(rand() % 10000);

	totalTreeDepth = 0;
	totalTreeNodes = 1;

	maxNodes = nodes;
}

void BST::insertNode()
/*Overload of BT::insertNode(). */
{
	if (maxNodes >= totalTreeNodes)
	{
		int depth = 0;
		int randomKey = rand() % 10000;
		BST::insertHelper(root, depth, randomKey);		// Explicit call to the overload.
		incrementNodes();
	}
}

void BST::insertHelper(Node *root, int& depth, int keyValue)
/*Overload of BT::insertHelper(...). */
{
	depth++;

	if (root->getKey() > keyValue)
	{
		if (root->getLeft() == nullptr)
		{
			// Create node immediately if no child exists on left.
			Node *temp = new Node(keyValue, rand() % 1000);
			root->setLeft(temp);
		}
		else
		{
			// Recursive call; compare key against existing left subtree node.
			root->incrementHeight();
			insertHelper(root->getLeft(), depth, keyValue);
		}
	}
	else   // Attempts to create a node on the right if child key > root key.
	{
		if (root->getRight() == nullptr)
		{
			// If no child exists on right subtree...
			Node *temp = new Node(keyValue, rand() % 1000);
			root->setRight(temp);
		}
		else
		{
			// For existing right subtrees.
			root->incrementHeight();
			insertHelper(root->getRight(), depth, keyValue);
		}
	}

	// Dev concern:
	// If a large key is generated early, this causes a 
	// significant bias to one side of the tree, doesn't it?

	// Assumption: 
	// Inherently, no, but it should cause a lot of 
	// left-side bias as the tree develops. e.g.:
	//           1
	//       73     1000
	//     23  75  12   10045
	//              341 2225
}

Node *BST::find(int value, Node *node)
/*Attempts to search for a node containing the key value of the query. */
{
	// Implies no value matched at end of search, or value exists.
	if (node == nullptr || value == node->getKey())
		return node;
	else if (value < node->getKey())			// If subtree exists branch by key value.
		return find(value, node->getLeft());    // Obviously, smaller values on the left...
	else
		return find(value, node->getRight());   // ...larger ones on the right.
}

Node *BST::findMin(Node *root)
/*Finds the left-most node, which logically has the lowest key value. */
{
	if (root == nullptr || root->getLeft() == nullptr) // End of search, else...
		return root;

	return findMin(root->getLeft()); // Recursive call if null not met.
}

Node *BST::findMax(Node *root)
/*Finds the right-most node, which logically has the highest key value.
Similar to findMin(). */
{
	if (root == nullptr || root->getRight() == nullptr)
		return root;

	return findMax(root->getRight());
}

BST::~BST()
{
	removeTree(root);
	root = nullptr;
}
