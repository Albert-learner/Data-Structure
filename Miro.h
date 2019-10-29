#pragma once
#include <iostream>
using namespace std;

enum BOOL{FALSE, TRUE};

typedef struct
{
	short int row; //��(������ǥ)
	short int col; //��(������ǥ)
	short int dir; //����(0 ~ 7) �ð�������� ���� ��ȹ
}Coordinate; //��ǥ�� ����ü

typedef struct
{
	int vert; //����
	int horiz; //������
}offsets; //���� ����ü

static const int STACK_SIZE = 100; //������ ũ��(�����)
static int top; //������ topIndex
static Coordinate stack[STACK_SIZE]; //STACK_SIZE ũ�� ��ŭ ����ü �迭 ����

class Stack
{
public:
	/*���� �����ϴ� ������*/
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

