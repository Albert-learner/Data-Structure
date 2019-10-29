#include "Queue.h"

bool Queue::IsEmpty()
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

bool Queue::IsFull()
{
	if (rear == QUEUE_SIZE - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Queue::enQueue(char item)
{
	if (IsFull())
	{
		cout << "Queue is Full" << "\n";
		return ;
	}
	else
	{
		++rear;
		queue[rear] = item;
	}
}

char Queue::deQueue()
{
	if (IsEmpty())
	{
		cout << "Queue is Empty" << "\n";
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

	if (IsEmpty())
	{
		cout << "Queue is Empty, nothing to display" << "\n";
	}
	else
	{
		i = front + 1;
		cout << "-- Print Queue --" << "\n";
		while (i <= rear)
		{
			cout << queue[i] << ' ';
			i += 1;
		}
		cout << "\n";
	}
}