#ifndef PATH_H
#define PATH_H
#include <iostream>
using namespace std;
struct Leader;
struct Follower;

struct Leader
{
	int vertex;
	int distance;
	bool known = false;
	Follower* firstFollower;

};
struct Follower
{
	int vertex;
	int distance;
	Follower*nextFollower;
};

class Dijkstras
{
public:
	Dijkstras::Dijkstras();
	void Dijkstras::initialization(Leader a[], int& startVertex);
	void Dijkstras::search(Leader a[], int& startVertex);
	int Dijkstras::findNextVertex(Leader a[]);
	void Dijkstras::paths(Leader a[]);
private:
	int startVertex = 1;
	Leader a[8];
	int arrayLength = 8;
};

class Floyds
{
public:
	Floyds::Floyds();
	void Floyds::initialization(int d[][7],int v[][7],int n);
	void Floyds::search(int d[][7], int v[][7], int n);
	void Floyds::paths(int d[][7], int v[][7], int i, int j);
private:
	int d[7][7];
	int v[7][7];
	int n;
	int i;
	int j;
};
#endif