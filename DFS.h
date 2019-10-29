#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *link;
};

class Graph
{
private:
	Node *root;
public:
	Graph() :root(NULL) {}
	void insertGraph(int data);
	Node *getRoot()
	{
		return root;
	}
};

void dfs(int v);

