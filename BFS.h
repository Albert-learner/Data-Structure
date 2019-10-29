#pragma once
#include <iostream>
using namespace std;
#define MAX 6

class Node
{
public:
	int vertex;
	Node *next;

	Node() : next(0) {}
	Node(int num) : vertex(num), next(0) {}
	friend class Graph;
};

class Graph
{
private:
	bool visited[MAX];
	bool visited1[MAX];
	int matrix[MAX][MAX];
	Node *front;
	Node *rear;

public:
	Node *graph[MAX];
	Graph() {}
	void initGraph();
	void insertGraph(int row, int col, int num, int cnt);
	void insertList(int index, int numC, int data);
	void initializeQ();
	void addQ(int v);
	bool isEmpty();
	int deleteQ();
	void bfs(int v);
	void bfs_list(int v);
	void print_matrix();
};