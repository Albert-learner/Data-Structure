#include "prim_2.h" 
#include <iostream>

using namespace std;

/********************************************************************************
Function : add
Description : 두 정점에 관한 간선정보를 저장한다.
variables : int vNum1 , vNum2 : 두 정점의 값.
*********************************************************************************/
void GraphList::add(int vNum1, int vNum2, int cost)
{
	Node *p;
	p = new Node();

	p->cost = cost;
	p->next = graph[vNum1];
	p->vertex = vNum2;
	graph[vNum1] = p;


	p = new Node();

	p->cost = cost;
	p->next = graph[vNum2];
	p->vertex = vNum1;
	graph[vNum2] = p;

	matrix[vNum1][vNum2] = 1;
	matrix[vNum2][vNum1] = 1;
	costList[vNum1][vNum2] = cost;
	costList[vNum2][vNum1] = cost;
}

void GraphList::print()
{
	Node *now;
	for (int i = 0; i<vertexCnt; ++i)
	{
		cout << 'V' << i << ":  ";
		for (now = graph[i]; now != NULL; now = now->next)
		{
			cout << now->vertex;
			if (now->next != NULL)
				cout << " -> ";
		}
		cout << endl;
	}
}

/********************************************************************************
Function : sort
Description : 간선정보가 담겨있는 graph배열을 정렬한다.
variables: int numV : 정렬을 시작하는 노드
*********************************************************************************/
void GraphList::sort(int numV)
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
			}
		}
		for (now = graph[i]; now->next != NULL; now = now->next)
		{
			if (now->vertex >= now->next->vertex)
			{
				temp = now->vertex;
				now->vertex = now->next->vertex;
				now->next->vertex = temp;
			}
		}

	}


	return;
}

void GraphList::DFS(int vert)
{
	Node  *now;
	visited[vert] = true;
	cout << 'V' << vert << ' ';
	for (now = graph[vert]; now != NULL; now = now->next)
	{
		if (!visited[now->vertex]) {
			cout << "-> ";
			DFS(now->vertex);
		}
	}


}
/*********************************************************************************
Function : printMatrix
Description : 그래프의 내용을 담은 인접 행렬을 출력한다.
variables : int matrix [][] : 인접 행렬 정보를 담은 배열
**********************************************************************************/
void GraphList::printMatrix() {
	cout << "   ";
	for (int i = 0; i < 8; i++) {
		cout << 'V' << i << ' ';
	}
	cout << endl;

	for (int i = 0; i < 8; i++) {
		cout << 'V' << i << ' ';
		for (int j = 0; j < 8; j++) {
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
}

void GraphList::primGreedy(int vert) {
	int v = vert;
	int visitedcnt = 1;
	visitedP[vert] = true;

	while (visitedcnt != vertexCnt) {
		if (visitedcnt != 1) {
			cout << "-> ";
		}
		int min = costList[v][0];
		int mininx = 0;
		for (int i = 1; i < vertexCnt + 1; i++) {
			if (min > costList[v][i] && !visitedP[i]) { //값이 더 작고, 방문하지 않았다면
				min = costList[v][i];
				mininx = i;
			}
		}
		cout << "(" << v << "," << mininx << ") ";
		visitedP[mininx] = true;
		v = mininx;
		visitedcnt++;
	}
	cout << endl;

}

void GraphList::prim(int vert) {
	int v = vert;
	int visitedcnt = 1;
	int lowcost[MAX_VERTEX];
	int lowwhere[MAX_VERTEX];
	int visitedP2[MAX_VERTEX] = { false, };
	visitedP2[vert] = true;
	for (int i = 0; i < vertexCnt + 1; i++) {
		lowcost[i] = costList[v][i];
		lowwhere[i] = v; // 출발 노드를 알려주는 배열
	}

	while (visitedcnt < vertexCnt) {
		if (visitedcnt != 1) {
			cout << "-> ";
		}
		int min = 9999;
		int mininx = 0;
		for (int i = 0; i < vertexCnt + 1; i++) {
			if (min > lowcost[i] && !visitedP2[i]) {
				min = lowcost[i];
				mininx = i;
			}
		}
		cout << "(" << lowwhere[mininx] << "," << mininx << ") ";
		visitedP2[mininx] = true;

		//lowcost 배열 업데이트. 가장 작은 값들로 업데이트, lowwhere배열도 같이 업데이트한다.
		for (int i = 0; i < vertexCnt + 1; i++) {
			if (lowcost[i] > costList[mininx][i] && !visitedP2[i]) {
				lowcost[i] = costList[mininx][i];
				lowwhere[i] = mininx;
			}
		}
		v = mininx;
		visitedcnt++;
	}

	cout << endl;

}

void GraphList::printCost() {
	cout << "    ";
	for (int i = 1; i < vertexCnt + 1; i++) {
		cout << 'v' << i << " ";
	}
	cout << endl;
	for (int i = 1; i < vertexCnt + 1; i++) {
		cout << 'v' << i << ' ';
		for (int j = 1; j < vertexCnt + 1; j++) {
			cout << costList[i][j] << "  ";
		}
		cout << endl;
	}
}