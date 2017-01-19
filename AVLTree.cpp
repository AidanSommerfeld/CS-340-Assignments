#include "AVLTree.h"
using namespace std;

void AVL::printHelper(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	printHelper(root->getLeft());
	printHelper(root->getRight());
	cout << root->getKey() << endl;
}

void AVL::printTree()
{
	cout << "Depth: " << totalTreeDepth << " Node number:" << totalTreeNodes << endl;
	printHelper(root);
}

AVL::AVL()
{
	cout << "begin" << endl;
	root->setKey(rand() % 10);
	cout << "Set a key" << endl;
	root->setValue(rand() % 10000);
	cout << "Set a value" << endl;
	totalTreeDepth = 0;
	totalTreeNodes = 1;
	maxNodes = 100000;	               //arbitrary number since the user is obligated to enter a number this value should never be hit (unless of course the user chooses 1)
}



AVL::AVL(int nodes)
{
	root->setKey(rand() % 10);
	root->setValue(rand() % 10000);
	totalTreeDepth = 0;
	totalTreeNodes = 1;
	maxNodes = nodes;
}



void AVL::addDepth(int nodeDepth)
{
	totalTreeDepth += nodeDepth;
}



void AVL::incrementNodes()
{
	totalTreeNodes++;
}



int AVL::getTreeDepth()
{
	return totalTreeDepth;
}



int AVL::getTreeNodes()
{
	return totalTreeNodes;
}



void AVL::randomHelper(Node* root, int& depth)
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



void AVL::insertRandomNode()
{
	if (maxNodes > totalTreeNodes)
	{
		int depth = 0;
		randomHelper(root, depth);
		incrementNodes();
		addDepth(depth);
	}
}



void AVL::removeTree(Node* root)

{
	if (root == nullptr)
	{
		return;
	}
	removeTree(root->getLeft());
	removeTree(root->getRight());
	delete root;
}



AVL::~AVL()

{
	removeTree(root);
	root = nullptr;
}
