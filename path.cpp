#include "path.h"
#include <iostream>
#include <fstream>
using namespace std;

void Dijkstras::initialization(Leader a[])
{
	for (int i = 1; i < (9-1); i++)
	{
		a[i].vertex = 0;
		a[i].known = false;
		a[i].distance = HIGH_VALUE;
		a[i].firstFollower = NULL;
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

void Dijkstras::search(Leader a[], int startVertex)
{
	a[startVertex].vertex = startVertex;
	a[startVertex].distance = 0;
	while (true)
	{
		int i = findNextVertex(a);
		if (i == VALUE_NOT_FOUND)
		{
			return;
		}

		a[i].known = true;
		Follower* p = a[i].firstFollower;

		while (p != NULL)
		{
			if (a[p->vertex].known == false)
			{
				if ((a[i].distance + p->distance) < a[p->vertex].distance)
				{
					a[p->vertex].distance = (a[i].distance + p->distance);
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
	int nextVertex = VALUE_NOT_FOUND;
	int shortestDistance = HIGH_VALUE;

	for (int i = 1; i < (9-1); i++)
	{
		if ((a[i].distance < shortestDistance) && (a[i].known == false))
		{
			nextVertex = i;
			shortestDistance = a[i].distance;
		}
	}
	return nextVertex;
}

void Dijkstras::paths(Leader a[])
{
	for (int i = 1; i < (9-1); i++)
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
	initialization(a);
	search(a, startVertex);
	paths(a);

}

///////////////////////////////////////////////
void Floyds::initialization(int d[][FLOYD_SIZE], int v[][FLOYD_SIZE], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			d[i][j] = HIGH_VALUE;
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

void Floyds::search(int d[][FLOYD_SIZE], int v[][FLOYD_SIZE], int n)
{
	for (int k = 1; k < n; k++)
	{
		for (int i = 1; i < n; i++)
		{
			if (i == k || d[i][k] == HIGH_VALUE)
			{

			}
			else
			{
				for (int j = 1; j < n; j++)
				{
					if (i == j || j == k || d[k][j] == HIGH_VALUE)
					{
						
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

void Floyds::paths(int d[][FLOYD_SIZE], int v[][FLOYD_SIZE], int i, int j)
{
	int length = d[i][j];
	cout << j;
	while (i != v[i][j])
	{
		cout << "<-";
		cout << v[i][j];
		j = v[i][j];
	}
	cout << "<-";
	cout << i;
	cout << "(LENGTH =";
	cout << length;
	cout << ")" << endl;

}

Floyds::Floyds()
{
	initialization(d, v, FLOYD_SIZE);

	search(d, v, FLOYD_SIZE);

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <  n; j++)
		{
			if (i != j && d[i][j] != HIGH_VALUE)
			{
				paths(d, v, i, j);
			}

		}
	}
	cout << "D array:" << endl;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "V array: " << endl;
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
