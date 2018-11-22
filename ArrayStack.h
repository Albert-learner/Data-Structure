#pragma once
//ArrayStack.h : �迭�� �̿��� int ���� Ŭ����
#include <cstdio> //C ������� <stdio.h>�� �����ϴ� �Ͱ� ����
#include <cstdlib> // C ������� <stdlib.h>�� �����ϴ� �Ͱ� ����

char errorM[30] = "���� ��ȭ �޽���!";
char errorM1[30] = "���� ���� �޽���!";

//���� ó�� �Լ�
inline void error(char *message)
{
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 20; //������ �ִ� ũ�� ����
class ArrayStack
{
	int top; //����� ����
	int data[MAX_STACK_SIZE]; //����� �迭

public:
	ArrayStack() { top = -1; } //���� ������(ADT�� create()����)
	~ArrayStack(){} //���� �Ҹ���
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE-1; }

	void push(int e)  //�� ���� �׸� ����
	{
		if (isFull())
			error(errorM);
		data[++top] = e;
	}

	int pop() // �� ���� ��Ҹ� �����ϰ� ��ȯ
	{
		if (isEmpty())
			error(errorM);
		return data[top--];
	}

	int peek() // �������� �ʰ� ��� ��ȯ
	{
		if (isEmpty())
			error(errorM1);
		return data[top];
	}

	void display()
	{
		printf("[���� �׸��� �� = %2d] ==> ", top + 1);
		for (int i = 0; i <= top; i++)
			printf("<%2d>", data[i]);
		printf("\n");
	}
};