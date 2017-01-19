#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <cstdlib>

#include "node.h"
#include "binaryTree.h"

using namespace std;

class AVL : public BT
{

/* If we make the member variables protected in BinaryTree.h this should work fine.

protected:

	Node* root = new Node;

	int totalTreeDepth;
	int totalTreeNodes;
	int maxNodes;
	
*/
	
public:
	AVL();
	AVL(int nodes);
	~AVL();	

	void printHelper(Node* root);
	void printTree();
	
	// void addDepth(int nodeDepth);
	// void incrementNodes(); 

	// int getTreeDepth();
	// int getTreeNodes();
	
	// If you see this, just a note that I'm
	// probably going to rename the insert function 
	// BinaryTree.h this exact way so it can be 
	// inherited and then overrode. IIRC
	// there's no need to declare an inherited function,
	// but you can define an override straight-up in 
	// the module.

	void insertNode();
	void insertHelper(Node* root, int &depth);

	// void removeTree(Node* root);
};

#endif
