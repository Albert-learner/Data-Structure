#pragma once
#include <iostream>
using namespace std;
#define max_size 8

static int cnt = 0;
static bool visited1[max_size] = { false, };
static bool visited[max_size] = { false, };
static int adj[max_size][max_size] = 
{
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 0, 1, 1, 0, 0, 0},
	{1, 0, 0, 0, 0, 1, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 0, 0, 1},
	{0, 0, 0, 1, 1, 1, 1, 0}
};

class Node
{
public:
	int vertex;
	Node *link;

	Node(): link(NULL){}
	Node(int data) : vertex(data), link(NULL) {}
	friend class Graph;
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

	Node *graph[max_size];
	void insert(int index, int numC, int data);
	bool isEmpty();
	bool isFull();
	void enqueue(int data);
	int dequeue();
	void BFS(int v);
	void BFS_list(int v);
	void print_matrix();
};