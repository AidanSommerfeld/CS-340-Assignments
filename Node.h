/*===================================================
Node.h
=====================================================

A header defining a class for nodes that 
compose a binary tree.

All binary tree headers will refer to this 
class definition header.

class Node is a recyclable class. While 
binary trees have no need for the key 
and value fields, binary search trees and AVL
trees are heavily reliant on these fields
for rebalancing.
===================================================*/

#ifndef NODE_H
#define NODE_H

class Node
{

	private:

		Node* leftBranch;
		Node* rightBranch;

		int key;		// Determines the branching of a node.
		int value;		// Arbitrary value container.
	
		int leftHeight;           //NOTE:
		int rightHeight;          // These values are only used for AVL trees

	public:

	// Default & initializing constructors.

		Node();
		Node(int newKey, int newValue);

	// Destructor. Should be called recursively by any binary tree destructor.

		~Node();

	// Getter & setter functions.

		void setKey(int newKey);
		void setValue(int newValue);

		int getKey();
		int getValue();
	
	//AVL ONLY FUNCTIONS//
		int getLeftHeight();
		int getRightHeight();
		void incrementLeftHeight();
		void incrementRightHeight();
	///////////////////////


	// Initializes branch nodes of a root. 
	// Note that any branch node is its own root, so this should call a Node() constructor.
	
	// Dev note: could we omit these if class BT was a friend class to class Node?

		void setLeft(Node* newNode);    
		void setRight(Node* newNode);  
		
		
	// Returns the address of any branches. These should return some invalid value if uninitialized.

		Node* getLeft();
		Node* getRight();
	
	//Operator is for the easy implementation of rotation in avl
		void operator= (Node* node2);
};

#endif
