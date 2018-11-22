#ifndef _MINHEAP_H__
#define _MINHEAP_H__
#define MAX_ELEMENTS 8

#include <iostream>

class MinHeap
{
private:
	int n;
	int maxsize;
	int heap[MAX_ELEMENTS];
public:
	MinHeap();
	bool isEmpty();
	bool isFull();
	void insert_minheap(int item);
	int delete_minheap();
	void display();
};
#endif // !_HEAP_H__

