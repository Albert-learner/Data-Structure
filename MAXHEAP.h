#ifndef _HEAP_H__
#define _HEAP_H__
#define MAX_ELEMENTS 9

#include <iostream>

class MaxHeap
{
private:
	int n;
	int maxsize;
	int heap[MAX_ELEMENTS];
public:
	MaxHeap();
	bool isFull();
	bool isEmpty();
	void insert_maxheap(int item);
	int delete_maxheap();
	void level();
	void display();
};
#endif