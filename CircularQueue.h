#pragma once
#include <iostream>
using namespace std;

const int CIRCULARQUEUE_SIZE = 3;

class CQueue
{
private:
	int front;
	int rear;
	char cqueue[CIRCULARQUEUE_SIZE];

public:
	CQueue()
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