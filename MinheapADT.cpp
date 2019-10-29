#include "Minheap.h"

Minheap::Minheap()
{
	n = 0;
	maxsize = MAX_ELEMENTS;
}

bool Minheap::isEmpty()
{
	return (n == 0);
}

bool Minheap::isFull()
{
	return (n == MAX_ELEMENTS - 1);
}

void Minheap::insert_minheap(int item)
{
	if (isFull())
	{
		cout << "Heap is Full, so you couldn`t insert item..." << endl;
		return ;
	}
	else
	{
		int i = ++n;

		while ((i != 1) && (item < heap[i / 2]))
		{
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i] = item;
	}
}

int Minheap::delete_minheap()
{
	int parent, child;
	int item, tmp;

	if (isEmpty())
	{
		cout << "Heap is Empty, so you couldn`t delete item..." << endl;
		return -1;
	}
	else
	{
		item = heap[1];
		tmp = heap[n--];
		parent = 1;
		child = 2;

		while (child <= n)
		{
			if ((child < n) && (heap[child] > heap[child + 1]))
			{
				child++;
			}
			if (tmp <= heap[child])
			{
				break;
			}

			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
		heap[parent] = tmp;
		return item;
	}
}

void Minheap::display()
{
	if (isEmpty())
	{
		cout << "Heap is Empty, so you couldn`t display item..." << endl;
		return ;
	}
	else
	{
		cout << "(";
		for (int i = 1; i <= n; i++)
		{
			if (i != n)
			{
				cout << heap[i] << ' ';
			}
			else
			{
				cout << heap[i] << ")";
			}
		}
		cout << endl;
	}
}

void Minheap::level()
{
	int pos = 1;
	int nn = n;

	if (isEmpty())
	{
		cout << "Heap is Empty, so level is none..." << endl;
		return ;
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