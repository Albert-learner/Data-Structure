#pragma once
#include <iostream>
using namespace std;
#define MAX 6 // 값 바꾸기, .dat파일 바꾸기

static bool visited[MAX];
static bool visited1[MAX];
static int cnt = 0;

class Node
{
public:
	int vertex;
	Node *link;
	Node() : link(NULL) {}
	Node(int data) : vertex(data), link(NULL) {}
	friend class Graph;
};

class Graph
{
public:
	//인접 행렬로 바꾸기
	int ADJM[MAX][MAX] =
	{
		{0, 1, 1, 0, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{1, 1, 0, 0, 0, 1},
		{0, 1, 0, 0, 1, 1},
		{0, 0, 0, 1, 0, 1},
		{0, 0, 1, 1, 1, 1}
	};
	Node *graph[MAX];
	void insert(int index, int numC, int data);
	void dfs(int v);
	void dfs_arr(int v);
	void printNode();
};