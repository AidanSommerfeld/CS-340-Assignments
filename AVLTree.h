/*===================================================
AVLTree.h
=====================================================

A header defining an AVL tree class.

Nodes are appended by key in the same method as 
a binary search tree.

The identifying property of an AVL tree is that
it maintains no more than a height difference
of 1 between left and right subtrees, using
"rotations" to retain this after nodes are added.

AVL is a derived class of BT and provides
an overload for node insertion.
===================================================*/

#ifndef AVLTREE_H
#define AVLTREE_H

#include "Node.h"
#include "BinaryTree.h"

#include <iostream>
#include <cstdlib>


class AVL : public BT
{

public:

	AVL();
	AVL(int nodes);
	~AVL();

	// Searches the tree for a specified key.
	
	bool searchTree(int num);
	bool searchHelper(Node *root, bool &found, int num);

	// Used for balancing / insertion.

	int max(int a, int b);

	void insertNode();
	void insertHelper(Node *root, int &depth, int keyValue);

	// Functions for AVL rotations.

	Node *RR(Node *original);
	Node *LL(Node *original);
	Node *LR(Node *original);
	Node *RL(Node *original);

	/*The following functions are inherited from
	class BT with no overrides or overloads:

	void addDepth(int nodeDepth);
	void incrementNodes();

	void calculateDepth();
	int calculateHelper(Node *root, int depth);

	void printTree();
	void printHelper(Node *root);

	int getTreeDepth();
	int getTreeNodes();

	void removeTree(Node *root);
	*/
};

#endif
