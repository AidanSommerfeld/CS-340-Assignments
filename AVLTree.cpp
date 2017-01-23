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
{
	if (a > b)
		return a;
	else
		return b;
}

// Rotation functions.

Node *AVL::RR(Node *original)
{
	Node *temp1 = new Node;
	Node *temp2 = new Node;

	temp1 = original->getLeft(); //sets temp 1 as left of original
	temp2 = temp1->getRight();   // sets temp 2 as the right of original
								 //       O
								 //    T1   
								 //		  T2
	                             // ---------------
	temp1->setRight(original);   //sets the right of temp 1 to original
	original->setLeft(temp2);	 //sets the left of original to temp 2
								 //       T1
								 //			  O
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

	temp1 = original->getRight(); //sets temp 1 as right of original
	temp2 = temp1->getLeft();     // sets temp 2 as the left of temp 1
								  //       O
								  //         T1
								  //	  T2
								  // ---------------
	temp1->setLeft(original);     //sets the left of temp 1 to original
	original->setRight(temp2);	  //sets the right of original to temp 2
								  //       T1
								  //	O
								  //       t2
								  // ---------------
	original->setHeight(max(original->getLeft()->getHeight(), original->getRight()->getHeight()) + 1);
	temp1->setHeight(max(temp1->getLeft()->getHeight(), temp1->getRight()->getHeight()) + 1);

	return temp1;
}
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
/////////////////////////////
void AVL::insertHelper(Node *root, int& depth, int keyValue)
{
	depth++;
	if (root->getKey() > keyValue)
	{
		if (root->getLeft() == nullptr)
		{
			Node *temp = new Node(keyValue, rand() % 10000);
			root->setLeft(temp);
		}
		else
		{
			root->incrementHeight();
			insertHelper(root->getLeft(), depth, keyValue);
		}
	}
	else
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


	int balance = root->getHeight() - root->getHeight();
	
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



void AVL::insertNode()
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


AVL::~AVL()

{
	removeTree(root);
	root = nullptr;
}
