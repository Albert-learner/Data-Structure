#pragma once
#include <iostream>
using namespace std;
#define MAX 8

class Node
{
	int vertex;
	Node *next;

	Node() : next(0){}
	Node(int num) : vertex(num), next(0){}
	friend class Graph;
};

class Graph
{
private:
	Node *graph[MAX];
	bool visited[MAX];
	int matrix[MAX][MAX];
	Node *front;
	Node *rear;

public:
	Graph(){}
	void initGraph();
	void insertGraph(int row, int col, int num, int cnt);
	void initializeQ();
	void addQ(int v);
	bool isEmpty();
	int deleteQ();
	void bfs(int v);
	void print_matrix();
};