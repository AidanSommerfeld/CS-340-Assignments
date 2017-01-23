#include "BinaryTree.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
int BT::calculateHelper(Node* root, int depth)
{

	if (root == nullptr)
	{
		return 0;
	}
	int left = calculateHelper(root->getLeft(), depth + 1);
	int right = calculateHelper(root->getRight(), depth + 1);

	return depth + left + right;
}

void BT::calculateDepth()
{
	int depth = 0;
	totalTreeDepth = calculateHelper(root, depth);
}

void BT::printHelper(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	printHelper(root->getLeft());
	printHelper(root->getRight());

	cout << root->getKey() << endl;
}
void BT::printTree()
{
	cout << "Depth: " << totalTreeDepth << " Node number:" << totalTreeNodes << endl;
	printHelper(root);
}
BT::BT()
{
	root->setKey(rand() % 10);
	root->setValue(rand() % 10000);
	totalTreeDepth = 0;
	totalTreeNodes = 1;
	maxNodes = 100000;	               //arbitrary number since the user is obligated to enter a number this value should never be hit (unless of course the user chooses it)
}

BT::BT(int nodes)
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

void BT::randomHelper(Node* root, int& depth)
{
	depth++;

	int decide = rand() % 2;

	if (decide == 0)
	{
		if (root->getLeft() == nullptr)
		{
			Node* temp = new Node;
			temp->setKey(rand() % 10);
			temp->setValue(rand() % 10000);
			temp->setLeft(nullptr);
			temp->setRight(nullptr);
			root->setLeft(temp);
		}
		else
		{
			randomHelper(root->getLeft(), depth);
		}
	}
	else
	{
		if (root->getRight() == nullptr)
		{
			Node* temp = new Node;
			temp->setKey(rand() % 10);
			temp->setValue(rand() % 10000);
			temp->setLeft(nullptr);
			temp->setRight(nullptr);
			root->setRight(temp);
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
		randomHelper(root, depth);
		incrementNodes();
		addDepth(depth);
	}
}

void BT::removeTree(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	removeTree(root->getLeft());
	removeTree(root->getRight());
	delete root;

}

BT::~BT()
{
	removeTree(root);
	root = nullptr;
}
