#include "node.h"
using namespace std;


Node::Node()
{
	key = 0;
	value = 0;
	left = 0;
	right = 0;
}
Node::Node(int newKey, int newValue)
{
	key = newKey;
	value = newValue;
	left = 0;
	right = 0;
}

void Node::setKey(int newKey)
{
	key = newKey;
}
void Node::setValue(int newValue)
{
	value = newValue;
}

int Node::getKey()
{
	return key;
}
int Node::getValue()
{
	return value;
}

void Node::setLeft(Node* newNode)   // calls default / init constructor?
{
	left = newNode;
}
void Node::setRight(Node* newNode)  // could be omiited if BT class is friend class?
{
	right = newNode;
}

Node* Node::getLeft()
{
	return left;
}

Node* Node::getRight()
{
	return right;
}

Node::~Node()           //deletes all values in the node
{				        // Recursively called by BT destructor? NPost-order traversal
	delete left;
	delete right;
}
