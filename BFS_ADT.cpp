#include "BFS.h"

bool Graph::isEmpty()
{
	if (front == rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Graph::isFull()
{
	if (rear == max_size - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Graph::enqueue(int data)
{
	if (isFull())
	{
		return ;
	}
	else
	{
		queue[++rear] = data;
	}
}

int Graph::dequeue()
{
	if (isEmpty())
	{
		return -1;
	}
	else
	{
		return queue[++front];
	}
}

void Graph::BFS(int v)
{
	cout << "***** Breath First Search(BFS)" << endl;
	visited[v] = true;
	cout << "v" << v<<"->";
	enqueue(v);

	while (!isEmpty())
	{
		int now = dequeue();

		for (int k = 0; k < max_size; k++)
		{
			if (adj[now][k] == 1 && visited[k] == false)
			{
				enqueue(k);
				visited[k] = true;

				if (k != max_size - 1)
				{
					cout << "v" << k << "->";
				}
				else
				{
					cout << "v" << k << endl;
				}
			}
		}
	}
	cout << endl;
}

void Graph::insert(int row, int col, int data, int cnt)
{
	adj[row][col] = data;
	Node *tmp = new Node(col);

	if (cnt == 0)
	{
		graph[row] = tmp;
		return ;
	}
	else
	{
		Node *p = graph[row];
		while (p->link != 0)
		{
			p = p->link;
		}
		p->link = tmp;
	}
}

void Graph::BFS_list(int v)
{
	cout << "***** Breath First Search(BFS) using List" << endl;
	Node *p;
	visited1[v] = true;
	cout << "v" << v << "->";
	
	for (p = graph[v]; p != NULL; p = p->link)
	{
		if (!visited1[p->vertex])
		{
			visited1[p->vertex] = true;
			cout << "v" << p->vertex << "->";
		}
	}
}

void Graph::print_matrix()
{
	cout << "***** Breath First Search(BFS)" << endl;
	for (int i = 0; i < max_size; i++)
	{
		for (int j = 0; j < max_size; j++)
		{
			cout <<adj[i][j] << " ";
		}
		cout << endl;
	}
}