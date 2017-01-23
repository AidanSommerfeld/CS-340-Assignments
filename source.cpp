// ======================================================================
// Binary Tree Generation
/* ======================================================================
// Authors:
// STNO#(s):
//                                                                     */
// =====================================================================
/* Class:  CS 340
// For: Assignment #1
// Date: January 23, 2017                                             */
// ======================================================================
/* Purpose: The main executable file for a process that generates
//			several types of binary trees to experimentally 
//			average and compare their depth. 
//
// Algorithm / Process:
//
//			Creates x dynamically-allocated trees with y nodes. 
//			During program operation, two counters are given to track 
//			the number of total nodes created in a process, as well as
//			the cumulative depth of all nodes that have been allocated.
//
//			These counters are fields in the binary tree classes. Before
//			a new tree is generated, these counters are added to an overall
//			cumulative counter before the current tree is de-allocated --
//			then a new tree is generated until the target number of trees 
//			is built.
//
// Major Variables and Constants:
//
// ======================================================================*/

#include <iostream>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "node.h"
#include <stdlib.h>
#include <ctime>
using namespace std;

void binaryTree(float& totalNodeCount, float& totalDepthCount, int nodeNumber);
void avlTree(float& totalNodeCount, float& totalDepthCount, int nodeNumber);
void bsTree(float& totalNodeCount, float& totalDepthCount, int nodeNumber);

int main()
{
	char quit;
	do
	{
		srand(time(0));
		float totalNodeCount = 0;
		float totalDepthCount = 0;
		float average = 0;
		int treeNumber;
		int nodeNumber;
		int frequency;
		char treeType;

		cout << "What kind of tree would you like to implement? " << endl
			<< "'a' BT" << endl
			<< "'b' AVL " << endl
			<< "'c' BST " << endl << "Tree type: ";
		do
		{
			cin >> treeType;
		} while (treeType != 'a' && treeType != 'b' && treeType != 'c'
			&& treeType != 'A' && treeType != 'B' && treeType != 'C');

		cout << "How many trees would you like to test: ";
		cin >> treeNumber;
		cout << "How many nodes will be in each tree: ";
		cin >> nodeNumber;
		do
		{
			cout << "please enter a print frequency: ";
			cin >> frequency;
			if (frequency < 1)
			{
				cout << "The frequency must be 1 or greater." << endl;
			}
		} while (frequency < 1);

		for (int i = 1; i <= treeNumber; i++)
		{

			if (treeType == 'a' || treeType == 'A')
			{
				binaryTree(totalNodeCount, totalDepthCount, nodeNumber);
			}

			if (treeType == 'b' || treeType == 'B')
			{
				avlTree(totalNodeCount, totalDepthCount, nodeNumber);
			}
			if (treeType == 'c' || treeType == 'C')
			{
				bsTree(totalNodeCount, totalDepthCount, nodeNumber);
			}


			if (i % frequency == 0)
			{
				cout << '.';
			}
			if (i % (frequency * 10) == 0)
			{
				cout << endl;
			}
		}
		cout << endl;
		average = totalDepthCount / totalNodeCount;

		cout << "The average depth of this tree is: " << average << endl;
		cout << "The total number of nodes was: " << fixed << totalNodeCount << " The total depth was: " << fixed << totalDepthCount << endl << endl;
		cout << "Would you like to quit? (Y/N): ";
		
		do {
			cin >> quit;
		} while (quit != 'y' && quit != 'Y' && quit != 'n' && quit != 'N');

	} while (quit == 'n' || quit == 'N');
	return 0;
}

void binaryTree(float& totalNodeCount, float& totalDepthCount, int nodeNumber)
{
	BT* tree = new BT(nodeNumber);

	for (int j = 0; j < nodeNumber - 1; j++)
	{
		tree->insertRandomNode();
	}
	tree->calculateDepth();
	totalNodeCount += tree->getTreeNodes();
	totalDepthCount += tree->getTreeDepth();
	delete tree;
}

void avlTree(float& totalNodeCount, float& totalDepthCount, int nodeNumber)
{
	AVL* tree = new AVL(nodeNumber);

	for (int j = 0; j < nodeNumber - 1; j++)
	{
		tree->insertRandomNode();
	}
	tree->calculateDepth();
	totalNodeCount += tree->getTreeNodes();
	totalDepthCount += tree->getTreeDepth();
	delete tree;
}

void bsTree(float& totalNodeCount, float& totalDepthCount, int nodeNumber)
{
	BST* tree = new BST(nodeNumber);

	for (int j = 0; j < nodeNumber - 1; j++)
	{
		tree->insertRandomNode();
	}
	tree->calculateDepth();
	totalNodeCount += tree->getTreeNodes();
	totalDepthCount += tree->getTreeDepth();
	delete tree;
}
