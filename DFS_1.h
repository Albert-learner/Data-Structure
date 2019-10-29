#pragma once
#include <iostream>
using namespace std;
#define MAX 8

static bool visited[MAX];
static bool visited1[MAX];
static int cnt = 0;

class Node
{
public:
	int vertex;
	Node *link;
	Node(): link(NULL){}
	Node(int data) : vertex(data), link(NULL){}
	friend class Graph;
};

class Graph
{
public:
	int ADJM[MAX][MAX] = 
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
	Node *graph[MAX];
	void insert(int index, int numC, int data);
	void dfs(int v);
	void dfs_arr(int v);
	void printNode();
};