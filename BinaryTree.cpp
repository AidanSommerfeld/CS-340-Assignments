#include <iostream>
#include <ctime>
#include <cstdlib>

#include "BinaryTree.h"

using std::cout;
using std::endl;

BT::BT()
/* Default constructor. */
{
	root->setKey(rand() % 10);
	root->setValue(rand() % 10000);
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

void BT::insertNode()
/* Adds nodes to the tree until target # of nodes is reached. */
{
	if (maxNodes > totalTreeNodes)
	{
		int depth = 0;
		insertHelper(root, depth);
		incrementNodes();
		addDepth(depth);
	}
}

void BT::insertHelper(Node *root, int &depth)
/* Recursive insertion helper of insertNode(). */
{
	depth++; // ?? May need to review implementation...

	// To reiterate: binary trees have no rules on adding nodes,
	// so here we simply randomize the choice. 
	// 0 adds the node to the left subtree; 1 to the right.

	int decide = rand() % 2;

	if (decide == 0) // Goes left.
	{
		if (root->getLeft() == nullptr)	// If no subtree currently exists...
		{
			Node *temp = new Node(rand() % 10, rand() % 10000);

			// Binary trees don't care about keys or values,
			// so these are arbitrarily set here.

			// Initializes the new node as a subtree of its parent.

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
			Node *temp = new Node(rand() % 10, rand() % 10000);
			root->setRight(temp);

			addDepth(depth);
		}
		else
		{
			insertHelper(root->getRight(), depth);
		}
	}
}

void BT::addDepth(int nodeDepth)
{
	totalTreeDepth += nodeDepth;
}

void BT::printTree()
{
	cout << "Depth: " << totalTreeDepth << '\n'
		 << "Node number:" << totalTreeNodes << endl;

	printHelper(root);
}

void BT::printHelper(Node *root)
/* Post-order traversal. Prints from the bottom up. */
{
	if (root == nullptr)
		return;

	printHelper(root->getLeft());
	printHelper(root->getRight());

	cout << root->getKey() << endl;
}

void BT::calculateDepth()
{
	int depth = 0;
	totalTreeDepth = calculateHelper(root, depth);
}

int BT::calculateHelper(Node *root, int depth)
{
	// Recursive helper. Recursively increments depth
	// until a leaf node is reached.

	if (root == nullptr)
		return 0;

	int left = calculateHelper(root->getLeft(), depth + 1);
	int right = calculateHelper(root->getRight(), depth + 1);

	return depth + left + right;
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

void BT::removeTree(Node *root)
/* Post-order deletion. Root MUST go last. */
{
	if (root == nullptr)
		return;

	// As a note: if we deleted any non-root node
	// this would delete all of its children underneath.
	// In practice only the destructor calls this, though.

	removeTree(root->getLeft());
	removeTree(root->getRight());
	delete root;

}

BT::~BT()
{
	removeTree(root);
	root = nullptr;
}
