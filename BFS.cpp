#include "BFS.h"

bool Graph::isEmpty()
{
	if (front == rear)
		return true;
	else
		return false;
}

bool Graph::isFull()
{
	if (rear == max_size - 1)
		return true;
	else
		return false;
}

void Graph::enqueue(int data)
{
	if (isFull())
		return ;
	queue[++rear] = data;
}

int Graph::dequeue()
{
	if (isEmpty())
		return -1;
	return queue[++front];
}

void Graph::bfs(int v)
{
	cout << "*****  Breadth First Search(BFS)" << endl;
	visited[v] = true;
	enqueue(v);
	cout << v << ' ';
	while (!isEmpty())
	{
		int now = dequeue();
		
		for (int k = 0; k < max_size; k++)
		{
			if (adj[now][k] == 1 && visited[k] == false)
			{
				enqueue(k);
				visited[k] = true;

				cout << k << ' ';
			}
		}
	}
	cout << endl;
}

void Graph::print_matrix()
{
	cout << "*****  Breath First Search(BFS)" << endl;
	for (int i = 0; i < max_size; i++)
	{
		for (int j = 0; j < max_size; j++)
			cout << adj[i][j] << ' ';
		cout << endl;
	}
}


