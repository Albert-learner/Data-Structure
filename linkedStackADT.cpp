#include "linkedStack.h"

void linkedStack::createStack()
{
	head = NULL;
}

int linkedStack::isEmpty()
{
	if (head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void linkedStack::push(int data)
{
	Node *temp = new Node(data);

	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

int linkedStack::pop()
{
	Node *p;
	int num;

	num = head->data;
	p = head;
	head = head->next;
	delete(p);
	return num;
}

void linkedStack::displayStack()
{
	Node *p;

	if (!isEmpty())
	{
		p = head;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << "\n";
	}
	else
	{
		cout << "Stack is Empty" << "\n";
	}
}
Node *linkedStack::invertStack(Node *head)
{
	Node *middle, *trail;
	middle = NULL;

	while (head)
	{
		trail = middle;
		middle = head;
		head = head->next;
		middle->next = trail;
	}
	return middle;
}

void linkedStack::searchStack(int data)
{
	Node *p;
	int pos=0;

	if (!isEmpty())
	{
		p = head;
		while (p != NULL)
		{
			if (p->data == data)
			{
				cout << p->data << " is at " << pos << " from head node." << "\n";
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
		cout << "Stack is Empty" << "\n";
		cout << "You could not find any data" << "\n";
	}
}