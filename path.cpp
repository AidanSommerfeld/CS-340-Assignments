#include "path.h"
#include <iostream>
#include <fstream>
using namespace std;

void Dijkstras::initialization(Leader a[], int& startVertex)
{
	for (int i = 1; i < arrayLength; i++)
	{
		a[i].vertex = 0;
		a[i].known = false;
		a[i].distance = INT_MAX;
		a[i].firstFollower = nullptr;
	}
	ifstream inFile;
	inFile.open("inputs.txt");
	int x;
	int y;
	int z;
	while (inFile >> x)
	{
		inFile >> y;
		inFile >> z;
		Follower* p = new Follower;
		p->vertex = y;
		p->distance = z;
		p->nextFollower = a[x].firstFollower;
		a[x].firstFollower = p;
	}

}

void Dijkstras::search(Leader a[], int& startVertex)
{
	a[startVertex].vertex = startVertex;
	a[startVertex].distance = 0;
	int nextVertex;
	while (true)
	{
		int i = findNextVertex(a);
		if (i == -1)
			break;

		a[i].known = true;
		Follower* p = a[i].firstFollower;

		while (p != nullptr)
		{
			if (a[p->vertex].known == false)
			{
				if (a[i].distance + p->distance < a[p->vertex].distance)
				{
					a[p->vertex].distance = a[i].distance + p->distance;
					a[p->vertex].vertex = i;
				}
			}
			p = p->nextFollower;
		}
	}
	return;
}

int Dijkstras::findNextVertex(Leader a[])
{
	int nextVertex = -1;
	int shortestDistance = INT_MAX;

	for (int i = 1; i < arrayLength; i++)
	{
		if (a[i].distance < shortestDistance && a[i].known == false)
		{
			nextVertex = i;
			shortestDistance = a[i].distance;
		}
	}
	return nextVertex;
}

void Dijkstras::paths(Leader a[])
{
	for (int i = 1; i < arrayLength; i++)
	{
		int j = i;
		while (j != a[j].vertex)
		{
			cout << j << "<-";
			j = (a[j].vertex);
		}
		cout << j << endl;
	}
	return;
}

Dijkstras::Dijkstras()
{
	initialization(a, startVertex);
	search(a, startVertex);
	paths(a);

}

///////////////////////////////////////////////
void Floyds::initialization(int d[][7], int v[][7], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			d[i][j] = INT_MAX;
			v[i][j] = i;
			if (i == j)
			{
				d[i][j] = 0;
			}
		}

	}
	// input
	ifstream inFile;
	inFile.open("inputs.txt");
	int i;
	int j;
	int distance;
	while (inFile >> i)
	{
		inFile >> j;
		inFile >> distance;
		if (distance < d[i][j])
		{
			d[i][j] = distance;
		}
	}
	return;
}

void Floyds::search(int d[][7], int v[][7], int n)
{
	for (int k = 1; k < n; k++)
	{
		for (int i = 1; i < n; i++)
		{
			if (i == k || d[i][k] == INT_MAX)
				continue;
			else
			{
				for (int j = 1; j < n; j++)
				{
					if (i == j || j == k || d[k][j] == INT_MAX)
					{
						continue;
					}
					if (d[i][k] + d[k][j] < d[i][j])
					{
						d[i][j] = d[i][k] + d[k][j];
						v[i][j] = v[k][j];
					}

				}
			}
		}
	}
	return;
}

void Floyds::paths(int d[][7], int v[][7], int i, int j)
{
	int length = d[i][j];
	cout << j;
	while (i != v[i][j])
	{
		cout << "<-" << endl;
		cout << v[i][j];
		j = v[i][j];
	}
	cout << "< -";
	cout << i;
	cout << "(LENGTH =";
	cout << length;
	cout << ")" << endl;
}

Floyds::Floyds()
{
	initialization(d, v, n);
	search(d, v, n);
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (i != j && d[i][j] != INT_MAX)
			{
				paths(d, v, i, j);
			}

		}
	}
}
