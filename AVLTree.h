#ifndef AVLTREE_H
#define AVLTREE_H
#include "node.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class AVL
{
private:
	int maxNodes;

	Node* root = new Node;
	int totalTreeDepth;
	int totalTreeNodes;
	
public:
	AVL();
	AVL(int nodes);
	~AVL();

	void addDepth(int nodeDepth);
	void incrementNodes();
	
	int calculateHelper(Node* root, int depth);
	void calculateDepth();

	void printHelper(Node* root);
	void printTree();

	bool searchHelper(Node*root, bool& found, int num);
	bool searchTree(int num);

	int getTreeDepth();
	int getTreeNodes();

	int max(int a, int b);

	void insertRandomNode();
	void randomHelper(Node* root, int &depth, int keyValue);

	Node* RR(Node* original);
	Node* LL(Node* original);
	Node* LR(Node* original);
	Node* RL(Node* original);


	void removeTree(Node* root);
};
#endif
