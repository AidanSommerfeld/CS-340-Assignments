#include <iostream>
#include <ctime>
#include <cstdlib>

#include "BinaryTree.h"

using namespace std;

BT::BT()
/* Default constructor. */
{
	root->setKey(rand() % 10);
	cout << "Key set for root node." << endl;
	root->setValue(rand() % 10000);
	cout << "Value set for root node." << endl;
	totalTreeDepth = 0;
	totalTreeNodes = 1;

	// This is arbitrary. Program design calls for the user to enter a value anyway,
	// and besides for most purposes the initializing constructor will be used.
	maxNodes = 100000;
}

BT::BT(int nodes)
/* Initializing constructor, given a user input.*/
{
	root->setKey(rand() % 10);
	root->setValue(rand() % 10000);

	totalTreeDepth = 0;
	totalTreeNodes = 1;

	maxNodes = nodes;
}

void BT::addDepth(int nodeDepth)
{
	totalTreeDepth += nodeDepth;
}

void BT::incrementNodes()
{
	totalTreeNodes++;
}

int BT::getTreeDepth()
{
	return totalTreeDepth;
}

int BT::getTreeNodes()
{
	return totalTreeNodes;
}

void BT::insertNode()
/* Adds nodes to the tree until target # of nodes is reached. */
{
	if (maxNodes > totalTreeNodes)
	{
		int depth = 0;
		insertHelper(root, depth);
		incrementNodes();
	}
}

void BT::insertHelper(Node* root, int& depth)
/* Recursive insertion helper of insertNode(). */
{
	depth++; // ?? May need to look into this.

	// To reiterate: binary trees have no rules on adding nodes,
	// so here we simply randomize the choice. 
	// 0 adds the node to the left subtree; 1 to the right.

	int decide = rand() % 2;

	if (decide == 0) // Goes left.
	{
		if (root->getLeft() == nullptr)	// If no subtree currently exists...
		{
			Node* temp = new Node;

			// Binary trees don't care about keys or values,
			// so these are arbitrarily set here and make no
			// difference in the insertion process.

			temp->setKey(rand() % 10);
			temp->setValue(rand() % 10000);

			// Initializes the new node as a subtree of its parent.

			temp->setLeft(nullptr);
			temp->setRight(nullptr);
			root->setLeft(temp);

			// Returns the depth of the current node to the depth accumulator.

			addDepth(depth);
		}        
		else                            
		{	
			// Otherwise recursively call the function and 
			// branch down to the existing node.
			// Repeat until an open subtree is found.
			insertHelper(root->getLeft(), depth);
		}
	}
	else // Goes right. Logic is the same; see above.
	{
		if (root->getRight() == nullptr)
		{
			Node* temp = new Node;

			temp->setKey(rand() % 10);
			temp->setValue(rand() % 10000);

			temp->setLeft(nullptr);
			temp->setRight(nullptr);
			root->setRight(temp);

			addDepth(depth);
		}
		else
		{
			insertHelper(root->getRight(), depth);
		}
	}
}

void BT::removeNode(Node* root)
/* Post-order deletion. Root MUST go last. */
{
	if (root == nullptr)
		return;

	// As a note: if we deleted any non-root node
	// this would delete all of its children underneath.
	// In practice only the destructor calls this, though.

	removeNode(root->getLeft());
	removeNode(root->getRight());
	delete root;

}

void BT::printTree()
{
	cout << "Depth: " << totalTreeDepth << '\n'
		<< "Node number:" << totalTreeNodes << endl;

	printHelper(root);
}

void BT::printHelper(Node* root)
/* Post-order traversal. Prints from the bottom up. */
{
	if (root == nullptr)
		return;

	printHelper(root->getLeft());
	printHelper(root->getRight());

	cout << root->getKey() << endl;
}


BT::~BT()
{
	removeNode(root);
	root = nullptr;
}
