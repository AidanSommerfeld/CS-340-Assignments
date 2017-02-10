#include <iostream>
#include <fstream>
#include "TopSort.h"
using namespace std;

leader* TopSort::BuildList(leader*w, leader*head, leader*tail, int vertexCount)
{
	leader* h = head;
	tail->data = w;
	while (h->data != w)
	{
		h = h->nextLeader;
	}
	if (h == tail)
	{
		tail = new leader;
		vertexCount++;
		h->inDegree = 0;
		h->firstFollower = nullptr;
		h->nextLeader = tail;
	}
	return h;
}

void TopSort::initialization(leader* head, leader* tail, int vertexCount)
{
	head = new leader;
	tail = head;

	int x;
	int y;

	ifstream inFile;
	
	inFile.open("whoNamedThisFileAnyway.txt");

	while (infile >> x)
	{
		infile >> y;
		leader* p = BuildList(x, head, tail, vertexCount);
		leader* q = BuildList(y, head, tail, vertexCount);

		follower* f = new follower;
		f->adjLeader = q;
		f->nextFollower = p->firstFollower;

		p->firstFollower = f;
		q->inDegree++;
	}

	infile.close();
}

void TopSort::FindStartVertex(leader*head, leader*tail)
{
	leader*p = head;
	head = nullptr;

	leader* r = tail;
	tail = nullptr;

	while (p != r)
	{
		leader* q = p;
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

void TopSort::PartialOrder(leader*head, leader*tail, int vertexCount)
{
	while (head != nullptr)
	{
		cout << head->data;
		vertexCount--;
		follower*f = head->firstFollower;
		head = head->nextLeader;
		
		while (f != nullptr)
		{
			leader* p = f->adjLeader;
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
