#include "LAB4_infix.h"

int Stack::isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

int Stack::isFull()
{
	if (top == MAX_STACK_SIZE - 1)
		return 1;
	else
		return 0;
}

void Stack::push(char num)
{
	if (isFull())
	{
		cout << "Stack is Full, push ERROR" << "\n";
		exit(1);
	}
	else
		stack[++top] = num;
}

char Stack::pop()
{
	if (isEmpty())
	{
		cout << "There`s no data in Stack, pop ERROR" << "\n";
		exit(1);
	}
	else
		return stack[top--];
}

void Stack::display()
{
	if (isEmpty())
	{
		cout << "There`s no data in Stack, you shouldn`t display any data" << "\n";
		exit(1);
	}
	else
	{
		for (int i = 0; i < top + 1; i++)
		{
			cout << stack[i] << ' ';
		}
		cout << "\n";
	}
}

void Stack::eval(char *input, int length)
{
	int result;
	int op1, op2;
	char arr[MAX_STACK_SIZE];

	for (int i = 0; i < length; i++)
	{
		if (isdigit(input[i]))
		{
			push(input[i]);
		}
		else
		{
			char op1 = pop()-48;
			char op2 = pop()-48;
			switch (input[i])
			{
			case '+':
				push(op1+op2+48);
				break;
			case '-':
				push(op1-op2+48);
				break;
			case '*':
				push(op1*op2+48);
				break;
			case '/':
				push(op1/op2+48);
				break;
			default:
				break;
			}
		}
	}
	result = pop() - 48;
	cout << " result = " << result;
}

int priority(char num)
{
	switch (num)
	{
	case ')':
		return 3;
		break;
	case '*':
	case '/':
		return 2;
		break;
	case '+':
	case '-':
		return 1;
		break;
	case '(':
		return 0;
		break;
	default:
		return 0;
		break;
	}
}