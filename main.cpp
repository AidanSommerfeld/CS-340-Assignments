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

#include <iostream>
#include <fstream>

#include "TopSort.h"

using std::cout;
using std::endl;

int main()
{
	// TopSort(h*ck, fr*ck); // DO NOT SWEAR IN ACTUAL ASSIGNMENTS SWEARING IS BAD

	int vertexCount = 0;

	/*
	cout << "I'd just like to interject for a moment. What you’re referring to as Linux, is in fact, GNU/Linux, or as I’ve recently taken to "
		<< "calling it, GNU plus Linux. Linux is not an operating system unto itself, but rather another free component of a fully functioning "
		<< "GNU system made useful by the GNU corelibs, shell utilities and vital system components comprising a full OS as defined by POSIX. "
		<< "Many computer users run a modified version of the GNU system every day, without realizing it.Through a peculiar turn of events, "
		<< "the version of GNU which is widely used today is often called “Linux”, and many of its users are not aware that it is basically "
		<< "the GNU system, developed by the GNU Project.There really is a Linux, and these people are using it, but it is just a part of the system they use. "
		<< "Linux is the kernel : the program in the system that allocates the machine’s resources to the other programs that you run.The kernel is an essential "
		<< "part of an operating system, but useless by itself; it can only function in the context of a complete operating system.Linux is normally used in "
		<< "combination with the GNU operating system : the whole system is basically GNU with Linux added, or GNU / Linux."
		<< "All the so - called “Linux” distributions are really distributions of GNU / Linux." << endl; */

	// Initialize(h*ck, fr*ck, vertexCount); 
	// FindStartVertex(h*ck, fr*ck);
	// FindPartialOrder(h*ck, fr*ck, vertexCount);

	if (vertexCount != 0)
		cout << "No partial order exists for the graph." << endl;

	return 0;
}
