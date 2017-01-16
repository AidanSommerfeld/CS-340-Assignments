#include "BinaryTree.h"
#include <ctime>
#include <stdlib.h>
using namespace std;
BT::BT()
{
	root.setKey(rand() % 10);
	root.setValue(rand() % 10000);
	totalTreeDepth = 0;
	totalTreeNodes = 1;
	maxNodes = 1;	               //arbitrary number since the user is obligated to enter a number this value should never be hit (unless of course the user chooses 1)
}

BT::BT(int nodes)
{
	root.setKey(rand() % 10);
	root.setValue(rand() % 10000);
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

void BT::randomHelper(Node* root, int& depth)
{
	depth++;

	int decide = rand() % 2;

	if (decide == 0)
	{
		if (root->getLeft() == 0)
		{
			Node* temp = new Node;
			temp->setKey(rand() % 10);
			temp->setValue(rand() % 10000);
			root->setLeft(temp);
			delete temp;
			addDepth(depth);
		}
		else
		{
			randomHelper(root->getLeft(), depth);
		}
	}
	else
	{
		if (root->getRight() == 0)
		{
			Node* temp = new Node;
			temp->setKey(rand() % 10);
			temp->setValue(rand() % 10000);
			root->setRight(temp);
			delete temp;
			addDepth(depth);
		}
		else
		{
			randomHelper(root->getRight(), depth);
		}
	}
}

void BT::insertRandomNode()
{
	if (maxNodes > totalTreeNodes)
	{
		int depth = 0;
		randomHelper(&root, depth);
		incrementNodes();
	}
}

void BT::removeTree(Node* root)
{
	if (root->getLeft() != 0)
	{
		removeTree(root->getLeft());
	}
	if (root->getRight() != 0)
	{
		removeTree(root->getRight());
	}

	delete root;

}

BT::~BT()
{
	removeTree(&root);
}
