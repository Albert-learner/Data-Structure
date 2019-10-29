#pragma once
#include <string>
#include <iostream>
using namespace std;

typedef struct _node Node;

struct _node
{
	char Name;
	int ID;
	string major;
	char Grade;
	Node *next;
};

typedef struct _list
{
	Node *head;
}List;

void createList(List *lp);
void addFirst(List *lp, char name, int ID, string major, char grade);
void displayList(List *lp);
void searchNode(List *lp, char grade);
void searchNode_pos(List lp);