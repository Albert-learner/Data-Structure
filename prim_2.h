#pragma once
#define MAX_VERTEX 100

/******************************************************************************
class : Node
Description : �������� ���� �� ���� ����
variables : int vertex : �����͸� ����
Node* next : ���� ���������� ��ũ.
*******************************************************************************/
class Node
{
public:
	int vertex;
	Node *next;
	int cost;
};

/********************************************************************************
class : GraphList
Description : �ڷᱸ�� �׷����� ����
variables : Node * graph[MAX_VERTEX] : ���� ������ ������ �迭
int vertexCnt : ������ ����
int edgeCnt : ������ ����
bool visited[MAX_VERTEX] : Ž�� �� Ž���� ������ �����ϴ� �迭
int matrix[][] : ���� ����� ������ �迭

GraphList(int,int) : ������ �Լ�. ����,������ ���� �ʱ�ȭ�� �迭 �ʱ�ȭ.
void sort(int) : graph[MAX_VERTEX]�� ����ִ� ������ �������� ����.
void printMatrix() : ��������� ����Ѵ�.
void add(int,int) : �� ������ ���������� �����Ѵ�.
void BFS(int) : �ʺ�켱Ž���� �ϴ� �Լ�.
*********************************************************************************/

class GraphList
{
public:
	Node * graph[MAX_VERTEX];
	int vertexCnt;
	int edgeCnt;
	bool visited[MAX_VERTEX] = { false, };
	bool visitedP[MAX_VERTEX] = { false, };
	int matrix[9][9] = { 0, };
	int costList[MAX_VERTEX][MAX_VERTEX];

	GraphList(int vert, int edge)
	{
		vertexCnt = vert;
		edgeCnt = edge;

		for (int i = 0; i < vertexCnt; ++i) {
			graph[i] = 0;
		}

		for (int i = 0; i < vertexCnt + 1; i++) {
			for (int j = 0; j < vertexCnt + 1; j++) {
				costList[i][j] = 100;
			}

		}



	}

	void sort(int numV);
	void print();
	void add(int vNum1, int vNum2, int cost);
	void DFS(int vert);
	void printMatrix();
	void primGreedy(int vert);
	void prim(int vert);
	void printCost();
};


