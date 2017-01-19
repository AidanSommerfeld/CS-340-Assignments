/*===================================================
BinaryTree.h
=====================================================

A header defining a binary tree class.

There are no rules as to appending new nodes
to basic binary trees. Hence, nodes are arbitrarily
(or, specifically, randomly) added to the tree
in this implementation

Classes BST and AVL are derived from this class.
===================================================*/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "node.h"

class BT
{
	// So class BST and AVL can inherit these.
	
	protected:

		// Roots need to be explicitly dynamic here so any tree instance
		// can likewise be de-allocated without issue.

		Node* root = new Node;

		// The following values are used for experimental statistic verification.

		// totalTreeDepth is the sum of the depth values assigned to each and every node.
		// totalTreeNodes is the number of nodes currently being allocated for a tree.
		// Hence, the average depth of a tree is taken as depth / nodes.

		// maxNodes defines the maximum number of nodes to be built for a tree
		// before it is de-allocated and a new tree is generated. 
		
		// The average depth of a tree is added to a running 
		// total in the main function before it is de-allocated
		// and a new tree is rebuilt.

		int totalTreeDepth;
		int totalTreeNodes;
		int maxNodes;

	public:

	// Constructors, destructor.

		BT();
		BT(int nodes);

		~BT();

	// Node insertion. Has a recursive helper function.
	
		void insertNode();
		void insertHelper(Node* root, int &depth);

	// Functions to calculate or return tree statistics.
	
	// addDepth adds the depth of a node to the running total.

		void addDepth(int nodeDepth);
		void incrementNodes(); 

		int getTreeDepth();
		int getTreeNodes();

		void removeNode(Node* root);		
	
};

#endif
