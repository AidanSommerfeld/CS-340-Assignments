#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "node.h"
class BT
{
public:
	BT();
	BT(int nodes);
	void insertRandomNode();
	void randomHelper(Node* root, int &depth);

	void addDepth(int nodeDepth);
	void incrementNodes();

	int getTreeDepth();
	int getTreeNodes();
	void removeTree(Node* root);
	~BT();


private:
	Node* root = new Node;
	int totalTreeDepth;
	int totalTreeNodes;
	int maxNodes;
};
#endif
