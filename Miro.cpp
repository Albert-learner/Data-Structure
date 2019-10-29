#include "Miro.h"

/*
-
Function name : isEmpty = 스택 비었는지 검사
Parameters : 없음
Returns : TRUE(비었을 때) / FALSE(데이터가 있을 시)
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
Function name : isFull - 스택 꽉 차있는지 검사
Parameters : 없음
Returns : TRUE(꽉 찼을 경우) / FALSE(꽉 차지 않을 경우)
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
Function name : pushData - 스택에 데이터 입력하기
Parameters : int값 row, col, dir(행, 열, 방향) 데이터
Returns : TRUE(데이터가 스택에 들어갔을 경우) / FALSE(데이터가 스택에 들어가지 않았을 경우)
*/
BOOL Stack::pushData(int row, int col, int dir)
{
	if (isFull()) //스택 꽉 찼을 경우에 데이터 넣을 수 없기 때문에 거짓 반환
	{
		return FALSE;
	}
	else // 스택 꽉 차지 않아 데이터 넣을 수 있으므로 stack에 데이터 넣을 수 참 반환
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
Function name : popData - 스택에 있는 데이터 꺼내기
Parameters : 없음
Returns : Coordinate 구조체
*/
Coordinate Stack::popData()
{
	if (isEmpty()) // 스택에 데이터가 없으면 pop할 수 없으므로 프로그램 종료
	{
		exit(1);
	}
	else
	{
		return stack[top--]; // 스택에 데이터가 있으므로 pop한 후 stack 초기화
	}
}

/*
-
Function name : display - 스택에 있는 데이터 출력
Parameters : 없음
Returns : 없음
*/
void Stack::display()
{
	int temp; //topIndex값 복사 위한 변수

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
Function name : makeDir - 방향 설정
Parameters : offsets move[] -> offsets 구조체의 move 배열
Returns : 없음
*/
void Stack::makeDir(offsets move[])
{
	move[0].vert = -1, move[0].horiz = 0; // 북쪽 N
	move[1].vert = -1, move[1].horiz = 1; //북동쪽 NE
	move[2].vert = 0, move[2].horiz = 1; //동 E
	move[3].vert = 1, move[3].horiz = 1; //남동 SE
	move[4].vert = 1, move[4].horiz = 0; //남 S 
	move[5].vert = 1, move[5].horiz = -1; //남서 SW
	move[6].vert = 0, move[6].horiz = -1; //서 W
	move[7].vert = -1, move[7].horiz = 01; //북서 NW
}

/*
-
Function name : findRoute - 미로찾기 알고리즘
Parameters : int maze[14][17], int mark[14][17] - maze배열과 mark배열
Returns : 없음
*/
void Stack::findRoute(int maze[14][17], int mark[14][17])
{
	int row, col, nRow, nCol, dir; //길 찾기 필요한 변수 선언
	bool found = false; //출구 찾았을 때 표시할 변수

	Coordinate pos; //현재 위치 저장할 구조체 변수
	offsets move[8]; //방향 저장할 구조체 변수

	makeDir(move); //방향 설정

	pushData(1, 1, 2); // 시작 좌표값은 (1, 1) default dir값은 동쪽(E)
	mark[1][1] = 1; // 시작 좌표값 mark

	while (top > -1 && !found) // 스택 비어있거나 출구 찾을 때까지 실행
	{
		pos = popData(); //pos변수에 현재 스택에 있는 데이터 저장 후 모든 방향 탐색 / 갈 수 있는 길 없으면 현재 위치 pop하고 이전 위치로 돌아가기
		row = pos.row; //pos변수에 현재 저장되어 있는 row값 저장
		col = pos.col; //pos변수에 현재 저장되어 있는 col값 저장
		dir = pos.dir; //pos변수에 현재 저장되어 있는 dir값 저장

		while (dir < 8 && !found) //모든 방향 탐색하기 전까지, 출구 찾기 전까지 실행
		{
			nRow = row + move[dir].vert; //현재 행에서 move값만큼 이동
			nCol = col + move[dir].horiz; //현재 열에서 move값만큼 이동
			
			if (nRow == 12 && nCol == 15)
			{
				pushData(row, col, dir); //바로 전 row, col, dir값 저장
				pushData(nRow, nCol, dir); //출구값 저장
				mark[12][15] = 1; //출구값 mark
				found = true; //출구값 찾음을 표시
			}
			else if (maze[nRow][nCol] != 1 && mark[nRow][nCol] != 1) //이동한 길이거나 막힌 길 아니면
			{
				mark[nRow][nCol] = 1; //처음 도달한 곳 표시
				pos.row = row;
				pos.col = col;
				pos.dir = dir;
				pushData(pos.row, pos.col, pos.dir); //미로 탈출 경로 push

				row = nRow; //현재 행으로 초기화
				col = nCol; //현재 열로 초기화
				dir = 0; //방향값 초기화
			}
			else //길이 막히거나, 이미 지났으면
			{
				dir++; //방향값 변경
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