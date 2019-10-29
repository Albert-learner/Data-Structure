#include <iostream>
using namespace std;
#define STACK_SIZE 100
#define MAX_SIZE 10

class Stack
{
private :
	int top[MAX_SIZE];
	int bottom[MAX_SIZE+1];
	int stack[STACK_SIZE];
	int a;

public:
	Stack(int a)
	{
		top[0] = 0;
		bottom[0] = 0;
		for (int i = 1; i < a; i++)
		{
			top[i] = (MAX_SIZE / a)*i;
		}
		bottom[a] = STACK_SIZE - 1;
	}
	int isEmpty(int num)
	{
		
	}
	int isFull(int num)
	{
		
	}
	int isKEmpty(int num)
	{
		if (top[num] == bottom[num])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int isKFull(int num)
	{
		if (top[num] == bottom[num + 1])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void Add(int num, int item)
	{
		if (isKFull(num))
		{
			isFull(num);
		}
		else
		{
			++top[num];
			stack[top[num]] = item;
		}
	}
	int Delete(int num)
	{
		if (isKEmpty(num))
		{
			isEmpty(num);
		}
		else
		{
			return stack[top[num] - 1];
		}
	}
};

int main()
{

	return 0;
}