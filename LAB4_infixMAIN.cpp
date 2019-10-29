#include "LAB4_infix.h"


int main()
{
	char data[MAX_STACK_SIZE];
	char postfix[MAX_STACK_SIZE];
	Stack stack;
	int size, post_cnt=0;

	cout << "Enter data : ";
	cin >> data;
	cout << "\n";

	cout << "1) Echo data(infix form) : ";
	cout << data << ' ' << "\n";
	cout << "\n";

	size = strlen(data);
	cout << "2) Conversion (postfix form) : ";
	
	for (int i = 0; i < size; i++)
	{
		if (isdigit(data[i]))
		{
			postfix[post_cnt++] = data[i];
		}
		else if(data[i] == '$')
		{
			postfix[post_cnt] = NULL;
			while (!stack.isEmpty())
			{
				char cost = stack.pop();
				postfix[post_cnt] = cost;
				post_cnt++;
			}
		}
		else
		{
			if (stack.isEmpty())
			{
				stack.push(data[i]);
			}
			else
			{
				if (data[i] == '(')
				{
					stack.push(data[i]);
				}
				else if(data[i] == ')')
				{
					while (1)
					{
						char cost1 = stack.pop();
						if (cost1 == '(')
						{
							break;
						}
						else
						{
							postfix[post_cnt] = cost1;
							post_cnt++;
						}
					}
				}
				else
				{
					char crit = stack.pop();
					if (priority(crit) <= priority(data[i]))
					{
						stack.push(crit);
						stack.push(data[i]);
					}
					else
					{
						while (!stack.isEmpty() && (priority(crit) > priority(data[i])))
						{
							postfix[post_cnt] = crit;
							stack.push(data[i]);
							post_cnt++;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < post_cnt; i++)
	{
		cout << postfix[i] << ' ';
	}
	cout << "\n";

	cout << "\n";
	cout << "3) Result(extra point) :";
	stack.eval(postfix, post_cnt);
	return 0;
}