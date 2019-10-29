#include <iostream>
#include <fstream>
using namespace std;
//값이 8개이므로 메모리 오류 방지를 위해 좀 더 큰 9로 설정합니다.
#define MAX_COL 9

/*
행, 열, 값(0이 아닌 값)들을 갖는 shape 구조체 생성합니다.
*/
typedef struct
{
	int row;
	int col;
	int value;
}shape;

/*
shape 구조체 배열 a를 shape 구조체 배열 b로 fast_transpose 알고리즘을 이용하여 구현합니다.
구조체 배열 a와 구조체 배열 b를 받아 a 행렬을 전치시켜 b행렬에 저장합니다.
6*6행렬에서 0이 아닌 값 8개를 파일에서 가져옵니다.
행과 열을 전치하기 위해 열을 기준으로 값을 비교해서, 작은 값 순서대로 개수에 맞춰 starting_pos배열에 추가시켜줍니다.
각 row_terms의 시작점으로 구해서 a 구조체 배열을 b구조체 배열로 옮깁니다.
*/
void fast_transpose(shape a[], shape b[])
{

	int row_terms[MAX_COL], starting_pos[MAX_COL];
	int i, j, num_col = a[0].col, num_terms = a[0].value;

	b[0].row = num_col;
	b[0].col = a[0].row;
	b[0].value = num_terms;

	//0이 아닌 행렬
	if (num_terms > 0)
	{
		for (i = 0; i < num_col; i++)
		{
			row_terms[i] = 0;
		}
		//각 row_terms 위한 값
		for (i = 1; i <= num_terms; i++)
		{
			row_terms[a[i].col]++;
		}

		//각 row_terms 시작점 구함
		starting_pos[0] = 1;
		for (i = 1; i < num_col; i++)
		{
			starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
 		}
		//a구조체 배열을 b구조체 배열로 옮김
		for (i = 1; i <= num_terms; i++)
		{
			j = starting_pos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}

int main()
{
	ifstream fin;
	fin.open("lab2-1.txt");
	shape sha[9];
	shape trans[9];

	/*
	파일 입출력을 통해 행, 열, 0이 아닌 값을 받아옵니다.
	*/
	for (int i = 0; i < 9; i++)
	{
		fin >> sha[i].row >> sha[i].col >> sha[i].value;
		cout << sha[i].row << ' ' << sha[i].col << ' ' << sha[i].value << "\n";
	}
	
	//fast_transpose알고리즘을 실행하여 sha 구조체 배열을 전치시켜 trans 구조체 배열에 저장합니다.
	fast_transpose(sha, trans);
	cout << endl;

	//전치시킨 trans 구조체 배열의 행, 열, 값을 출력합니다.
	for (int j = 0; j < 9; j++)
	{
		cout << trans[j].row << ' ' << trans[j].col << ' ' << trans[j].value << "\n";
	}
	return 0;
}