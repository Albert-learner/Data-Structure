#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class CQueue
{
private:
	int front;
	int rear;
	int queue[MAX_SIZE];

public:
	CQueue()
	{
		front = -1;
		rear = -1;
	}
	bool IsEmpty();
	bool IsFull();
	void enQueue(int value);
	int deQueue();
	void printCQueue();
};