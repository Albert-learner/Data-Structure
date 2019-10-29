#pragma once
#include <iostream>
using namespace std;

//MAX_SIZE 바꾸기, 정점 개수에 따라
const int MAX_SIZE = 7;

struct Node
{
	char start;
	int cost;
	char end;
	Node *next;

	Node(char start, int cost, char end)
	{
		this->start = start;
		this->cost = cost;
		this->end = end;
		next = NULL;
	}
};

class Kruskal
{
private:
	Node *head;
	Node *graph[MAX_SIZE];
	int parent[MAX_SIZE];

public:
	Kruskal();
	void addData(char start, int cost, char end);
	void sortData();
	int get(int x);
	int Find(int u, int v);
	void Union(int u, int v);
	void SolveKruskal();
	void OutPutKruData();
};

