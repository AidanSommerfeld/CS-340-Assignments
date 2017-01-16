#ifndef NODE_H
#define NODE_H
class Node
{
private:

	Node* left;
	Node* right;
	int key;
	int value;

public:
	Node();
	Node(int newKey, int newValue);

	void setKey(int newKey);
	void setValue(int newValue);

	int getKey();
	int getValue(); 

	void setLeft(Node* newNode);    // calls default / init constructor?
	void setRight(Node* newNode);   // could be omiited if BT class is friend class?
	Node* getLeft();
	Node* getRight();

	~Node();           //deletes all values in the node
	                   // Recursively called by BT destructor? NPost-order traversal
};
#endif
