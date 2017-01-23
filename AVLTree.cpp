#include <ctime>
#include <iostream>

#include "AVLTree.h"

using std::cout;
using std::endl;

AVL::AVL()
/* Default constructor. */
{
	root->setKey(rand() % 10);
	root->setValue(rand() % 10000);

	totalTreeDepth = 0;
	totalTreeNodes = 1;

	maxNodes = 100000; // Arbitrary.
}

AVL::AVL(int nodes)
/* Initializing constructor, given a user input. */
{
	root->setKey(rand() % 10);
	root->setValue(rand() % 10000);

	totalTreeDepth = 0;
	totalTreeNodes = 1;

	maxNodes = nodes;
}

bool AVL::searchTree(int num)
{
	bool found = false;
	searchHelper(root, found, num);
	return found;
}

bool AVL::searchHelper(Node *root, bool &found, int num)
/* A recursive function that searches the tree for a node with a certain key. */
{
	if (root == nullptr)
	{
		return found;
	}
	if (root->getKey() == num)
	{
		found = true;
		return found;
	}
	searchHelper(root->getLeft(), found, num);

	if (found == true)
	{
		return found;
	}

	searchHelper(root->getRight(), found, num);

	return found;
}   

int AVL::max(int a, int b)
/* In context, the max function only compares the heights
   of left / right subtrees. */
{
	if (a > b)
		return a;
	else
		return b;
}

/*===================================================
// Rotation functions.                             */

// Single-rotation functions.
// Called by double rotations as well.

Node *AVL::RR(Node *original)
{
	Node *temp1 = new Node;
	Node *temp2 = new Node;

	temp1 = original->getLeft(); // Sets temp1 as left of original.
	temp2 = temp1->getRight();   // Sets temp2 to the right of original.
								 //       O
								 //    T1   
								 //	  T2
	                             // ---------------
	temp1->setRight(original);   // Sets the right of temp1 to original.
	original->setLeft(temp2);    // Sets the left of original to temp2.
				     // The final result moves the original node as shown below.
								 //       T1
								 //		O
								 //       t2
								 // ---------------
	temp1->setHeight(max(temp1->getLeft()->getHeight(), temp1->getRight()->getHeight())+1);
	original->setHeight(max(original->getLeft()->getHeight(), original->getRight()->getHeight())+1);

	return temp1;
}

Node *AVL::LL(Node *original)
{
	Node *temp1 = new Node;
	Node *temp2 = new Node;

	temp1 = original->getRight(); // Sets temp1 as right of original node.
	temp2 = temp1->getLeft();     // Sets temp2 as the left of temp1.
								  //       O
								  //         T1
								  //	  T2
								  // ---------------
	temp1->setLeft(original);     // Sets the left of temp1 to original.
	original->setRight(temp2);    // Sets the right of original to temp2.
				      // The final result moves the original node as shown below.
								  //       T1
								  //	O
								  //       t2
								  // ---------------
	
	// Resets the height value of the repositioned nodes.
	
	original->setHeight(max(original->getLeft()->getHeight(), original->getRight()->getHeight()) + 1);
	temp1->setHeight(max(temp1->getLeft()->getHeight(), temp1->getRight()->getHeight()) + 1);

	return temp1;
}

// Double-rotation functions.

Node *AVL::LR(Node *original)
{
	RR(original->getLeft());
	LL(original);
	return original;
}

Node *AVL::RL(Node *original)
{
	LL(original->getRight());
	RR(original);
	return original;
}

/*===================================================
// Insertion functions.                             */

void AVL::insertNode()
/* The AVL node insertion override of the base BT insertion function. */
{
	if (maxNodes >= totalTreeNodes)
	{
		int randomKey;

		//do
		//{
			randomKey = rand() % 10000;
		//} while (searchTree(randomKey) == false);

		int depth = 0;
		insertHelper(root, depth, randomKey);
		incrementNodes();
		addDepth(depth);
	}
}

void AVL::insertHelper(Node *root, int& depth, int keyValue)
/* Recursive helper function of insertNode. */
{
	depth++;
	
	if (root->getKey() > keyValue)
	{
		if (root->getLeft() == nullptr)
		{
			// Create node immediately if no child exists on left.
			Node *temp = new Node(keyValue, rand() % 10000);
			root->setLeft(temp);
		}
		else
		{
			// Recursive call; compare key against existing left subtree node.
			root->incrementHeight();
			insertHelper(root->getLeft(), depth, keyValue);
		}
	}
	else	// Attempts to create a node on the right if child key > root key.
	{
		if (root->getRight() == nullptr)
		{
			Node *temp = new Node(keyValue, rand() % 10000);
			root->setRight(temp);
		}
		else
		{
			root->incrementHeight();
			insertHelper(root->getRight(), depth, keyValue);
		}
	}
	
	// Rotation algorithms.

	int balance = root->getHeight() - root->getHeight();
	
	// Note: height balancing here is erratically implemented.
	
	if (balance > 1 && root->getKey() < root->getLeft()->getKey())
	{
		RR(root);
		return;
	}

	if (balance < -1 && root->getKey() > root->getRight()->getKey())
	{
		LL(root);
		return;
	}

	if (balance > 1 && root->getKey() > root->getLeft()->getKey())
	{
		LR(root);
		return;
	}
	
	if (balance < -1 && root->getKey() < root->getRight()->getKey())
	{
		RL(root);
		return;
	}
}

AVL::~AVL()
{
	removeTree(root);
	root = nullptr;
}
