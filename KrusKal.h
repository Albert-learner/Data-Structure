#ifndef _KRUSKAL_H__
#define _KRUSKAL_H__
#include <iostream>
using namespace std;

const int MAX_SIZE = 6;

struct Node
{
	char start;
	int cost;
	char end;
	Node *next;

	Node(char s, int c, char e)
	{
		start = s;
		cost = c;
		end = e;
		next = NULL;
	}
};

class KrusKal
{
public:
	Node *head;
	Node *graph[MAX_SIZE];
	int parent[MAX_SIZE];
	KrusKal();
	void addData(char start, int cost, char end);
	void sortData();
	int get(int x);
	int Find(int u, int v);
	void Union(int u, int v);
	void SolveKrusKal();
	void OutPutKRUData();
};
#endif // !_KRUSKAL_H__
