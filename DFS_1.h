#pragma once
#define MAX_VERTEX 100

extern bool check[MAX_VERTEX];

class Node
{
public:
	int vertex;
	Node *next;
};

class GraphList
{
public:
	Node * graph[MAX_VERTEX];
	int vertexCnt;
	int edgeCnt;

	GraphList(int vert, int edge)
	{
		vertexCnt = vert;
		edgeCnt = edge;

		for (int i = 0; i<vertexCnt; ++i)
			graph[i] = 0;
	}

	void initGraph_List(int numV);
	void sortGraph_List(int numV);
	void outputGraph_List();
	bool addNode(int vNum1, int vNum2);
	void destroyGraph_List();
	void DFS(int vert);
};



