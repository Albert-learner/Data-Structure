#pragma once
#include <iostream>
using namespace std;

typedef int Type;

class Node
{
private:
	int val;
	Node *next;
	Node *prev;

	Node(Type data)
	{
		val = data;
		next = NULL;
		prev = NULL;
	}
	friend class List;
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
	int isEmpty();
	void insertList(int);
	void deleteList(int);
	void forwardList();
	void backwardList();
	void searchList(int);
	int listLength();
	void locateCurrent(int);

	~List()
	{
		Node *p;

		while (head != NULL)
		{
			p = head;
			head = head->next;
			delete p;
		}
	}
};