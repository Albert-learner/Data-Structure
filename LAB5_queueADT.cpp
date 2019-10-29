#include "LAB5_queue.h"

bool Queue::isEmpty()
{
	if (front == rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Queue::isFull()
{
	if (rear == MAX_SIZE - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Queue::enQueue(int value)
{
	if (isFull())
	{
		cout << "Queue is Full" << "\n";
		exit(1);
	}
	else
	{
		++rear;
		queue[rear] = value;
	}
}

int Queue::deQueue()
{
	if (isEmpty())
	{
		cout << "Queue is Empty" << "\n";
		exit(1);
	}
	else
	{
		++front;
		return queue[front];
	}
}

void Queue::printQueue()
{
	int i;

	if (isEmpty())
	{
		cout << "Queue is Empty" << "\n";
	}
	else
	{
		i = front + 1;
		cout << "-- Print Queue -- " << "\n";
		while (i <= rear)
		{
			cout << queue[i]<<' ';
			i += 1;
		}
	}
}