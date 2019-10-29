#pragma once
#include <iostream>
using namespace std;

const int STACK_SIZE = 2;

class Stack
{
private:
	int top;
	char stack[STACK_SIZE];

public:
	Stack()
	{
		top = -1;
	}
	bool IsEmpty();
	bool IsFull();
	void push(char item);
	char pop();
	void displayStack();
};