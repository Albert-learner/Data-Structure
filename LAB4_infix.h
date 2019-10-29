#pragma once

#include <iostream>
#include <string>
using namespace std;

const int MAX_STACK_SIZE = 50;

//stack ADT ����, char������ Ű����� �Է¹޾Ƽ� ó���մϴ�.
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

	int isEmpty();
	int isFull();
	void push(char num);
	char pop();
	//���ÿ� ����Ǿ� �ִ� ���� ����ϴ� �Լ�
	void display();
	//�迭�� postfix������ ���� �Է¹޾� ���� ����ؼ� ����ϴ� �Լ�
	void eval(char *input, int b);
};

//�������� �켱������ ���ϱ� ���� ������ �Լ�
int priority(char num);
