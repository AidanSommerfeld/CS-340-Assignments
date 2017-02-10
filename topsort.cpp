#include <iostream>
#include <fstream>
#include <string>
#include "topsort.h"
using namespace std;

void TopSort::initialization(Leader*&head, Leader*&tail, int vertexCount)
{
	head = new Leader;
	tail = head;

	int x;
	int y;

	ifstream inFile;

	inFile.open("inputs.txt");

	while (inFile >> x)
	{
		inFile >> y;
		Leader* p = BuildList(x, head, tail, vertexCount);
		Leader* q = BuildList(y, head, tail, vertexCount);

		Follower* f = new Follower;
		f->adjLeader = q;
		f->nextFollower = p->firstFollower;

		p->firstFollower = f;
		q->inDegree++;
	}

	inFile.close();
}


Leader* TopSort::BuildList(int w, Leader*&head, Leader*&tail, int vertexCount)
{
	Leader* h = head;
	tail->data = w;
	while (h->data != w)
	{
		h = h->nextLeader;
	}
	if (h == tail)
	{
		tail = new Leader;
		vertexCount++;
		h->inDegree = 0;
		h->firstFollower = nullptr;
		h->nextLeader = tail;
	}
	return h;
}

void TopSort::FindStartVertex(Leader*&head, Leader*&tail)
{
	Leader*p = head;
	head = nullptr;

	Leader* r = tail;
	tail = nullptr;

	while (p != r)
	{
		Leader* q = p;
		p = p->nextLeader;
		if (q->inDegree == 0)
		{
			q->nextLeader = head;
			head = q;
			if (tail == nullptr)
			{
				tail = q;
			}
		}
	}
}

void TopSort::PartialOrder(Leader*&head, Leader*&tail, int vertexCount)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		vertexCount--;
		Follower*f = head->firstFollower;
		head = head->nextLeader;

		while (f != nullptr)
		{
			Leader* p = f->adjLeader;
			p->inDegree--;
			if (p->inDegree == 0)
			{
				p->nextLeader = nullptr;
				tail->nextLeader = p;
				tail = p;
				if (head == nullptr)
				{
					head = tail;
				}
			}
			f = f->nextFollower;
		}
	}
}
void TopSort::GetDepths(Leader*&head, Leader*&tail)
{
	for (Leader*p = head; p != tail; p = p->nextLeader)
	{
		if (p->firstFollower != nullptr)
		{
			for (Follower*q = p->firstFollower; q != nullptr; q = q->nextFollower)
			{
				if ((p->depth + 1) < q->adjLeader->depth || q->adjLeader->depth == 0)
				{
					q->adjLeader->depth = (p->depth + 1);
				}
			}
		}
	}
}

void TopSort::Print(Leader*&head, Leader*&tail)
{
	cout << "Printing the vertexes" << endl;
	int i = 0;
	while (i <= 25)
	{
		bool valueFound = false;
		for (Leader* p = head; p != tail; p = p->nextLeader)
		{
			if (p->depth == i)
			{
				valueFound = true;
				cout << p->data << " ";
			}
		}

		if (valueFound == true)
		{
			cout << endl;
		}
		i++;
	}
	cout << endl;
}

TopSort::TopSort()
{
	vertexCount = 0;
	initialization(head, tail, vertexCount);
	GetDepths(head, tail);
	Print(head, tail);
	FindStartVertex(head, tail);
	PartialOrder(head, tail, vertexCount);
	if (vertexCount != 0)
	{
		cout << "Not a partial order" << endl;
	}
}



void TopSortString::initialization(LeaderString*&head, LeaderString*&tail, int vertexCount)
{
	head = new LeaderString;
	tail = head;

	string x;
	string y;

	ifstream inFile;

	inFile.open("prerequisites.txt");

	while (inFile >> x)
	{
		inFile >> y;
		LeaderString* p = BuildList(x, head, tail, vertexCount);
		LeaderString* q = BuildList(y, head, tail, vertexCount);

		FollowerString* f = new FollowerString;
		f->adjLeader = q;
		f->nextFollower = p->firstFollower;

		p->firstFollower = f;
		q->inDegree++;
	}

	inFile.close();
}

LeaderString* TopSortString::BuildList(string w, LeaderString*&head, LeaderString*&tail, int vertexCount)
{
	LeaderString* h = head;
	tail->data = w;
	while (h->data != w)
	{
		h = h->nextLeader;
	}
	if (h == tail)
	{
		tail = new LeaderString;
		vertexCount++;
		h->inDegree = 0;
		h->firstFollower = nullptr;
		h->nextLeader = tail;
	}
	return h;
}
void TopSortString::FindStartVertex(LeaderString*&head, LeaderString*&tail)
{
	LeaderString*p = head;
	head = nullptr;

	LeaderString* r = tail;
	tail = nullptr;

	while (p != r)
	{
		LeaderString* q = p;
		p = p->nextLeader;
		if (q->inDegree == 0)
		{
			q->nextLeader = head;
			head = q;
			if (tail == nullptr)
			{
				tail = q;
			}
		}
	}
}
void TopSortString::PartialOrder(LeaderString*&head, LeaderString*&tail, int vertexCount)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		vertexCount--;
		FollowerString*f = head->firstFollower;
		head = head->nextLeader;

		while (f != nullptr)
		{
			LeaderString* p = f->adjLeader;
			p->inDegree--;
			if (p->inDegree == 0)
			{
				p->nextLeader = nullptr;
				tail->nextLeader = p;
				tail = p;
				if (head == nullptr)
				{
					head = tail;
				}
			}
			f = f->nextFollower;
		}
	}
}

void TopSortString::GetDepths(LeaderString*&head, LeaderString*&tail)
{
	for (LeaderString*p = head; p != tail; p = p->nextLeader)
	{
		if (p->firstFollower != nullptr)
		{
			for (FollowerString*q = p->firstFollower; q != nullptr; q = q->nextFollower)
			{
				if ((p->depth + 1) < q->adjLeader->depth || q->adjLeader->depth == 0)
				{
					q->adjLeader->depth = (p->depth + 1);
				}
			}
		}
	}
}

void TopSortString::Print(LeaderString*&head, LeaderString*&tail)
{
	cout << "Printing the vertexes" << endl;
	int i = 0;
	while (i <= 30)
	{
		bool valueFound = false;
		for (LeaderString* p = head; p != tail; p = p->nextLeader)
		{
			if (p->depth == i)
			{
				valueFound = true;
				cout << p->data << " ";
			}
		}

		if (valueFound == true)
		{
			cout << endl;
		}
		i++;
	}
	cout << endl;
}

TopSortString::TopSortString()
{
	vertexCount = 0;
	initialization(head, tail, vertexCount);
	GetDepths(head, tail);
	Print(head, tail);
	FindStartVertex(head, tail);
	PartialOrder(head, tail, vertexCount);
	if (vertexCount != 0)
	{
		cout << "Not a partial order" << endl;
	}
}
