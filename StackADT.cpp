#include "Stack.h"

bool Stack::IsEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Stack::IsFull()
{
	if (top == STACK_SIZE - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Stack::push(char item)
{
	if (IsFull())
	{
		cout << "Stack is Full" << "\n";
	}
	else
	{
		++top;
		stack[top] = item;
	}
}

char Stack::pop()
{
	if (IsEmpty())
	{
		cout << "Stack is Empty" << "\n";
		return NULL;
	}
	else
	{
		return stack[top--];
	}
}

void Stack::displayStack()
{
	int sp;
	if (IsEmpty())
	{
		cout << "Stack is Empty, nothing to display" << "\n";
	}
	else
	{
		sp = top;
		cout << "-- Print Stack --" << "\n";
		while (sp != -1)
		{
			cout << stack[sp] << ' ';
			--sp;
		}
		cout << "\n";
	}
}