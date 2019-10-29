#include "CircularQueue.h"

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
	if ((rear + 1) % CIRCULARQUEUE_SIZE == front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CQueue::enQueue(char item)
{
	rear = (rear + 1) % CIRCULARQUEUE_SIZE;
	if (front == rear)
	{
		cout << "Queue is Full" << "\n";
		return ;
	}
	else
	{
		cqueue[rear] = item;
	}
}

char CQueue::deQueue()
{
	if (front == rear)
	{
		cout << "Queue is Empty" << "\n";
		return NULL;
	}
	else
	{
		front = (front + 1) % CIRCULARQUEUE_SIZE;
		int change = cqueue[front];
		return change;
	}
}

void CQueue::printQueue(){
	int i;
	if (front == rear + 1)
	{
		cout << "Queue is Empty" << "\n";
		return;
	}

	else
	{
		cout << "-- Print CircularQueue --" << "\n";
		i = front + 1;
		while (i != rear)
		{
			if (i == CIRCULARQUEUE_SIZE)
			{
				i = 0;
				if (i == rear)
					break;
			}
			cout << cqueue[i] << " ";
			i += 1;
		}
		cout << cqueue[rear];
		cout << "\n";
	}
}