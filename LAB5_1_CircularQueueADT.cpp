#include "LAB5_1_CircularQueue.h"

bool CQueue::IsEmpty()
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

bool CQueue::IsFull()
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

void CQueue::enQueue(int value)
{
	rear = (rear + 1) % MAX_SIZE;
	if (IsFull())
	{
		cout << "Queue is Full" << "\n";
		exit(1);
	}
	else
	{
		queue[rear] = value;
	}
}

int CQueue::deQueue()
{
	if (IsEmpty())
	{
		cout << "Queue is Empty" << "\n";
		exit(1);
	}
	else
	{
		front = (front + 1) % MAX_SIZE;
		int change = queue[front];
		queue[front] = 0;
		return change;
	}
}

void CQueue::printCQueue()
{
	int i;
	if (IsEmpty())
	{
		cout << "Queue is Empty" << "\n";
	}
	else
	{
		cout << "-- Print CircularQueue --" << "\n";
		i = front + 1;
		while (i != rear)
		{
			if (i == MAX_SIZE)
			{
				i = 0;
				if (i == rear)
					break;
			}
			cout << queue[i] << " ";
			i += 1;

		}
		cout << queue[rear];
		cout << "\n";
	}
}