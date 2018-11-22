#pragma once
#define MAX_VERTEX 100

extern bool check[MAX_VERTEX];
/*---------------------------------------------
GraphList ó�� ����ü �� Ȱ�� �Լ�
----------------------------------------------*/
class Node
{
public:
	int vertex;
	int cost;
	Node *next;
};

class Queue
{
public:
	int *queue;
	int front;
	int size;
	int rear;

	Queue(int sizeNum)
	{
		queue = new int[sizeNum];
		front = 0;
		size = sizeNum;
		rear = 0;
	}
	bool isEmpty();
	bool isFull();
	void Enqueue(int data);
	int Dequeue();
	friend class GraphList;
};

class GraphList
{
public:
	Node * graph[MAX_VERTEX];  /* ���� ����Ʈ ǥ�� �迭 - Node ������ �迭 */
	int vertexCnt;    /* ���� ���� */
	int edgeCnt;      /* ���� ���� */

	GraphList(int vert, int edge)
	{
		vertexCnt = vert;
		edgeCnt = edge;

		for (int i = 0; i<vertexCnt; ++i)
			graph[i] = 0;
	}

	void initGraph_List(int numV);
	void sortGraph_List(int numV);
	void outputGraph_Array(int **);
	void outputGraph_List(); /* �׷������� ������ ������ ���踦 ���� ����Ʈ ���·� ��� */
	bool addNode(int vNum1, int vNum2, int cost); /* �� ������ ���踦 ����Ʈ�� ����� */
	void destroyGraph_List(); /* �׷������� ���� ��� ��� ���� */
	void DFS(int vert);
	void BFS(int vert);
	void primMethod1(int vert, int**);
	void primMethod2(int vert, int**);

	friend class Queue;
};


