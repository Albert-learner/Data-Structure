#include "prim.h"

bool Queue::isEmpty()
{
	if (rear == front)
		return true;
	else
		return false;
}

bool Queue::isFull()
{
	if (rear == max_size - 1)
		return true;
	else
		return false;
}

void Queue::enqueue(int data)
{
	if (isFull())
		return ;
	queue[++rear] = data;
}

int Queue::dequeue()
{
	if (isEmpty())
		return -1;
	return queue[++front];
}

bool Graph::addNode(int num1, int num2, int cost)
{
	Node *n;
	n = new Node();
	if (n == NULL)
		return false;

	n->link = graph[num1];
	n->vertex = num2;
	n->cost = cost;
	graph[num2] = n;

	return true;
}

void Graph::outputGraph(int **arr)
{
	int i,j;
	
	for (i = 0; i < vertexCount; i++)
	{
		for (j = 0; j < vertexCount; j++)
		{
			if (i == j)
				arr[i][j] = 0;
			arr[i][j] = 100;
		}
	}

	Node *cur;
	int count = 1;
	/*
	for(i=0;i<vertexCount;i++)
	{
		cout<<" V"<<count++;
	}
	*/
	count = 0;
	for (i = 0; i < vertexCount; i++)
	{
		for (cur = graph[i]; cur != NULL; cur = cur->link)
		{
			arr[i][cur->vertex] = cur->cost;
			arr[cur->vertex][i] = cur->cost;
		}
	}

	for (i = 0; i < vertexCount; i++)
	{
		//cout<<'V'<<count++<<'  ';
		for (j = 0; j < vertexCount; j++)
			cout << arr[i][j] << '\t';
		cout << endl;
	}
}

void Graph::outputList()
{
	int i;
	Node *cur;

	for (i = 0; i < vertexCount; i++)
	{
		cout << 'V' << i << ": ";
		for (cur = graph[i]; cur != NULL; cur = cur->link)
		{
			cout << cur->vertex << '(' << cur->cost << ')';
			if (cur != NULL)
				cout << " ->";
		}
		cout << endl;
	}
}

void Graph::destroyList()
{
	int i;
	Node *cur, *link;

	for (i = 0; i < vertexCount; i++)
	{
		cur = graph[i];
		while (cur != NULL)
		{
			link = cur->link;
			delete cur;
			cur = link;
		}
	}
}

void Graph::sortGraph(int num)
{
	Node *cur;
	int tmp;

	for (int i = 0; i < num; i++)
	{
		for (cur = graph[i]; cur != NULL; cur = cur->link)
		{
			tmp = cur->vertex;
			cur->vertex = cur->link->vertex;
			cur->link->vertex = tmp;
		}

		for (cur = graph[i]; cur->link != NULL; cur = cur->link)
		{
			if (cur->vertex >= cur->link->vertex)
			{
				tmp = cur->vertex;
				cur->vertex = cur->link->vertex;
				cur->link->vertex = tmp;
			}
		}
	}
	return ;
}

void Graph::DFS(int vert)
{
	Node *cur;
	check[vert] = true;
	cout << 'V' << vert;
	for (cur = graph[vert]; cur != NULL; cur = cur->link)
	{
		if (!check[cur->vertex])
		{
			cout << "->";
			DFS(cur->vertex);
		}
	}
}

void Graph::BFS(int vert)
{
	Node *cur;
	check[vert] = true;
	Queue q(max_size);
	q.enqueue(vert);
	cout << vert << ' ';

	while (!q.isEmpty())
	{
		for (cur = graph[vert]; cur != NULL; cur = cur->link)
		{
			if (!check[cur->vertex])
			{
				q.enqueue(cur->vertex);
				check[cur->vertex] = true;
				cout << cur->vertex << ' ';
			}
		}
	}
}

void Graph::prim_method1(int vert, int **lowCost)
{
	int checkCnt = 0;
	int vertIndex = vert;
	int end = 100;
	int min = 100;
	int *lowCost1 = new int[vertIndex];

	for (int i = 0; i < vertexCount; i++)
	{
		lowCost1[i] = lowCost[vertIndex][i];
	}
	check[vert] = true;
	checkCnt++;

	while (checkCnt != vertexCount)
	{
		for (int i = 0; i < vertexCount; i++)
		{
			if (lowCost[vertIndex][i] < min && check[i] != true)
			{
				min = lowCost[vertIndex][i];
				end = i;
			}
		}
		check[end] = true;
		checkCnt++;

		if (checkCnt == vertexCount)
			cout << vertIndex + 1 << ',' << end + 1;
		else
			cout << vertIndex + 1 << ',' << end + 1 << "->";

		for (int i = 0; i < vertexCount; i++)
		{
			if (check[i] == true)
				lowCost1[i] = 100;
			else
				lowCost1[i] = lowCost[end][i];
		}

		min = 100;
		vertIndex = end;
	}
	delete[]lowCost1;
	cout << endl;
}