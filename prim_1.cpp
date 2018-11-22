#include "prim_1.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include <iostream>

using namespace std;

bool check[MAX_VERTEX] = { false, };
bool check2[MAX_VERTEX] = { false, };
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: addNode() - �� ������ ���踦 ����Ʈ�� �����
��������:  g - �׷��� ���� ����ü�� �ּ�
vNum1 - ù��° ������ ��ȣ
vNum2 - �ι�° ������ ��ȣ
���ϰ�: ���� ����� �����ϸ� TRUE ����, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
bool GraphList::addNode(int vNum1, int vNum2, int cost)
{
	Node *newNode;
	newNode = new Node();  /* �� ���� ���� ��� ���� */
	if (newNode == NULL) 
		return false;

	newNode->next = graph[vNum1];
	newNode->vertex = vNum2;
	newNode->cost = cost;
	graph[vNum1] = newNode;   /* ���ο� ���� ���� ��带 ���� ����Ʈ�� �߰� */

							  /* ������ �׷��������� ��Ī��(Symmetry) ����Ͽ� �� ���⿡ ������ �߰��� �ʱ�ȭ */
	newNode = new Node();  /* �� ���� ���� ��� ���� */
	if (newNode == NULL)
	{
		free(graph[vNum1]);
		return false;
	}
	newNode->next = graph[vNum2];
	newNode->vertex = vNum1;
	newNode->cost = cost;
	graph[vNum2] = newNode;   /* ���ο� ���� ���� ��带 ���� ����Ʈ�� �߰� */
							  //cout << "ADD ����" << endl;
	return true;
}

/*--------------------------------------------------------------------------------------
�Լ��� �� ���: outputGraph_L() - �׷������� ������ ������ ���踦 ���� ����Ʈ ���·� ���
��������:  g : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void GraphList::outputGraph_List()
{
	int i;         // iterator 
	Node *now;
	for (i = 0; i<vertexCnt; ++i)
	{
		cout << 'V' << i << ":  ";
		for (now = graph[i]; now != NULL; now = now->next)
		{
			cout << now->vertex << '(' << now->cost << ')';
			if (now->next != NULL)
				cout << " -> ";
		}
		cout << endl;
	}
}

/*--------------------------------------------------------------------------------------
�Լ��� �� ���: outputGraph_L() - �׷������� ������ ������ ���踦 ���� ����Ʈ ���·� ���
��������:  g : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void GraphList::outputGraph_Array(int **arr)
{
	int i;         // iterator 

	for (int j = 0; j < vertexCnt; j++)
	{
		for (int k = 0; k < vertexCnt; k++)
		{
			arr[j][k] = 100;
		}
	} // �迭 �Ҵ� �� �ʱ�ȭ
	Node *now;
	int count = 1;
	/*for (int j = 0; j < vertexCnt; j++)
	{
	//cout << " V" << count++;
	} */// �迭 ���� ���

	count = 0;

	for (i = 0; i<vertexCnt; ++i)
	{
		for (now = graph[i]; now != NULL; now = now->next)
		{
			arr[i][now->vertex] = now->cost;
			arr[now->vertex][i] = now->cost;
		}
	}
	for (int j = 0; j < vertexCnt; j++)
	{
		//cout << 'V' << count++ << '  ';
		for (int k = 0; k < vertexCnt; k++)
		{
			cout << arr[j][k] << '\t';
		}
		cout << endl;
	} // �迭 �Ҵ� �� �ʱ�ȭ
}

/*--------------------------------------------------------------------------------------
�Լ��� �� ���: destroyGraph_L() - �׷������� ���� ��� ��� ����
��������:
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void GraphList::destroyGraph_List()
{
	int i;         /* iterator */
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
				//cout <<i<<"�࿡�� " <<now->vertex << ' ' << now->next->vertex << "swap" << endl;
			}
		}
		for (now = graph[i]; now->next != NULL; now = now->next)
		{
			if (now->vertex >= now->next->vertex)
			{
				temp = now->vertex;
				now->vertex = now->next->vertex;
				now->next->vertex = temp;
				//cout << i << "�࿡�� " << now->vertex << ' ' << now->next->vertex << "swap" << endl;
			}
		}
	}


	return;
}

void GraphList::DFS(int vert)
{
	Node  *now;
	check[vert] = true;
	cout << 'V' << vert;
	for (now = graph[vert]; now != NULL; now = now->next)
	{
		if (!check[now->vertex])
		{
			cout << " -> ";
			DFS(now->vertex);
		}
	}
}


void GraphList::BFS(int v)
{
	Node  *now;
	check[v] = true;
	Queue queue(MAX_VERTEX);
	queue.Enqueue(v);
	cout << v << ' ';

	while (!queue.isEmpty())
	{
		v = queue.Dequeue();
		for (now = graph[v]; now != NULL; now = now->next)
		{
			if (!check[now->vertex])
			{
				queue.Enqueue(now->vertex);
				check[now->vertex] = true;
				cout << now->vertex << ' ';
			}
		}
	}

}

bool Queue::isEmpty()
{
	if (front == rear)
		return true;
	else
		return false;
}

bool Queue::isFull()
{
	if (front == (rear + 1) % size)
		return true;
	else
		return false;
}

void Queue::Enqueue(int data)
{
	if (!isFull())
	{
		queue[rear] = data;
		rear = (rear + 1) % size;

	}
	else
		return;
}

int Queue::Dequeue()
{
	int temp = -1;

	if (!isEmpty())
	{
		temp = queue[front];
		queue[front] = NULL;
		front = (front + 1) % size;
		return temp;
	}
	else
		return temp;
}


void GraphList::primMethod1(int vert, int **lowCost)
{
	//Node  *now;
	int checkCount = 0;
	int vertIdx = vert;
	int end = 100;
	int min = 100;
	int sum = 0;
	int *lowCost1 = new int[vertexCnt];
	for (int i = 0; i < vertexCnt; i++)
	{
		lowCost1[i] = lowCost[vert][i];
		//cout << lowCost1[i]<< ' ';
	}
	check[vert] = true;
	checkCount++;

	while (checkCount != vertexCnt)
	{
		for (int i = 0; i < vertexCnt; i++)
		{
			if (lowCost[vertIdx][i] < min && check[i] != true)
			{
				min = lowCost[vertIdx][i];  // min�� ���ϱ�
				end = i;
			}
		}  // min �� ã��
		   //cout << "min:" << min << endl;
		check[end] = true;
		checkCount++;
		if (checkCount == vertexCnt)
			cout << vertIdx + 1 << ',' << end + 1;
		else
			cout << vertIdx + 1 << ',' << end + 1 << " -> ";

		for (int i = 0; i < vertexCnt; i++)
		{
			if (check[i] == true)
			{
				lowCost1[i] = 100;
			}
			else
			{
				lowCost1[i] = lowCost[end][i];
			}
			//cout <<lowCost1[i] << ' ';
		}
		sum += min;
		min = 100;
		vertIdx = end;
	}
	cout << endl;
	cout << "Weight: " << sum << endl;
	delete[]lowCost1;
	
	cout << endl;
}


void GraphList::primMethod2(int vert, int **lowCost)
{
	int checkCount = 0;
	int vertIdx = vert;
	int end = 0;
	int min = 100;
	int sum = 0;
	int *lowCost1 = new int[vertexCnt];
	int *lowWhere = new int[vertexCnt];
	for (int i = 0; i < vertexCnt; i++)
	{
		lowCost1[i] = lowCost[vert][i];
		lowWhere[i] = vert;
		//cout << lowCost1[i]<< ' ';
	} // ���� �޾ƿ�
	check2[vert] = true;
	checkCount++;

	while (checkCount != vertexCnt)
	{
		for (int i = 0; i < vertexCnt; i++)
		{
			if (lowCost1[i] < min && check2[i] != true)
			{
				min = lowCost1[i];  // min�� ���ϱ�
				end = i;
			}
		}  // min �� ã��
		   //cout << "min:" << min << endl;
		check2[end] = true;
		checkCount++;
		if (checkCount == vertexCnt)
			cout << lowWhere[end] + 1 << "," << end + 1;
		else
			cout << lowWhere[end] + 1 << "," << end + 1 << " -> ";



		for (int i = 0; i < vertexCnt; i++)
		{
			if (check2[i] == true)
			{
				lowCost1[i] = 100;
			}
			else if (lowCost1[i] > lowCost[end][i])
			{
				lowCost1[i] = lowCost[end][i];
				lowWhere[i] = end;
			}
			//cout << lowCost1[i] << ' ';
		}
		sum += min;
		min = 100;
		vertIdx = end;
	}
	cout << endl;
	cout << "Weight: " << sum << endl;
	delete[]lowCost1;
	cout << endl;
}