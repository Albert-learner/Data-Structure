#pragma once

#include <iostream>
#include <string>
using namespace std;

const int MAX_STACK_SIZE = 50;

//stack ADT 선언, char형으로 키보드로 입력받아서 처리합니다.
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
	//스택에 저장되어 있는 값들 출력하는 함수
	void display();
	//배열과 postfix연산자 수를 입력받아 값을 계산해서 출력하는 함수
	void eval(char *input, int b);
};

//연산자의 우선순위를 비교하기 위해 구현한 함수
int priority(char num);
