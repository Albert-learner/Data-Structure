#include <iostream>
#include <fstream>
using namespace std;

#define MAX_ELEMENTS 9

typedef struct
{
	int key;
}element;

element heap[MAX_ELEMENTS];
int n = 0;

void insert_maxheap(int item)
{
	if (n == MAX_ELEMENTS - 1)
	{
		cout << "Heap is full......\n";
		exit(1);
	}

	int I = ++(n);


	while ((I != 1) && (item > heap[I / 2].key))
	{
		heap[I] = heap[I / 2];
		I = I / 2;
	}
	heap[I].key = item;
}

element delete_maxheap()
{
	int parent, child;
	element item, temp;

	item = heap[1];
	temp = heap[n--];
	parent = 1;
	child = 2;

	while (child <= n)
	{
		if ((child < n) && heap[child].key < heap[child + 1].key)
			child++;
		if (temp.key >= heap[child].key)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	heap[n + 1].key = 0;
	return item;
}

bool empty_maxheap()
{
	return (n == 0);
}

bool full_maxheap()
{
	return (n == MAX_ELEMENTS - 1);
}

void print()
{
	int i;
	for (i = 0; i < MAX_ELEMENTS - 1; i++)
	{
		cout << heap[i].key << ' ';
	}
}

int search(element item, int data)
{
	int i;
	for (i = 0; i < MAX_ELEMENTS - 1; i++)
	{
		if (heap[i].key == data)
			return heap[i].key;
	}

}

int main()
{

	insert_maxheap(0);
	insert_maxheap(8);
	insert_maxheap(6);
	insert_maxheap(4);
	insert_maxheap(2);
	insert_maxheap(5);
	insert_maxheap(3);
	insert_maxheap(9);
	print();
	cout << endl;
	delete_maxheap();
	print();

	return 0;
}