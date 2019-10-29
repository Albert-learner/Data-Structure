#include "linkedQueue.h"

int linkedQueue::isEmpty()
{
	if (front == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void linkedQueue::enQueue(int data)
{
	Node *temp = new Node(data);

	if (isEmpty())
	{
		front = temp;
		rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}

int linkedQueue::deQueue()
{
	Node *p;
	int num;

	num = front->data;
	p = front;

	if (front == rear)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		front = front->next;
	}
	
	delete(p);
	return num;
}

void linkedQueue::displayQueue()
{
	Node *p;

	if (!isEmpty())
	{
		p = front;
		while (p)
		{
			cout << p->data << ' ';
			p = p->next;
		}
		cout << "\n";
	}
	else
	{
		cout << "Queue is Empty" << "\n";
	}
}

void linkedQueue::searchQueue(int data)
{
	Node *p;
	int pos = 0;

	if (!isEmpty())
	{
		p = front;
		while (p != rear)
		{
			if (p->data == data)
			{
				cout << p->data << " is at " << pos << " from front node." << "\n";
				break;
			}
			else
			{
				pos++;
				p = p->next;
			}
		}
	}
	else
	{
		cout << "Queue is Empty" << "\n";
		cout << "You could not find any data" << "\n";
	}
}