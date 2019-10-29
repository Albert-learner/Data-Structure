#include "Prim.h"

bool check[MAX_VERTEX] = { false, };
bool check2[MAX_VERTEX] = { false, };

bool Queue::isEmpty()
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

bool Queue::isFull()
{
	if (front == (rear + 1) % size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Queue::Enqueue(int data)
{
	if (!isFull())
	{
		queue[rear] = data;
		rear = (rear + 1) % size;
	}
	else
	{
		return;
	}
}

int Queue::Dequeue()
{
	int tmp = -1;

	if (!isEmpty())
	{
		tmp = queue[front];
		queue[front] = NULL;
		front = (front + 1) % size;
		return tmp;
	}
	else
	{
		return tmp;
	}
}

bool GraphList::addNode(int vN1, int vN2, int cost)
{
	Node *nNode = new Node();
	if (nNode == NULL)
	{
		return false;
	}
	else
	{
		nNode->next = graph[vN1];
		nNode->vertex = vN2;
		nNode->cost = cost;
		graph[vN1] = nNode;

		nNode = new Node();
		if (nNode == NULL)
		{
			free(graph[vN1]);
			return false;
		}
		else
		{
			nNode->next = graph[vN2];
			nNode->vertex = vN1;
			nNode->cost = cost;
			graph[vN2] = nNode;

			return true;
		}
	}
}

void GraphList::outputGraph_List()
{
	Node *now;

	for (int i = 0; i < vertexCnt; i++)
	{
		cout << "V" << i << ":  ";
		for (now = graph[i]; now != NULL; now = now->next)
		{
			cout << now->vertex << "(" << now->cost << ")";
			if (now->next != NULL)
			{
				cout << " -> ";
			}
		}
		cout << endl;
	}
}

void GraphList::outputGraph_Arr(int **arr)
{
	int i;

	for (int j = 0; j < vertexCnt; j++)
	{
		for (int k = 0; k < vertexCnt; k++)
		{
			arr[j][k] = 100;
		}
	}

	Node *now;
	int count = 1;
	/*
	배열 할당 및 초기화
	for (int j = 0; j < vertexCnt; j++)
	{
		cout << " V" << count++;
	}
	*/
	count = 0;
	
	for (i = 0; i < vertexCnt; i++)
	{
		for (now = graph[i]; now != NULL; now = now->next)
		{
			arr[i][now->vertex] = now->cost;
			arr[now->vertex][i] = now->cost;
		}
	}
	cout << "--------- Reinitialized Matrix ---------" << endl;
	for (int j = 0; j < vertexCnt; j++)
	{
		//cout << "V" << count++ << "  ";
		for (int k = 0; k < vertexCnt; k++)
		{
			cout << arr[j][k] << "\t";
		}
		cout << endl;
	}
}

void GraphList::destroyGraph_List()
{
	int i; /*iterator*/
	Node *now, *next;

	for (i = 0; i < vertexCnt; i++)
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
	int tmp;

	for (int i = 0; i < numV; i++)
	{
		for (now = graph[i]; now->next != NULL; now = now->next)
		{
			if (now->vertex >= now->next->vertex)
			{
				tmp = now->vertex;
				now->vertex = now->next->vertex;
				now->next->vertex = tmp;
			}
		}
		for (now = graph[i]; now->next != NULL; now = now->next)
		{
			if (now->vertex >= now->next->vertex)
			{
				tmp = now->vertex;
				now->vertex = now->next->vertex;
				now->next->vertex = tmp;
			}
		}
	}
	return ;
}

void GraphList::DFS(int vert)
{
	Node *now;
	check[vert] = true;
	cout << "V" << vert;

	for (now = graph[vert]; now != NULL; now = now->next)
	{
		if (!check[now->vertex])
		{
			cout << " -> ";
			DFS(now->vertex);
		}
	}
}

void GraphList::BFS(int vert)
{
	Node *now;
	check[vert] = true;
	Queue queue(MAX_VERTEX);
	queue.Enqueue(vert);
	cout << vert << " ";

	while (!queue.isEmpty())
	{
		vert = queue.Dequeue();
		for (now = graph[vert]; now != NULL; now = now->next)
		{
			if (!check[now->vertex])
			{
				queue.Enqueue(now->vertex);
				check[now->vertex] = true;
				cout << now->vertex << " ";
			}
		}
	}
}

void GraphList::primeMethod1(int vert, int **lowCst)
{
	int checkCnt = 0;
	int vertIdx = vert;
	int end = 100, min = 100, sum = 0;
	int *lowCst1 = new int[vertexCnt];
	for (int i = 0; i < vertexCnt; i++)
	{
		lowCst1[i] = lowCst[vert][i];
		//cout << lowCst1[i] << ' ';
	}
	check[vert] = true;
	checkCnt++;

	cout << "Prim method 1, find the least cost at current node" << endl;
	while (checkCnt != vertexCnt)
	{
		//min값 찾기
		for (int i = 0; i < vertexCnt; i++)
		{
			if (lowCst[vertIdx][i] < min && check[i] != true)
			{
				min = lowCst[vertIdx][i];
				end = i;
			}
		}
		//cout << "min:" << min << endl;
		check[end] = true;
		checkCnt++;
		if (checkCnt == vertexCnt)
		{
			//cout << vertIdx + 1 << "," << end + 1;
			cout << "(" << char(vertIdx + 1 + 64)<< "," << char(end + 1 + 64) << ")";
		}
		else
		{
			//cout << vertIdx + 1 << "," << end + 1 << " -> ";
			cout << "(" << char(vertIdx + 1 + 64)<< "," << char(end + 1 + 64)<< ")" << " -> ";
		}

		for (int i = 0; i < vertexCnt; i++)
		{
			if (check[i] == true)
			{
				lowCst1[i] = 100;
			}
			else
			{
				lowCst1[i] = lowCst[end][i];
			}
			//cout << lowCst1[i] << " ";
		}
		sum += min;
		min = 100;
		vertIdx = end;
	}
	cout << endl;
	cout << "Weight: " << sum << endl;
	delete[]lowCst1;

	cout << endl;
}

void GraphList::primeMethod2(int vert, int **lowCst)
{
	int checkCnt = 0;
	int vertIdx = vert;
	int end = 0, min = 100, sum = 0;
	int *lowCst1 = new int[vertexCnt];
	int *lowWhere = new int[vertexCnt];

	for (int i = 0; i < vertexCnt; i++)
	{
		lowCst1[i] = lowCst[vert][i];
		lowWhere[i] = vert;
		//cout << lowCst1[i] << " ";
	}//값을 받아옴
	check2[vert] = true;
	checkCnt++;

	cout << "Prim method 2, find the least cost at all passed node" << endl;
	while (checkCnt != vertexCnt)
	{
		//min값 찾기
		for (int i = 0; i < vertexCnt; i++)
		{
			if (lowCst1[i] < min && check2[i] != true)
			{
				min = lowCst1[i];
				end = i;
			}
		}
		//cout << "min:" << min << endl;
		check2[end] = true;
		checkCnt++;

		if (checkCnt == vertexCnt)
		{
			//cout << lowWhere[end] + 1 << "," << end + 1;
			cout << "(" << char(lowWhere[end] + 1 + 64)<< "," << char(end + 1 + 64) << ")";
		}
		else
		{
			//cout << lowWhere[end] + 1 << "," << end + 1 << " -> ";
			cout << "(" << char(lowWhere[end] + 1 + 64)<< "," << char(end + 1 + 64) << ")" << " -> ";
		}

		for (int i = 0; i < vertexCnt; i++)
		{
			if (check2[i] == true)
			{
				lowCst1[i] = 100;
			}
			else if (lowCst1[i] > lowCst[end][i])
			{
				lowCst1[i] = lowCst[end][i];
				lowWhere[i] = end;
			}
			//cout << lowCst1[i] << ' ';
		}
		sum += min;
		min = 100;
		vertIdx = end;
	}
	cout << endl;
	cout << "Weight: " << sum << endl;
	delete[]lowCst1;
	cout << endl;
}