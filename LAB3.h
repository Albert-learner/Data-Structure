#pragma once
#include <iostream>
using namespace std;

const int MAX_STACK_SIZE = 50;

class Stack
{
private:
	int top;
	char stack[MAX_STACK_SIZE];

public:
	Stack()
	{
		top = -1;
	}

	int IsEmpty()
	{
		if (top == -1)
			return 1;
		else
			return 0;
	}

	int IsFull()
	{
		if (top == MAX_STACK_SIZE - 1)
			return 1;
		else
			return 0;
	}

	void push(char e)
	{
		if (IsFull())
			exit(1);
		stack[++top] = e;
	}

	char pop()
	{
		if (IsEmpty())
			exit(1);
		return stack[top--];
	}
};