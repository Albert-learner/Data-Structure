#pragma once
//ArrayStack.h : 배열을 이용한 int 스택 클래스
#include <cstdio> //C 헤더파일 <stdio.h>을 포함하는 것과 동일
#include <cstdlib> // C 헤더파일 <stdlib.h>을 포함하는 것과 동일

char errorM[30] = "스택 포화 메시지!";
char errorM1[30] = "스택 없음 메시지!";

//오류 처리 함수
inline void error(char *message)
{
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 20; //스택의 최대 크기 설정
class ArrayStack
{
	int top; //요소의 개수
	int data[MAX_STACK_SIZE]; //요소의 배열

public:
	ArrayStack() { top = -1; } //스택 생성자(ADT의 create()역할)
	~ArrayStack(){} //스택 소멸자
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE-1; }

	void push(int e)  //맨 위에 항목 삽입
	{
		if (isFull())
			error(errorM);
		data[++top] = e;
	}

	int pop() // 맨 위의 요소를 삭제하고 반환
	{
		if (isEmpty())
			error(errorM);
		return data[top--];
	}

	int peek() // 삭제하지 않고 요소 반환
	{
		if (isEmpty())
			error(errorM1);
		return data[top];
	}

	void display()
	{
		printf("[스택 항목의 수 = %2d] ==> ", top + 1);
		for (int i = 0; i <= top; i++)
			printf("<%2d>", data[i]);
		printf("\n");
	}
};