#include <iostream>
#include <fstream>
#define MAX_COL 9

using namespace std;

typedef struct {
	int row;
	int col;
	int value;
}shape;



void fast_transpose(shape a[], shape b[])
{
	int row_terms[MAX_COL], starting_pos[MAX_COL];
	int i, j;
	int num_col = a[0].col;
	int num_terms = a[0].value;

	b[0].row = num_col;
	b[0].col = a[0].row;
	b[0].value = num_terms;

	if (num_terms > 0)  // 0¾Æ ¾Æ´Ò¶§
	{
		for (i = 0; i < num_col; i++)
			row_terms[i] = 0;
		for (i = 1; i <= num_terms; i++)
			row_terms[a[i].col]++;

		starting_pos[0] = 1;
		for (i = 1; i < num_col; i++)
			starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

		for (i = 1; i <= num_terms; i++)
		{
			j = starting_pos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}


int main(void)
{
	ifstream fin;
	fin.open("lab2-1.txt");
	shape sha[9];
	shape trans[9];

	for (int i = 0;i<9;i++)
	{
		fin >> sha[i].row >> sha[i].col >> sha[i].value;
		cout << sha[i].row << ' ' << sha[i].col << ' ' << sha[i].value << '\n';
	}
	
	fast_transpose(sha, trans);
	
	for (int j = 0; j < 9; j++)
	{
		cout << sha[j].row << ' ' << sha[j].col << ' ' << sha[j].value << '\n';
	}

	return 0;
}