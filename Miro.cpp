#include "Miro.h"

/*
-
Function name : isEmpty = ���� ������� �˻�
Parameters : ����
Returns : TRUE(����� ��) / FALSE(�����Ͱ� ���� ��)
*/
BOOL Stack::isEmpty()
{
	if (top == -1)
		return TRUE;
	else
		return FALSE;
}

/*
-
Function name : isFull - ���� �� ���ִ��� �˻�
Parameters : ����
Returns : TRUE(�� á�� ���) / FALSE(�� ���� ���� ���)
*/
BOOL Stack::isFull()
{
	if (top == STACK_SIZE - 1)
		return TRUE;
	else
		return FALSE;
}

/*
-
Function name : pushData - ���ÿ� ������ �Է��ϱ�
Parameters : int�� row, col, dir(��, ��, ����) ������
Returns : TRUE(�����Ͱ� ���ÿ� ���� ���) / FALSE(�����Ͱ� ���ÿ� ���� �ʾ��� ���)
*/
BOOL Stack::pushData(int row, int col, int dir)
{
	if (isFull()) //���� �� á�� ��쿡 ������ ���� �� ���� ������ ���� ��ȯ
	{
		return FALSE;
	}
	else // ���� �� ���� �ʾ� ������ ���� �� �����Ƿ� stack�� ������ ���� �� �� ��ȯ
	{
		++top;
		stack[top].row = row;
		stack[top].col = col;
		stack[top].dir = dir;
		return TRUE;
	}
}

/*
-
Function name : popData - ���ÿ� �ִ� ������ ������
Parameters : ����
Returns : Coordinate ����ü
*/
Coordinate Stack::popData()
{
	if (isEmpty()) // ���ÿ� �����Ͱ� ������ pop�� �� �����Ƿ� ���α׷� ����
	{
		exit(1);
	}
	else
	{
		return stack[top--]; // ���ÿ� �����Ͱ� �����Ƿ� pop�� �� stack �ʱ�ȭ
	}
}

/*
-
Function name : display - ���ÿ� �ִ� ������ ���
Parameters : ����
Returns : ����
*/
void Stack::display()
{
	int temp; //topIndex�� ���� ���� ����

	if (isEmpty())
	{
		cout << "Stack Empty" << "\n";
	}
	else
	{
		temp = top;
		cout << " PATH " << "\n";
		cout << " ROW" << "   COL   " << "\n";
		for (int i = 0; i < top; i++)
		{
			cout << "   " << stack[i].row << "   " << stack[i].col << "\n";
		}
		cout << "\n";
	}
}

/*
-
Function name : makeDir - ���� ����
Parameters : offsets move[] -> offsets ����ü�� move �迭
Returns : ����
*/
void Stack::makeDir(offsets move[])
{
	move[0].vert = -1, move[0].horiz = 0; // ���� N
	move[1].vert = -1, move[1].horiz = 1; //�ϵ��� NE
	move[2].vert = 0, move[2].horiz = 1; //�� E
	move[3].vert = 1, move[3].horiz = 1; //���� SE
	move[4].vert = 1, move[4].horiz = 0; //�� S 
	move[5].vert = 1, move[5].horiz = -1; //���� SW
	move[6].vert = 0, move[6].horiz = -1; //�� W
	move[7].vert = -1, move[7].horiz = 01; //�ϼ� NW
}

/*
-
Function name : findRoute - �̷�ã�� �˰���
Parameters : int maze[14][17], int mark[14][17] - maze�迭�� mark�迭
Returns : ����
*/
void Stack::findRoute(int maze[14][17], int mark[14][17])
{
	int row, col, nRow, nCol, dir; //�� ã�� �ʿ��� ���� ����
	bool found = false; //�ⱸ ã���� �� ǥ���� ����

	Coordinate pos; //���� ��ġ ������ ����ü ����
	offsets move[8]; //���� ������ ����ü ����

	makeDir(move); //���� ����

	pushData(1, 1, 2); // ���� ��ǥ���� (1, 1) default dir���� ����(E)
	mark[1][1] = 1; // ���� ��ǥ�� mark

	while (top > -1 && !found) // ���� ����ְų� �ⱸ ã�� ������ ����
	{
		pos = popData(); //pos������ ���� ���ÿ� �ִ� ������ ���� �� ��� ���� Ž�� / �� �� �ִ� �� ������ ���� ��ġ pop�ϰ� ���� ��ġ�� ���ư���
		row = pos.row; //pos������ ���� ����Ǿ� �ִ� row�� ����
		col = pos.col; //pos������ ���� ����Ǿ� �ִ� col�� ����
		dir = pos.dir; //pos������ ���� ����Ǿ� �ִ� dir�� ����

		while (dir < 8 && !found) //��� ���� Ž���ϱ� ������, �ⱸ ã�� ������ ����
		{
			nRow = row + move[dir].vert; //���� �࿡�� move����ŭ �̵�
			nCol = col + move[dir].horiz; //���� ������ move����ŭ �̵�
			
			if (nRow == 12 && nCol == 15)
			{
				pushData(row, col, dir); //�ٷ� �� row, col, dir�� ����
				pushData(nRow, nCol, dir); //�ⱸ�� ����
				mark[12][15] = 1; //�ⱸ�� mark
				found = true; //�ⱸ�� ã���� ǥ��
			}
			else if (maze[nRow][nCol] != 1 && mark[nRow][nCol] != 1) //�̵��� ���̰ų� ���� �� �ƴϸ�
			{
				mark[nRow][nCol] = 1; //ó�� ������ �� ǥ��
				pos.row = row;
				pos.col = col;
				pos.dir = dir;
				pushData(pos.row, pos.col, pos.dir); //�̷� Ż�� ��� push

				row = nRow; //���� ������ �ʱ�ȭ
				col = nCol; //���� ���� �ʱ�ȭ
				dir = 0; //���Ⱚ �ʱ�ȭ
			}
			else //���� �����ų�, �̹� ��������
			{
				dir++; //���Ⱚ ����
			}
		}
	}
}


void Stack::sMark(int mark[14][17])
{
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			cout << mark[i][j] << ' ';
		}
		cout << "\n";
	}
}