#include "node.h"

using namespace std;

// ----------------------------------------
// Constructors for nodes.

Node::Node()
/* Default constructor. */
{
	key = 0;
	value = 0;

	left = nullptr;
	right = nullptr;

	leftHeight = 0;
	rightHeight = 0;
}

Node::Node(int newKey, int newValue)
/* Initializing constructor. */
{
	key = newKey;
	value = newValue;
	
	left = nullptr;
	right = nullptr;
	
	leftHeight = 0;
	rightHeight = 0;
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

// ----------------------------------------
// AVL tree-specific operations.

// Height operations.
int Node::getLeftHeight()
{
	return leftHeight;
}

int Node::getRightHeight()
{
	return rightHeight;
}

void Node::setLeftHeight(int num)
{
	leftHeight = num;
}

void Node::setRightHeight(int num)
{
	rightHeight = num;
}

void Node::incrementLeftHeight()
{
	leftHeight++;
}

void Node::incrementRightHeight()
{
	rightHeight++;
}

void Node::operator= (Node* node2)
/* An operator overload to expedite AVL rotations. */
{
	left = node2->getLeft();
	right = node2->getRight();
	key = node2->getKey();
	value = node2->getValue();
	leftHeight = node2->getLeftHeight();
	rightHeight = node2->getLeftHeight();
}

Node::~Node()   
/* What are we doing with this? 
   It seems like the BT destructor is doing the job... */
{			        
}
