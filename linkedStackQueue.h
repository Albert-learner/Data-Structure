#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
	char data;
	Node *next;

	Node(char value)
	{
		data = value;
		next = NULL;
	}
	friend class linkedStack;
	friend class linkedQueue;
};

class linkedStack
{
private:
	Node *head;

public:
	linkedStack()
	{
		head = NULL;
	}

	Node *getHead()
	{
		return head;
	}
	void createStack();
	int isEmpty();
	void push(int data);
	int pop();
	void displayStack();
	Node *invertStack(Node *head);
	void searchStack(int data);
	void invert()
	{
		head = invertStack(head);
	}
};

class linkedQueue
{
private:
	Node *front;
	Node *rear;

public:
	linkedQueue()
	{
		front = 0;
		rear = 0;
	}

	int isEmpty();
	void enQueue(int data);
	int deQueue();

	void displayQueue();
	void searchQueue(int data);
};


