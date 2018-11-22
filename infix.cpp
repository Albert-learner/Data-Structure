#include <iostream>
#include <cstring>

using namespace std;

void create_stack();
void push(char num);
int pop();
int prior(char num);
int isEmpty();

const int Stacksize = 100;
char stack[Stacksize]; //스택
char postfix[Stacksize];  //postfix가 실행된 결과를 저장하는 배열
int top;

int main()
{
	char input[100];
	int temp;
	int index = 0;
	int j = 0;

	create_stack(); //스택 생성

	cout << "수식을 입력하세요." << endl;
	cin >> input;

	temp = strlen(input);

	while (j != temp)
	{

		if (isdigit(input[j]) == 1) //숫자일떄
		{
			postfix[index++] = input[j]; //숫자일 떄는 배열에 숫자를 저장
			j++;
		}

		else if (input[j] == '(')   //좌괄호일떄
		{
			push(input[j]);
			j++;
		}

		else if (input[j] == ')') //우괄호일때
		{


			while (stack[top] != '(')  //좌괄호가 나올때까지 pop
			{
				postfix[index++] = pop();
			}

			pop(); //좌괄호를 버린다

			j++;

		}
		else   //연산자일떄
		{
			if (prior(stack[top]) <= prior(input[j]))//스택의 top에 있는 연산자 우선순위가
			{                                        //input값보다 작은경우 push
				push(input[j]);
			}
			else
			{
				while (!isEmpty() && (prior(stack[top]) >= prior(input[j])))
				{                                       //스택의 top에 있는 연산자 우선순위가
														//input값보다 큰 경우 pop

					postfix[index++] = pop();

				}
				push(input[j]); //input값은 push

			}
			j++;
		}

	}


	while (!isEmpty()) //스택에 데이터가 남아있으면 전부 pop
	{
		postfix[index++] = pop();
	}

	cout << input << endl;

	for (int x = 0; x < index; x++)
		cout << postfix[x];

	cout << endl;


	return 0;
}



void create_stack()   //스택생성하는 함수
{
	top = -1;
}

void push(char num)  // push함수
{
	++top;
	stack[top] = num;
}

int pop() //pop함수
{
	return stack[top--];
}

int prior(char num)  //연산자 우선순위를 확인하는 함수
{

	switch (num)   //리턴값이 큰 수가 우선순위가 위에 있다.
	{
	case ')':
		return 3;
		break;
	case '*': case '/':
		return 2;
		break;
	case '+': case '-':
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

int isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}
