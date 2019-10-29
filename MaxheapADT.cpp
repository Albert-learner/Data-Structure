#include "MaxHeap.h"

MaxHeap::MaxHeap()
{
	n = 0;
	maxsize = MAX_ELEMENTS;
}

bool MaxHeap::isEmpty()
{
	return n == 0;
}

bool MaxHeap::isFull()
{
	return n == MAX_ELEMENTS - 1;
}

void MaxHeap::insert_maxheap(int item)
{
	if (isFull())
	{
		cout << "Heap is Full......, so you couldn`t insert" << "\n";
		exit(1);
	}
	else
	{
		int i = ++n;

		while ((i != 1) && (item > heap[i / 2]))
		{
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i] = item;
	}
}

int MaxHeap::delete_maxheap()
{
	int parent, child;
	int item, temp;

	if (isEmpty())
	{
		cout << "Heap is Empty...... so you couldn`t delete" << "\n";
		return -1;
	}
	else
	{
		item = heap[1];
		temp = heap[n--];
		parent = 1;
		child = 2;

		while (child <= n)
		{
			if ((child < n) && (heap[child] < heap[child + 1]))
			{
				child++;
			}
			if (temp >= heap[child])
			{
				break;
			}
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
		heap[parent] = temp;
		return item;
	}
}

void MaxHeap::display()
{
	if (isEmpty())
	{
		cout << "Heap is Empty... so you couldn`t display" << "\n";
		return ;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			cout << heap[i] << ' ';
		}
		cout << endl;
	}
}

void MaxHeap::level()
{
	int pos = 1;
	int nn = n;
	if (isEmpty())
	{
		cout << "Heap is Empty, so level is none" << endl;
	}
	else
	{
		if (nn % 2 == 0)
		{
			while (nn != 1)
			{
				nn /= 2;
				pos++;
			}
			cout << "Heap level is " << pos << endl;
		}
		else
		{
			while (nn != 1)
			{
				nn /= 2;
				pos++;
			}
			cout << "Heap level is " << pos << endl;
		}
	}
}