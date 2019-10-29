#include "DFS.h"

void Graph::insert(int idx, int numC, int num)
{
	Node *tmp = new Node(num);
	if (numC == 0)
	{
		graph[idx] = tmp;
		return;
	}
	else
	{
		Node *p = graph[idx];
		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = tmp;
	}
}

void Graph::dfs(int v)
{
	Node *w;
	visited[v] = true;
	cnt++;
	//cnt 개수 == MAX 개수
	if (cnt != MAX)
	{
		cout << "V" << v << "->";
	}
	else
	{
		cout << "V" << v << endl;
		cnt = 0;
	}
	for (w = graph[v]; w != NULL; w = w->link)
	{
		if (!visited[w->vertex])
		{
			dfs(w->vertex);
		}
	}
}

void Graph::dfs_arr(int v)
{
	visited1[v] = true;
	cnt++;

	if (cnt != MAX)
	{
		cout << "V" << v << "->";
	}
	else
	{
		cout << "V" << v << endl;
	}
	for (int j = 0; j < MAX; j++)
	{
		if (ADJM[v][j] == 1 && visited1[j] == 0)
		{
			dfs_arr(j);
		}
	}
}

void Graph::printNode()
{
	for (int i = 0; i < MAX; i++)
	{
		Node *p = graph[i];
		cout << "V" << i << ": ";
		while (p != NULL)
		{
			cout << p->vertex << " ";
			p = p->link;
		}
		cout << endl;
	}
}