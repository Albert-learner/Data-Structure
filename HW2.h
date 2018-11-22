#pragma once
#ifndef __HW2_H__
#define __HW2_H__


#include <string>
using namespace std;

typedef struct _node Node; //구조체 노드 형명 재지정

struct _node {        //노드 구조체(자기참조 구조체 사용)
	char Name;
	int ID;            //데이터 영역
	string major;
	char Grade;
	Node *next;     //포인터 영역
};

typedef struct _list {
	Node *head;
}List;

void createList(List *lp);
void addFirst(List *lp, char name, int ID, string major, char grade);
void displayList(List *lp);
void searchNode(List *lp, char grade);
void searchNode_3(List lp);

#endif