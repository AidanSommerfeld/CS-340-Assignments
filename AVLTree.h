#ifndef AVLTREE_H
#define AVLTREE_H
#include "node.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class AVL
{
private:
	Node* root = new Node;

	int totalTreeDepth;
	int totalTreeNodes;
	int maxNodes;
public:
	AVL();
	AVL(int nodes);
	~AVL();

	void addDepth(int nodeDepth);
	void incrementNodes();

	void printHelper(Node* root);
	void printTree();

	int getTreeDepth();
	int getTreeNodes();


	void insertRandomNode();
	void randomHelper(Node* root, int &depth);


	void removeTree(Node* root);
};
#endif
