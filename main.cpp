// =================================================================================
// Topological Sort
/* =================================================================================
// Authors: Aidan Sommerfeld, Rafael Queypo
// STNO#(s): 200362730, 200365586                                    
// =================================================================================
/* Class:  CS 340
// For: Assignment #2
// Date: February 8, 2017                                             
// =================================================================================
/* Purpose: Generates concurrent (i.e., all possible) configurations
//			of partial-order sorts of the vertices of a directed graph.
//
// Algorithm / Process:
//
//			Generates a linked list of vertices designated as "leaders", 
//			with connections to adjacent leader vertices given by 
//			pointers contained by "follower" nodes to a leader.
//
//			To indicate divergent configurations at each step of the path,
//			concurrent vertices branching from one vertex are shown
//			at the same degree / level.
// ===============================================================================*/
#include "topsort.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Integer Test" << endl << endl;
	TopSort ts; 
	cout << endl << endl << endl;

	cout << "Prereq Test" << endl << endl;
	TopSortString tss;
	cout << endl << endl;

	return 0;
}
}
