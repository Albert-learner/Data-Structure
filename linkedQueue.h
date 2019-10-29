#pragma once
#include <iostream>
using namespace std;

class QNode
{
private:
	char data;
	Node *next;

	QNode(char value)
	{
		data = value;
		next = NULL;
	}
	friend class linkedQueue;
};

class linkedQueue
{
private:
	QNode *front;
	QNode *rear;

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