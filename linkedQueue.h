#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	Node *next;

	Node(int value)
	{
		data = value;
		next = NULL;
	}
	friend class linkedQueue;
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