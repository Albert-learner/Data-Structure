#pragma once
#define MAX_ELEMENTS 8

#include <iostream>
using namespace std;

class Minheap
{
private:
	int n;
	int maxsize;
	int heap[MAX_ELEMENTS];

public:
	Minheap();
	bool isEmpty();
	bool isFull();
	void insert_minheap(int item);
	int delete_minheap();
	void display();
	void level();
};