/*==============================================
TopSort.h
================================================
A header for data structures required by 
graphs and the topological sort algorithm.
==============================================*/

#ifndef TOP_SORT_H
#define TOP_SORT_H

struct Follower; // Structure prototype.

struct Leader
{
	int inDegree;
	Leader *nextLeader;
	Follower *firstFollower;
	
	void TopSort(Leader *head, Leader *tail);
	void Initialize();
	void BuildList();
	void FindStartVertex();
	void FindPartialOrder();
};

struct Follower
{
	Leader *adjLeader;
	Follower *nextFollower;
};

#endif
