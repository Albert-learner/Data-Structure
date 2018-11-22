#include "DFS_1.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include <iostream>

using namespace std;

bool check[MAX_VERTEX] = { false, };

bool GraphList::addNode(int vNum1, int vNum2)
{
	Node *newNode;
	newNode = new Node();
	if (newNode == NULL) return false;
	newNode->next = graph[vNum1];
	newNode->vertex = vNum2;
	graph[vNum1] = newNode;


	newNode = new Node();
	if (newNode == NULL)
	{
		free(graph[vNum1]);
		return false;
	}
	newNode->next = graph[vNum2];
	newNode->vertex = vNum1;
	graph[vNum2] = newNode;

	return true;
}


void GraphList::outputGraph_List()
{
	int i;
	Node *now;
	for (i = 0; i<vertexCnt; ++i)
	{
		cout << 'V' << i << ":  ";
		for (now = graph[i]; now != NULL; now = now->next)
		{
			cout << now->vertex;
			if (now->next != NULL)
				cout << " -> ";
		}
		cout << endl;
	}
}


void GraphList::destroyGraph_List()
{
	int i;
	Node *now, *next;
	for (i = 0; i<vertexCnt; ++i)
	{
		now = graph[i];
		while (now != NULL)
		{
			next = now->next;
			delete now;
			now = next;
		}
	}
}

void GraphList::sortGraph_List(int numV)
{
	Node *now;
	int temp;

	for (int i = 0; i < numV; i++)
	{
		for (now = graph[i]; now->next != NULL; now = now->next)
		{
			if (now->vertex >= now->next->vertex)
			{
				temp = now->vertex;
				now->vertex = now->next->vertex;
				now->next->vertex = temp;

			}
		}
		for (now = graph[i]; now->next != NULL; now = now->next)
		{
			if (now->vertex >= now->next->vertex)
			{
				temp = now->vertex;
				now->vertex = now->next->vertex;
				now->next->vertex = temp;

			}
		}
	}


	return;
}

void GraphList::DFS(int vert)
{
	Node  *now;
	check[vert] = true;
	cout << vert << ' ';
	for (now = graph[vert]; now != NULL; now = now->next)
	{
		if (!check[now->vertex])
			DFS(now->vertex);
	}
}