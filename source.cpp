#include <iostream>
#include "BinaryTree.h"
#include "node.h"
#include <stdlib.h>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	float totalNodeCount = 0;
	float totalDepthCount = 0;
	float average = 0;
	int treeNumber;
	int nodeNumber;
	int frequency;

	cout << "How many trees would you like to test: ";
	cin >> treeNumber;
	cout << "How many nodes will be in each tree: ";
	cin >> nodeNumber;
	cout << "please enter a print frequency: ";
	cin >> frequency;
	nodeNumber--;

	for (int i = 0; i < treeNumber; i++)
	{

		BT* tree = new BT;

		for (int j = 0; j < nodeNumber; j++)
		{
			tree->insertRandomNode();
		}
		totalNodeCount += tree->getTreeNodes();
		totalDepthCount += tree->getTreeDepth();
		delete tree;
		if (i % frequency == 0)
		{
			cout << '.';
		}
		if (i % (frequency * 10) == 0 )
		{
			cout << endl;
		}
	}
	cout << endl;
	average = totalDepthCount / totalNodeCount;

	cout << "The average depth of this tree is: " << average << endl;
	cout << "The total number of nodes was: " << fixed << totalNodeCount << " The total depth was: "  << fixed << totalDepthCount << endl;
	return 0;
}
