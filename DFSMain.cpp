#include "DFS.h"

const int max_size = 6;
bool visited[max_size] = { false, };
Graph graph[max_size];

void dfs(int v) 
{
	cout << v<<"->";
	visited[v] = true;

	for (Node *w = graph[v].getRoot(); w != NULL; w = w->link) 
	{
		if (!visited[w->data])
			dfs(w->data);
	}
}

int main() 
{
	for (int i = 0; i < max_size; i++) 
	{
		graph[i].insertGraph(i);
	}

	graph[0].insertGraph(1); graph[0].insertGraph(2);
	graph[1].insertGraph(0); graph[1].insertGraph(2); graph[1].insertGraph(3);
	graph[2].insertGraph(1); graph[2].insertGraph(5); 
	graph[3].insertGraph(1); graph[3].insertGraph(5); graph[3].insertGraph(4);
	graph[4].insertGraph(3); graph[4].insertGraph(5); 
	graph[5].insertGraph(2); graph[5].insertGraph(3); graph[5].insertGraph(4);
	graph[6].insertGraph(0); graph[6].insertGraph(1); graph[6].insertGraph(5);

	dfs(0);
	cout << endl;
}

/*
graph[0].insertGraph(1); graph[0].insertGraph(2);
graph[1].insertGraph(0); graph[1].insertGraph(3); graph[1].insertGraph(4);
graph[2].insertGraph(0); graph[2].insertGraph(5); graph[2].insertGraph(6);
graph[3].insertGraph(1); graph[3].insertGraph(7);
graph[4].insertGraph(1); graph[4].insertGraph(7);
graph[5].insertGraph(2); graph[5].insertGraph(7);
graph[6].insertGraph(2); graph[6].insertGraph(7);
graph[7].insertGraph(3); graph[7].insertGraph(4); graph[7].insertGraph(5);
graph[7].insertGraph(6);
*/