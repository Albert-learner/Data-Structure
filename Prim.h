#pragma once
#define MAX_VERTEX 100
#include <iostream>
using namespace std;

extern bool check[MAX_VERTEX];

class Node
{
public:
	int vertex;
	int cost;
	Node *next;
};

class Queue
{
public:
	int *queue;
	int front;
	int size;
	int rear;

	Queue(int sizeN)
	{
		queue = new int[sizeN];
		front = 0;
		size = sizeN;
		rear = 0;
	}

	bool isEmpty();
	bool isFull();
	void Enqueue(int data);
	int Dequeue();
	friend class GraphList;
};

class GraphList
{
public:
	Node *graph[MAX_VERTEX];
	int vertexCnt;
	int edgeCnt;

	GraphList(int vert, int edge)
	{
		vertexCnt = vert;
		edgeCnt = edge;

		for (int i = 0; i < vertexCnt; i++)
		{
			graph[i] = 0;
		}
	}

	bool addNode(int vN1, int vN2, int cost);
	void sortGraph_List(int numV);
	void outputGraph_Arr(int **);
	void outputGraph_List();
	void destroyGraph_List();
	void DFS(int vert);
	void BFS(int vert);
	void primeMethod1(int vert, int **);
	void primeMethod2(int vert, int **);

	friend class Queue;
};