#pragma once
#include <iostream>
using namespace std;

enum BOOL{FALSE, TRUE};

typedef struct
{
	short int row; //행(가로좌표)
	short int col; //열(세로좌표)
	short int dir; //방향(0 ~ 7) 시계방향으로 구현 계획
}Coordinate; //좌표값 구조체

typedef struct
{
	int vert; //수평값
	int horiz; //수직값
}offsets; //방향 구조체

static const int STACK_SIZE = 100; //스택의 크기(상수값)
static int top; //스택의 topIndex
static Coordinate stack[STACK_SIZE]; //STACK_SIZE 크기 만큼 구조체 배열 생성

class Stack
{
public:
	/*스택 생성하는 생성자*/
	Stack()
	{
		top = -1;
	}

	BOOL pushData(int, int, int);
	Coordinate popData();
	BOOL isFull();
	BOOL isEmpty();
	void display();
	void makeDir(offsets move[]);
	void findRoute(int[14][17], int[14][17]);
	void sMark(int[14][17]);
};

