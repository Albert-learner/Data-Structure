#ifndef _BFS_H__
#define _BFS_H__

#include <iostream>
using namespace std;

#define max_size 8
static bool visited[max_size] = { false, };
static int adj[max_size][max_size] =
{
	{ 0,1,1,0,0,0,0,0 },
	{ 1,0,0,1,1,0,0,0 },
	{ 1,0,0,0,0,1,1,0 },
	{ 0,1,0,0,0,0,0,1 },
	{ 0,1,0,0,0,0,0,1 },
	{ 0,0,1,0,0,0,0,1 },
	{ 0,0,1,0,0,0,0,1 },
	{ 0,0,0,1,1,1,1,0 }
};

class Graph
{
private:
	int front, rear;
	int queue[max_size];
public:
	Graph()
	{
		front = -1;
		rear = -1;
	}

	bool isEmpty();
	bool isFull();
	void enqueue(int data);
	int dequeue();
	void bfs(int v);
	void print_matrix();
};

#endif // !_BFS_H__

