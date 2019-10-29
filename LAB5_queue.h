#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Queue
{
private:
	int front;
	int rear;
	int queue[MAX_SIZE];

public:
	Queue()
	{
		front = -1;
		rear = -1;
	}
	bool isEmpty();
	bool isFull();
	void enQueue(int value);
	int deQueue();
	void printQueue();
};
