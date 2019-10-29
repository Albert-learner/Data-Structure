#pragma once
#include <iostream>
using namespace std;

typedef struct _node Node;

struct _node
{
	int data;
	Node *next;
};

class List
{
private:
	Node *head;

public:
	List()
	{
		head = NULL;
	}
	bool isEmpty();
	void insertNode(int cost);
	void appendNode(int cost);
	void deleteNode(int cost);
	void searchNode(int cost);
	void searchNode_pos(int cost);
	Node *invertList(Node *head);
	void invert()
	{
		head = invertList(head);
	}
	void traverseList();
	void printLast();
	~List();
};