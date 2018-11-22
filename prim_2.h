#pragma once
#define MAX_VERTEX 100

/******************************************************************************
class : Node
Description : 데이터의 저장 및 간선 정보
variables : int vertex : 데이터를 저장
Node* next : 다음 정점으로의 링크.
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
Description : 자료구조 그래프의 구현
variables : Node * graph[MAX_VERTEX] : 간선 정보를 저장할 배열
int vertexCnt : 정점의 갯수
int edgeCnt : 간선의 갯수
bool visited[MAX_VERTEX] : 탐색 시 탐색의 유무를 저장하는 배열
int matrix[][] : 인접 행렬을 구성할 배열

GraphList(int,int) : 생성자 함수. 정점,간선의 갯수 초기화와 배열 초기화.
void sort(int) : graph[MAX_VERTEX]에 담겨있는 정보를 오름차순 정렬.
void printMatrix() : 인접행렬을 출력한다.
void add(int,int) : 두 정점의 간선정보를 저장한다.
void BFS(int) : 너비우선탐색을 하는 함수.
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


