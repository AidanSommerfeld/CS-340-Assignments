/*===================================================
BinaryTree.h
=====================================================

A header defining a binary tree class.

There are no rules as to appending new nodes
to basic binary trees. Hence, nodes are arbitrarily
(or, specifically, randomly) added to the tree
in this implementation.
===================================================*/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "node.h"

class BT
{
	private:

		Node* root = new Node;	// All binary trees are initialized with a root node.

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
	
		void insertRandomNode();
		void randomHelper(Node* root, int &depth);

	// Functions to calculate or return tree statistics.
	
	// addDepth adds the depth of a node to the running total.

		void addDepth(int nodeDepth);
		void incrementNodes(); 

		int getTreeDepth();
		int getTreeNodes();

		void removeTree(Node* root);		
	
};

#endif
