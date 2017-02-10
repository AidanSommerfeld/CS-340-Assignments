/*==============================================
TopSort.h
================================================
A header for data structures required by
graphs and the topological sort algorithm.
==============================================*/
#include <string>
using namespace std;
#ifndef TOP_SORT_H
#define TOP_SORT_H



struct Follower; // Structure prototypes.
struct Leader;
struct FollowerString;
struct LeaderString;


struct Leader
{
	int inDegree;
	Leader *nextLeader;
	Follower *firstFollower;
	int data;
	int depth = 0;
};

struct Follower
{
	Leader *adjLeader;
	Follower *nextFollower;
};

struct LeaderString
{
	int inDegree;
	LeaderString *nextLeader;
	FollowerString *firstFollower;
	string data;
	int depth = 0;
};

struct FollowerString
{
	LeaderString *adjLeader;
	FollowerString *nextFollower;
};


class TopSort
{
public:
	TopSort();
	void TopSort::initialization(Leader*&head, Leader*&tail, int vertexCount);
	Leader* TopSort::BuildList(int w, Leader*&head, Leader*&tail, int vertexCount);
	void TopSort::FindStartVertex(Leader*&head, Leader*&tail);
	void TopSort::PartialOrder(Leader*&head, Leader*&tail, int vertexCount);
	void TopSort::GetDepths(Leader*&head, Leader*&tail);
	void TopSort::Print(Leader*&head, Leader*&tail);

private:
	Leader*head;
	Leader*tail;
	int vertexCount;
};



class TopSortString
{
public:
	TopSortString();
	void TopSortString::initialization(LeaderString*&head, LeaderString*&tail, int vertexCount);
	LeaderString* TopSortString::BuildList(string w, LeaderString*&head, LeaderString*&tail, int vertexCount);
	void TopSortString::FindStartVertex(LeaderString*&head, LeaderString*&tail);
	void TopSortString::PartialOrder(LeaderString*&head, LeaderString*&tail, int vertexCount);
	void TopSortString::GetDepths(LeaderString*&head, LeaderString*&tail);
	void TopSortString::Print(LeaderString*&head, LeaderString*&tail);

private:
	LeaderString*head;
	LeaderString*tail;
	int vertexCount;
};

#endif
