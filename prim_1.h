#pragma once
#define MAX_VERTEX 100

extern bool check[MAX_VERTEX];
/*---------------------------------------------
GraphList 처리 구조체 및 활용 함수
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
	Node * graph[MAX_VERTEX];  /* 인접 리스트 표기 배열 - Node 포인터 배열 */
	int vertexCnt;    /* 정점 개수 */
	int edgeCnt;      /* 간선 개수 */

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
	void outputGraph_List(); /* 그래프내의 정점과 간선의 관계를 인접 리스트 형태로 출력 */
	bool addNode(int vNum1, int vNum2, int cost); /* 두 정점의 관계를 리스트에 등록함 */
	void destroyGraph_List(); /* 그래프내의 정점 노드 모두 삭제 */
	void DFS(int vert);
	void BFS(int vert);
	void primMethod1(int vert, int**);
	void primMethod2(int vert, int**);

	friend class Queue;
};


