#ifndef _PRIM_H__
#define _PRIM_H__
#include <iostream>
#include <vector>
using namespace std;

const int max_size = 6;
extern bool check[max_size];
bool visited_1[max_size] = { false, };
bool visited_2[max_size] = { false, };

int COST[max_size][max_size] =
{ 
	{0, 5, 100, 12, 100, 100},
	{5, 0, 6, 10, 24, 100},
	{100, 6, 0, 17, 100, 30},
	{12, 10, 17, 0, 20, 100},
	{100, 24, 100, 20, 0, 13},
	{100, 100, 30, 100, 13, 0},
};

struct Node
{
	int vertex;
	int cost;
	Node *link;
};

class Queue
{
private:
	vector<int>queue;
	int front;
	int rear;
	int size;

	Queue(int sizeCost)
	{
		front = -1;
		rear = -1;
		size = sizeCost;
	}
	bool isEmpty();
	bool isFull();
	void enqueue(int data);
	int dequeue();
	friend class Graph;
};

class Graph
{
public:
	Node *graph[max_size];
	int vertexCount;
	int edgeCount;

	Graph(int vert, int edge)
	{
		vertexCount = vert;
		edgeCount = edge;

		for (int i = 0; i < vertexCount; i++)
			graph[i] = 0;
	}

	void sortGraph(int num);
	void outputGraph(int **);
	void outputList();
	bool addNode(int vnum1, int vnum2, int cost);
	void destroyList();
	void DFS(int vert);
	void BFS(int vert);
	void prim_method1(int vert, int **);
	void prim_method2(int vert, int **);

	friend class Queue;
};
#endif // !-PRIM_H__
