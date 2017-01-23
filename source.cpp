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
#include <cstdlib>
#include <ctime>

#include "binaryTree.h"
#include "binarySearchTree.h"
#include "AVL.h"
#include "node.h"

using namespace std;

int main()
{
	srand(time(0));

	float totalNodeCount = 0;
	float totalDepthCount = 0;
	float average = 0;

	// Counters for the numbers of trees / nodes built per process.

	int treeNumber;
	int nodeNumber;
	int frequency;

	cout << "How many trees would you like to test: ";
	cin >> treeNumber;
	cout << "How many nodes will be in each tree: ";
	cin >> nodeNumber;
	do
	{
		cout << "please enter a print frequency: ";
		cin >> frequency;
		if(frequency < 1)
		{
			cout << "The frequency must be 1 or greater." << endl;
		}
	} while (frequency < 1);

	for (int i = 0; i < treeNumber; i++)
	{

		BT* tree = new BT;

		for (int j = 0; j < nodeNumber -1; j++)
		{
			tree->insertNode();
		}

		totalNodeCount += tree->getTreeNodes();
		totalDepthCount += tree->getTreeDepth();
		delete tree;

		if (i % frequency == 0)
			cout << '.';
		if (i % (frequency * 10) == 0 && i != 0)
			cout << endl;

	}
	cout << endl;
	average = totalDepthCount / totalNodeCount;

	cout << "The average depth of this tree is: " << average << endl;
	cout << "The total number of nodes built was: " << fixed << totalNodeCount << '\n'
		 << "The total depth was: " << fixed << totalDepthCount << endl;

	return 0;
}
