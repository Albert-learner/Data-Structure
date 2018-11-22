#include "MINHEAP.h"
using namespace std;

MinHeap::MinHeap()
{
	n = 0;
	maxsize = MAX_ELEMENTS;
}

bool MinHeap::isEmpty()
{
	return(n == 0);
}

bool MinHeap::isFull()
{
	return (n == MAX_ELEMENTS - 1);
}

void MinHeap::insert_minheap(int item)
{
	if (isFull())
	{
		cout << "Heap is full......\n";
		exit(1);
	}

	int i = ++n;

	while ((i != 1) && (item < heap[i / 2]))
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

int MinHeap::delete_minheap()
{
	int parent, child;
	int item, temp;

	if (isEmpty())
	{
		cout << "Heap is Empty" << endl;
		return -1;
	}

	item = heap[1];
	temp = heap[n--];
	parent = 1;
	child = 2;

	while (child <= n)
	{
		if ((child < n) && heap[child] > heap[child + 1])
			child++;
		if (temp <= heap[child])
			break;

		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}

	heap[parent] = temp;
	return item;
}

void MinHeap::display()
{
	if (isEmpty())
	{
		cout << "Heap is Empty" << endl;
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << heap[i] << ' ';
		cout << endl;
	}
}