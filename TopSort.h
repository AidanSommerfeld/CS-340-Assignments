/*==============================================
TopSort.h
================================================
A header for data structures required by 
graphs and the topological sort algorithm.
==============================================*/

#ifndef TOP_SORT_H
#define TOP_SORT_H

struct Follower; // Structure prototypes.
struct Leader;

void BuildList(, Leader *head, Leader *tail, int &vertexCount);

struct Leader
{
	int inDegree;
	Leader *nextLeader;
	Follower *firstFollower;
	
	void TopSort(Leader *head, Leader *tail);
	void Initialize(Leader *head, Leader *tail, int &vertexCount);
	void FindStartVertex(Leader *head, Leader *tail);
	void FindPartialOrder(Leader *head, Leader *tail, int &vertexCount);
};

struct Follower
{
	Leader *adjLeader;
	Follower *nextFollower;
};

#endif
