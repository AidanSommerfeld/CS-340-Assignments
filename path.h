#ifndef PATH_H
#define PATH_H
#include <iostream>
using namespace std;

const int FLOYD_SIZE = 8;
const int HIGH_VALUE = 9999;
const int VALUE_NOT_FOUND = 10000;

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
	void Dijkstras::initialization(Leader a[]);
	void Dijkstras::search(Leader a[], int startVertex);
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
	void Floyds::initialization(int d[][FLOYD_SIZE], int v[][FLOYD_SIZE], int n);
	void Floyds::search(int d[][FLOYD_SIZE], int v[][FLOYD_SIZE], int n);
	void Floyds::paths(int d[][FLOYD_SIZE], int v[][FLOYD_SIZE], int i, int j);
private:
	int d[FLOYD_SIZE][FLOYD_SIZE];
	int v[FLOYD_SIZE][FLOYD_SIZE];
	int n = FLOYD_SIZE;
	int i = 1;
	int j = 1;
};
#endif
