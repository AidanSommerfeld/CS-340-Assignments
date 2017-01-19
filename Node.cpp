#include "node.h"
using namespace std;

//CONSTRUCTORS
Node::Node()
{
	key = 0;
	value = 0;
	left = nullptr;
	right = nullptr;
	leftHeight = 0;
	rightHeight = 0;
}
Node::Node(int newKey, int newValue)
{
	key = newKey;
	value = newValue;
	left = nullptr;
	right = nullptr;
	leftHeight = 0;
	rightHeight = 0;
}
//SET INTERNAL VALUES//
void Node::setKey(int newKey)
{
	key = newKey;
}
void Node::setValue(int newValue)
{
	value = newValue;
}
//GET INTERNAL VALUES//
int Node::getKey()
{
	return key;
}
int Node::getValue()
{
	return value;
}
//AVL ONLY FUNCTIONS//////////////////////////

//GET HEIGHTS//
int Node::getLeftHeight()
{
	return leftHeight;
}
int Node::getRightHeight()
{
	return rightHeight;
}
void Node::incrementLeftHeight()
{
	leftHeight++;
}
void Node::incrementRightHeight()
{
	rightHeight++;
}
//////////////////////////////////////////////
//SET CHILDREN//
void Node::setLeft(Node* newNode)   // calls default / init constructor?
{
	left = newNode;
}
void Node::setRight(Node* newNode)  // could be omiited if BT class is friend class?
{
	right = newNode;
}
//GET CHILDREN//
Node* Node::getLeft()
{
	return left;
}

Node* Node::getRight()
{
	return right;
}
void Node::operator= (Node* node2)
{
	left = node2->getLeft();
	right = node2->getRight();
	key = node2->getKey();
	value = node2->getValue();
	leftHeight = node2->getLeftHeight();
	rightHeight = node2->getLeftHeight();
}
//DESTRUCTOR//
Node::~Node()           //deletes all values in the node
{				        // Recursively called by BT destructor? NPost-order traversal

}
