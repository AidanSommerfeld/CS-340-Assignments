/*==========================================
Node.cpp

Implementation file of the Node header.
==========================================*/

#include "Node.h"

// ----------------------------------------
// Constructors for nodes.

Node::Node()
/* Default constructor. */
{
	key = 0;
	value = 0;

	left = nullptr;
	right = nullptr;

	height = 0;
}

Node::Node(int newKey, int newValue)
/* Initializing constructor. */
{
	key = newKey;
	value = newValue;
	
	left = nullptr;
	right = nullptr;
	
	height = 0;
}

// ----------------------------------------
// Internal value setters.

void Node::setKey(int newKey)
{
	key = newKey;
}

void Node::setValue(int newValue)
{
	value = newValue;
}

// ----------------------------------------
// Functions returning private data fields.

int Node::getKey()
{
	return key;
}

int Node::getValue()
{
	return value;
}

// ----------------------------------------
// Subtree operations. 

void Node::setLeft(Node *newNode)   
{
	left = newNode;
}

void Node::setRight(Node *newNode)  
{
	right = newNode;
}


Node *Node::getLeft()
{
	return left;
}

Node *Node::getRight()
{
	return right;
}

// ----------------------------------------
// AVL tree-specific operations.

int Node::getHeight()
{
	return height;
}

void Node::setHeight(int num)
{
	height = num;
}

void Node::incrementHeight()
{
	height++;
}

void Node::operator= (Node *node2)
/* An operator overload to expedite AVL rotations. */
{
	left = node2->getLeft();
	right = node2->getRight();
	key = node2->getKey();
	value = node2->getValue();
	height = node2->getHeight();
}

Node::~Node()   
/* What are we doing with this? 
   It seems like the BT destructor is doing the job... */
{			        
}
