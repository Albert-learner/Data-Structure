#include "BFS_1.h"

void Graph::initGraph()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		visited[i] = false;
		graph[i] = new Node();
	}
}

void Graph::insertGraph(int row, int col, int num, int cnt)
{
	matrix[row][col] = num;
	Node *tmp = new Node(col);

	if (cnt == 0)
	{
		graph[row] = tmp;
		return ;
	}
	else
	{
		Node *p = graph[row];
		while (p->next != 0)
		{
			p = p->next;
		}
		p->next = tmp;
	}
}

void Graph::initializeQ()
{
	rear = new Node();
	front = rear;
}

void Graph::addQ(int v)
{
	Node *tmp = new Node(v);
	if (front == rear)
	{
		front->next = tmp;
		rear = rear->next;
	}
	else
	{
		rear->next = tmp;
		rear = rear->next;
	}
}

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

int Graph::deleteQ()
{
	Node *p = front;
	front = front->next;
	int vert = front->vertex;
	delete p;
	return vert;
}

void Graph::bfs(int v)
{
	Node *p;
	visited[v] = true;
	cout << "v" << v << " ";
	addQ(v);

	while (!isEmpty())
	{
		v = deleteQ();
		for (p = graph[v]; p; p = p->next)
		{
			if (!visited[p->vertex])
			{
				addQ(p->vertex);
				visited[p->vertex] = true;
				cout << "v" << p->vertex << " ";
			}
		}
	}
}

void Graph::print_matrix()
{
	cout << "*****  Adjacent Matrix";
	cout << "    "<<endl;
	for (int i = 0; i< MAX; i++)
	{
		cout << "v" << i << " ";
		for (int j = 0; j < MAX; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}