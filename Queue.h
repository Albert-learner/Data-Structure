#pragma once
#include <iostream>
using namespace std;

const int QUEUE_SIZE = 3;

class Queue
{
private:
	int front;
	int rear;
	char queue[QUEUE_SIZE];

public:
	Queue()
	{
		front = -1;
		rear = -1;
	}
	bool IsEmpty();
	bool IsFull();
	void enQueue(char item);
	char deQueue();
	void printQueue();
};