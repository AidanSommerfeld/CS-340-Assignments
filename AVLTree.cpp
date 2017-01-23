#include "AVLTree.h"
using namespace std;

int AVL::calculateHelper(Node* root, int depth)
{

	if (root == nullptr)
	{
		return 0;
	}
	int left = calculateHelper(root->getLeft(), depth + 1);
	int right = calculateHelper(root->getRight(), depth + 1);

	return depth + left + right;
}

void AVL::calculateDepth()
{
	int depth = 0;
	totalTreeDepth = calculateHelper(root, depth);
}

int AVL::max(int a, int b)
{
	if (a > b)
		return a;

	return b;
}
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
	root->setKey(rand() % 10);
	root->setValue(rand() % 10000);
	totalTreeDepth = 0;
	totalTreeNodes = 1;
	maxNodes = 1;	               //arbitrary number since the user is obligated to enter a number this value should never be hit (unless of course the user chooses 1)
}

bool AVL::searchHelper(Node*root, bool& found, int num)
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
bool AVL::searchTree(int num)
{
	bool found = false;
	searchHelper(root, found, num);
	return found;
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

//ROTATION FUNCTIONS/////////
Node* AVL::RR(Node* original)
{
	Node* temp1 = new Node;
	Node* temp2 = new Node;

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
Node* AVL::LL(Node* original)
{
	Node* temp1 = new Node;
	Node* temp2 = new Node;

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
Node* AVL::LR(Node* original)
{
	RR(original->getLeft());
	LL(original);
	return original;
}
Node* AVL::RL(Node* original)
{
	LL(original->getRight());
	RR(original);
	return original;
}
/////////////////////////////
void AVL::randomHelper(Node* root, int& depth, int keyValue)
{
	depth++;
	if (root->getKey() > keyValue)
	{
		if (root->getLeft() == nullptr)
		{
			Node* temp = new Node(keyValue, rand() % 10000);
			root->setLeft(temp);
		}
		else
		{
			root->incrementHeight();
			randomHelper(root->getLeft(), depth, keyValue);
		}
	}
	else
	{
		if (root->getRight() == nullptr)
		{
			Node* temp = new Node(keyValue, rand() % 10000);
			root->setRight(temp);
		}
		else
		{
			root->incrementHeight();
			randomHelper(root->getRight(), depth, keyValue);
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



void AVL::insertRandomNode()
{
	if (maxNodes >= totalTreeNodes)
	{
		int randomKey;

		//do
		//{
			randomKey = rand() % 10000;
		//} while (searchTree(randomKey) == false);

		int depth = 0;
		randomHelper(root, depth, randomKey);
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
