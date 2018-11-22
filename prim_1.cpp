#include "prim_1.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include <iostream>

using namespace std;

bool check[MAX_VERTEX] = { false, };
bool check2[MAX_VERTEX] = { false, };
/*--------------------------------------------------------------------------------------
함수명 및 기능: addNode() - 두 정점의 관계를 리스트에 등록함
전달인자:  g - 그래프 정보 구조체의 주소
vNum1 - 첫번째 정점의 번호
vNum2 - 두번째 정점이 번호
리턴값: 정점 등록이 성공하면 TRUE 리턴, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
bool GraphList::addNode(int vNum1, int vNum2, int cost)
{
	Node *newNode;
	newNode = new Node();  /* 새 간선 정보 노드 생성 */
	if (newNode == NULL) 
		return false;

	newNode->next = graph[vNum1];
	newNode->vertex = vNum2;
	newNode->cost = cost;
	graph[vNum1] = newNode;   /* 새로운 간선 정보 노드를 인접 리스트에 추가 */

							  /* 무방향 그래프에서의 대칭성(Symmetry) 고려하여 역 방향에 간선도 추가로 초기화 */
	newNode = new Node();  /* 새 간선 정보 노드 생성 */
	if (newNode == NULL)
	{
		free(graph[vNum1]);
		return false;
	}
	newNode->next = graph[vNum2];
	newNode->vertex = vNum1;
	newNode->cost = cost;
	graph[vNum2] = newNode;   /* 새로운 간선 정보 노드를 인접 리스트에 추가 */
							  //cout << "ADD 성공" << endl;
	return true;
}

/*--------------------------------------------------------------------------------------
함수명 및 기능: outputGraph_L() - 그래프내의 정점과 간선의 관계를 인접 리스트 형태로 출력
전달인자:  g : 그래프 정보 구조체의 주소
리턴값: 없음
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
함수명 및 기능: outputGraph_L() - 그래프내의 정점과 간선의 관계를 인접 리스트 형태로 출력
전달인자:  g : 그래프 정보 구조체의 주소
리턴값: 없음
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
	} // 배열 할당 및 초기화
	Node *now;
	int count = 1;
	/*for (int j = 0; j < vertexCnt; j++)
	{
	//cout << " V" << count++;
	} */// 배열 형식 출력

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
	} // 배열 할당 및 초기화
}

/*--------------------------------------------------------------------------------------
함수명 및 기능: destroyGraph_L() - 그래프내의 정점 노드 모두 삭제
전달인자:
리턴값: 없음
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
				//cout <<i<<"행에서 " <<now->vertex << ' ' << now->next->vertex << "swap" << endl;
			}
		}
		for (now = graph[i]; now->next != NULL; now = now->next)
		{
			if (now->vertex >= now->next->vertex)
			{
				temp = now->vertex;
				now->vertex = now->next->vertex;
				now->next->vertex = temp;
				//cout << i << "행에서 " << now->vertex << ' ' << now->next->vertex << "swap" << endl;
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
				min = lowCost[vertIdx][i];  // min값 구하기
				end = i;
			}
		}  // min 값 찾기
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
	} // 값을 받아옴
	check2[vert] = true;
	checkCount++;

	while (checkCount != vertexCnt)
	{
		for (int i = 0; i < vertexCnt; i++)
		{
			if (lowCost1[i] < min && check2[i] != true)
			{
				min = lowCost1[i];  // min값 구하기
				end = i;
			}
		}  // min 값 찾기
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