#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;

#define SIZE 20

class Stack
{
private:
	int top;
	char stack[SIZE];

public:
	Stack()
	{
		top = -1;
	}
	int IsEmpty()
	{
		if (top == -1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int IsFull()
	{
		if (top == SIZE - 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void push(char item)
	{
		if (IsFull())
		{
			cout << "Stack is Full" << "\n";
			exit(1);
		}
		else
		{
			++top;
			stack[top] = item;
		}
	}

	char peek()
	{
		if (IsEmpty())
		{
			cout << "Stack is Empty" << "\n";
			exit(1);
		}
		return stack[top];
	}

	char pop()
	{
		if (IsEmpty())
		{
			cout << "Stack is Empty" << "\n";
			exit(1);
		}
		else
		{
			return stack[top--];
		}
	}
	void flush() 
	{
		top = -1;
	}
};

int main()
{
	ifstream fin;
	int count, i;
	int length = 0;
	bool check = true;
	Stack stack;
	fin.open("lab03_1.txt");

	if (fin.fail())
	{
		cout << "File open Error" << "\n";
		exit(1);
	}
	fin >> count;
	for (int q = 0; q < count; q++)
	{
		stack.flush();
		char line[20] = { '\0' };
		int k = 0;
		i = 0;
		fin >> line;
		while (line[k] != '\0') 
		{
			k++;
		}
		length = k;
		if (length % 2 == 0)
		{
			while (i < length / 2)
			{
				stack.push(line[i]);
				i++;
			}
		}
		else
		{
			while (i < length / 2)
			{
				stack.push(line[i]);
				i++;
			}
			i++;
		}
		
		for (i; i < length; i++)
		{
			if (stack.pop() != line[i])
			{
				check = false;
				break;
			}
		}
		if (check == true)
		{
			cout << "a palindrome" << "\n";
		}
		else
		{
			cout << "not a palindrome" << "\n";
		}
	}
	return 0;
}