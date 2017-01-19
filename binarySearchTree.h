/*===================================================
BinarySearchTree.h
=====================================================

A header defining a binary search tree class.

Nodes are appended by key. Any new node added to
the tree is compared against the key of the root:
left if lower than; right if greater than.

If no node exists where a node travels, it becomes
appended as the child node; else, the node's key
is compared against the next node in the branch
and the process repeats.

BST is a derived class of BT and provides
an overload for node insertion.
===================================================*/

#ifndef BIN_SEARCH_H
#define BIN_SEARCH_H

#include "node.h"
#include "binaryTree.h"

#include <iostream>
#include <cstdlib>

class BST : public BT
{
	public: 

		BST();
		BST(int nodes);
		~BST();

		void insertNode();
		void insertHelper(Node* root, int& depth);

		// These functions are called by the 
		// BST insertion algorithm.

		void find();
		void findMin();
		void findMax();
};

#endif
